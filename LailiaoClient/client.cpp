#include "client.h"
#include "ui_client.h"
#include <QSound>
#include <QMessageBox>
#include <QMenu>

Client::Client(QString qq, QString nickName, QString ipv4) :
    ui(new Ui::Client)
{
   // QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    ui->setupUi(this);
    this->setWindowTitle(tr("����"));
    ui->nameLabel->setText(nickName+"("+qq+")");
    ui->comboBox->setCurrentIndex(0);
    ui->toolButton_tx->setIcon(QIcon(":/icons/icon/icq_online.jpg"));

    firm_list.clear();
    id_list.clear();
    chat_list.clear();

    this->nickName = nickName;
    this->ipv4 = ipv4;
    this->qq = qq;
    f_qq="";
    f_name="";
    search = new Search(ipv4, qq, nickName);

    //����������趨
    tcpPort = 60001;
    udpPort = 44444;

    //address = QHostAddress::LocalHost;
    address=DOMAIN_IP;
    clientSocket = new QTcpSocket(this);
    serverSocket = new QTcpSocket(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(udpPort, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 54545);
    nextBlockSize = 0;

    clientSocket->abort();
    clientSocket->connectToHost(address, tcpPort);

    //���Լ����Ϊ���ѣ���ֹ�Լ�����Լ�
    addNewFriendToList(ipv4, qq, nickName);
    //////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////
    //��ʱ��

    connect(this, SIGNAL(toQuit()), this, SLOT(sendOffLineSlot()));
    connect(ui->searchBtn, SIGNAL(clicked()), this, SLOT(searchFormSlot()));

    //�źźͲ�
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
            this, SLOT(showChatForm(QTreeWidgetItem*, int)));
    //connect(ui->treeWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showMenu()));
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readMessageSlot()));
    connect(clientSocket, SIGNAL(connected()), this, SLOT(timerToCheckConnection()));
}

Client::~Client()
{
    delete ui;
}


void Client::closeEvent(QCloseEvent *event)
{
    qDebug()<<"I have closed";
    emit toQuit();
    sendOffLineSlot();
    event->accept();
    qApp->quit();
}
//����ȥ�����Ƿ�����
void Client::timerToCheckConnection()
{
    timer = new QTimer();
    timer->start(3 * 1000);
    timerID = timer->timerId();
    connect(timer, SIGNAL(timeout()), this, SLOT(checkConnectionStateSLot()));
}

void Client::newConnectionSlot()
{
    serverSocket = server->nextPendingConnection();
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(readTCPMessageSlot()));
}

void Client::readTCPMessageSlot()
{
    nextBlockSize=0;
     //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QDataStream in(serverSocket);
    in.setVersion(QDataStream::Qt_5_5);

    if (nextBlockSize == 0) {
        if (serverSocket->bytesAvailable() < sizeof(quint16)) return;
        in >> nextBlockSize;
    }
    if (serverSocket->bytesAvailable() < nextBlockSize) return;

    quint8 type;
    in >> type;
    qDebug() << "tcp type = " << type;


    ////////////////////////////ZHELI ///////////////////////////
//    QByteArray block;
//    QDataStream out(&block, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_5_5);

//    out << quint16(0) << quint8(ADD_FRIEND) << nickName << qq << ipv4;
//    out.device()->seek(0);
//    out << quint16(block.size() - sizeof(quint16));

//    clientSocket->write(block);
/////////////////////////////////////////////////////////////////////
    QSound sys("../sound/system.wav");

    switch (type) {
    case ADD_REQUEST:
        sys.play();
        in >> ip_s >> qq_s >> nickname_s;
        if (QMessageBox::Yes == QMessageBox::question(this,
                                tr("��Ӻ�������"),
                                tr("%1 ������Ϊ���ѣ����Ƿ����?").arg(ip_s),
                                QMessageBox::Yes | QMessageBox::No,
                                QMessageBox::Yes)) {
            sendAddResult(quint8(AGREED));
            //��Ӻ���
            addNewFriendToList(ip_s, qq_s, nickname_s);
        } else {
            sendAddResult(quint8(DENIED));
        }
        break;
    default:
        break;
    }
}

void Client::readMessageSlot()
{
    QByteArray datagram;
    do {
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
    } while (udpSocket->hasPendingDatagrams());

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_5);

    int type;
    QString qq_in, name_in, message;
    QString qq_to, name_to;
    in >> type;

    QSound msg("../sound/msg.wav");
    QSound nudge("../sound/shake.wav");

    switch (type) {
    case Message:
        msg.play();
        in >> qq_in >> name_in >> qq_to >> name_to >> message;
        openRelevantChatForm(name_in, qq_in, message);
        break;
    case Nudge:

        nudge.play();
        in >> qq_in >> name_in;
        nudgeRelevantChatForm(name_in, qq_in);
        break;
    default:
        break;
    }
}
//�����촰��
void Client::openRelevantChatForm(QString name_sender, QString qq_sender, QString mes)
{
    bool nflag = false;
    int n = ui->treeWidget->topLevelItemCount();

    for (int i = 0; i < id_list.size(); i++) {
        if (id_list.at(i) == qq_sender){
            nflag = true;
            break;
        }
    }

    if (nflag == true){
        for (int i = 0; i < n; i++) {
            if (firm_list.at(i) == qq_sender) {
                chat_list.at(i)->messagefirmSlot(qq_sender, mes, name_sender);
            }
        }
    } else {
        id_list << qq_sender;
        for (int i = 0; i < n; i++) {
            if (firm_list.at(i) == qq_sender) {
                chat_list.at(i)->show();
                chat_list.at(i)->messagefirmSlot(qq_sender, mes, name_sender);
                connect(chat_list.at(i), SIGNAL(closebutton(QString)), this, SLOT(outputlist(QString)));
            }
        }
    }
}
//�𶯴���
void Client::nudgeRelevantChatForm(QString name_sender, QString qq_sender)
{
    bool nflag = false;
    int n = ui->treeWidget->topLevelItemCount();

    for (int i = 0; i < id_list.size(); i++) {
        if (id_list.at(i) == qq_sender){
            nflag = true;
            break;
        }
    }

    if (nflag == true){
        for (int i = 0; i < n; i++) {
            if (firm_list.at(i) == qq_sender) {
                chat_list.at(i)->getWindowAnimation(name_sender);
            }
        }
    } else {
        id_list << qq_sender;
        for (int i = 0; i < n; i++) {
            if (firm_list.at(i) == qq_sender) {
                chat_list.at(i)->show();
                chat_list.at(i)->getWindowAnimation(name_sender);
                connect(chat_list.at(i), SIGNAL(closebutton(QString)), this, SLOT(outputlist(QString)));
            }
        }
    }
}
//���������Ϣ
void Client::sendAddResult(quint8 res)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << quint16(0) << res << ipv4 << qq << nickName;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));

    serverSocket->write(block);
}

//�����û����ߺ��״̬��Ϣ
void Client::sendOnlineSlot()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << quint16(0) << quint8(LOG_IN) << nickName << qq << ipv4;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));

    clientSocket->write(block);
    ui->toolButton_tx->setIcon(QIcon(":/icons/icon/icq_online.jpg"));
}

//�����û����ߺ��״̬��Ϣ
void Client::sendOffLineSlot()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << quint16(0) << quint8(LOG_OUT) << qq << nickName;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));

    clientSocket->write(block);
}

//��chat���촰��
void Client::showChatForm(QTreeWidgetItem* m, int ix)
{
    if (m->childCount() == 0) return;//mark1-b,�迼������Ƿ����


    bool bflag = false;

    /*int index=m->text(0).lastIndexOf('(');
    int index2=m->text(0).lastIndexOf(')');
    QString id =m->text(0).mid(index+1,index2-index-1);*/
    QString id=m->child(0)->text(0);
    int n = ui->treeWidget->topLevelItemCount();
    if (!(id_list.isEmpty())) {
        for (int i = 0; i < id_list.size(); ++i) {
            if (id_list.at(i) == id) {
                bflag = true;
                break;
            }
        }
    }
    if (bflag == true ) {
        return;
    } else {
        id_list << id;
        for(int i = 0; i < n; ++i) {
            if (firm_list.at(i) == id) {
                chat_list.at(i)->show();
                connect(chat_list.at(i), SIGNAL(closebutton(QString)), this, SLOT(outputlist(QString)));
            }
        }
    }
}



//��Ӻ���������
void Client::searchFormSlot()
{
    Search *xsearch = this->findChild<Search *>("search");
    if (xsearch == 0) {
        search->show();
        connect(search, SIGNAL(newFriend(QString,QString,QString)),
                this, SLOT(addNewFriendToList(QString,QString,QString)));
    } else {
        return;
    }
}

//�˳�˽���������
void Client::outputlist(QString qqid)
{
    for (int i = 0; i < id_list.size(); ++i) {
        if (id_list.at(i) == qqid) {
            id_list.removeAt(i);
        }
    }
}

void Client::addNewFriendToList(QString ip, QString qq, QString name)
{
    QTreeWidget *t = ui->treeWidget;
    QTreeWidgetItem *a = new QTreeWidgetItem(t, QStringList(tr("%1(%2)").arg(name).arg(qq)));
    a->setIcon(0,QIcon(":/icons/icon/icq_online.jpg"));
    QTreeWidgetItem *aip = new QTreeWidgetItem(a, QStringList(qq));//mark1-a,�迼������Ƿ����
    createNewChatForm(ip, qq, name);
}

//˽���û�����
void Client::createNewChatForm(QString ip_t, QString qq_t, QString name_t)
{
    Chat *a;
    a = new Chat(qq, qq_t, nickName, name_t, ipv4, ip_t);
    qDebug() << "qq_t = " << qq_t;
    chat_list << a;
    firm_list << qq_t;
}

//ȷ�Ͽͻ�������״̬
void Client::checkConnectionStateSLot()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    if (clientSocket->state() == QAbstractSocket::UnconnectedState) {
        QMessageBox::critical(this, tr("����������"), tr("�޷����ӷ������������µ�¼"));
        QObject::killTimer(timerID);
        ui->comboBox->setCurrentIndex(1);
    }
}

void Client::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0) {
        if (clientSocket->state() == QTcpSocket::UnconnectedState) {
            clientSocket->abort();
            clientSocket->connectToHost(address, tcpPort);
            connect(clientSocket, SIGNAL(connected()), this, SLOT(sendOnlineSlot()));
        }
    }
    if (index == 1) {
        sendOffLineSlot();
        ui->toolButton_tx->setIcon(QIcon(":/icons/icon/icq_offline.jpg"));
    }
}

void Client::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<<"Hello";
    QTreeWidgetItem* curItem=ui->treeWidget->itemAt(pos);  //��ȡ��ǰ������Ľڵ�
        if(curItem==NULL)return;           //����������Ҽ���λ�ò���treeItem�ķ�Χ�ڣ����ڿհ�λ���һ�
        if(0==curItem->data(0,Qt::UserRole))      //data(...)���ص�data�Ѿ���֮ǰ�����ڵ�ʱ��setdata()���ú�
        {
        }
        else
        {
            QMenu *popMenu =new QMenu(this);//����һ���Ҽ������˵�
            popMenu->addAction(ui->actionAdd);
            popMenu->addAction(ui->actionDelete);//���˵������QAction   ��action��ǰ���������������
            popMenu->exec(QCursor::pos());//�����Ҽ��˵����˵�λ��Ϊ���λ��
        }
}

///////////////////////ɾ������//////////////////////////////////////////////////////////////
void Client::on_actionDelete_activated(int arg1)
{
    QTreeWidgetItem* item=ui->treeWidget->currentItem();//��õ�ǰ�ڵ�
        if(NULL==item)//û��ѡ��ڵ�
            return;
        else
        {
            if(item->parent()==NULL)
                     delete ui->treeWidget->takeTopLevelItem(ui->treeWidget->currentIndex().row());
        }
}

/////////////////////////////////��ӱ�ע///////////////////////////////////////////////////////
void Client::on_actionAdd_activated()
{
    QTreeWidgetItem* item=ui->treeWidget->currentItem();//��õ�ǰ�ڵ�
        if(NULL==item)//û��ѡ��ڵ�
            return;
        else
        {
            item->setFlags(Qt::ItemIsEditable |Qt::ItemIsEnabled);
            ui->treeWidget->editItem(item,0);
            f_name=item->text(0);
            f_qq=item->text(0).mid(item->text(0).lastIndexOf('('),item->text(0).lastIndexOf(')'));
            item->setText(0,"");
            item->setFlags(item->flags()&~(Qt::ItemIsEditable));
        }
}

