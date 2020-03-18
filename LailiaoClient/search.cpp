#include "search.h"
#include "ui_search.h"
#include <QtGui>

#include <QMessageBox>


Search::Search(QString ip, QString qq, QString name) :
    ui(new Ui::Search)
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    ui->setupUi(this);
    //qq_s = ip;
    this->source_ip = ip;
    this->qq = qq;
    this->nickName = name;

    this->setWindowTitle(QStringLiteral("ËÑË÷ºÃÓÑ"));
    ui->qqRadioButton->setEnabled(true);
    ui->qqRadioButton->setChecked(true);
    ui->sendBtn->setDefault(true);

    hostAddress = QHostAddress::LocalHost;
    //address = QHostAddress::LocalHost;
    address=DOMAIN_IP;
    clientPort = 60001;
    tcpPort = 54545;

    tcpSocket = new QTcpSocket(this);
    clientSocket=new QTcpSocket(this);


    nextBlockSize = 0;
    ui->adduserButton->setEnabled(false);
    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(connectSlot1()));
    connect(ui->adduserButton, SIGNAL(clicked()), this, SLOT(connectSlot()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendAddQuerySlot()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveAddResult()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(clientSocket,SIGNAL(connected()),this,SLOT(sendFriendRequest()));
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(getFriendRequest()));

}

Search::~Search()
{
    delete ui;
}



void Search::connectSlot1()
{
    qDebug()<<"here";
    if (ui->qqLineEdit->text().trimmed().isEmpty()) {
        QMessageBox::critical(this, QStringLiteral("Request Failure"), QStringLiteral("Please input your IP."));
    }
    clientSocket->abort();
    clientSocket->connectToHost(address,clientPort);
}
void Search::connectSlot()
{
    disconnect(clientSocket,SIGNAL(connected()),this,SLOT(sendFriendRequest()));
    disconnect(clientSocket,SIGNAL(readyRead()),this,SLOT(getFriendRequest()));
    tcpSocket->abort();
    tcpSocket->connectToHost(target_ip, tcpPort);
}
// send to server
void Search::sendFriendRequest()
{
    qq_t = ui->qqLineEdit->text();
    QByteArray sblock;
    QDataStream sout(&sblock, QIODevice::WriteOnly);
    sout.setVersion(QDataStream::Qt_5_5);
    sout << quint16(0) << quint8(ADD_FRIEND) <<qq_t;
    sout.device()->seek(0);
    sout << quint16(sblock.size() - sizeof(quint16));
    clientSocket->write(sblock);
}
void Search::getFriendRequest()
{
    QDataStream in;
     nextBlockSize=0;
    in.setDevice(clientSocket);
    in.setVersion(QDataStream::Qt_5_5);

    //nextBlockSize = 0;
    if (nextBlockSize == 0) {
        if (clientSocket->bytesAvailable() < sizeof(quint16)) return; 
    }
    in >> nextBlockSize;
    if (clientSocket->bytesAvailable() < nextBlockSize) return;
    in >> loginResult;

    if (loginResult == ADD_FRIEND_SUCCESS) {
       ui->user_id->setText(ui->qqLineEdit->text().trimmed());
        QString name;
        in>>name>>target_ip;
        ui->user_nickName->setText(name);
        ui->user_ip->setText(target_ip);
        qDebug()<<"dddddd"+target_ip;
        ui->adduserButton->setEnabled(true);
    }

    if (loginResult == ADD_FRIEND_FALSE)
    {
        qDebug()<<loginResult;
    }
   //clientSocket->abort();
}
void Search::sendAddQuerySlot()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << quint16(0) << quint8(ADD_REQUEST) //<< nickName
        << source_ip << qq << nickName;

    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    tcpSocket->write(block);

    this->close();
}

void Search::receiveAddResult()
{
    QDataStream in;
     nextBlockSize=0;
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_5);

    //nextBlockSize = 0;
    if (nextBlockSize == 0) {
        if (tcpSocket->bytesAvailable() < sizeof(quint16)) return;
        in >> nextBlockSize;
    }
    if (tcpSocket->bytesAvailable() < nextBlockSize) return;

    quint8 res;
    in >> res;

    QString ip_t, qq_t, name_t;
    switch (res) {
    case AGREED:
        in >> ip_t >> qq_t >> name_t;
        QMessageBox::information(this, QStringLiteral("Hmmm..."), QStringLiteral("I'm glad to hear that %1 agreed to add you as a friend.").arg(ip_t));
        emit newFriend(ip_t, qq_t, name_t);
        break;
    case DENIED:
        in >> ip_t >> qq_t >> name_t;
        QMessageBox::information(this, QStringLiteral("Hmmm..."), QStringLiteral("I'm sorry! %1 denied your request.").arg(ip_t));
        break;
    default:
        break;
    }

    this->destroy();
}

void Search::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, tr("Warnning"),
                                     tr("The host was not found. Please check the "
                                        "host name and port settings."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, tr("Warnning"),
                                     tr("The connection was refused by the peer. "
                                        "Make sure the fortune server is running, "
                                        "and check that the host name and port "
                                        "settings are correct."));
            break;
        default:
            QMessageBox::information(this, tr("Warnning"),
                                     tr("The following error occurred: %1.")
                                     .arg(tcpSocket->errorString()));
    }
}

