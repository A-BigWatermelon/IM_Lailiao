#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //ui->qq_LineEdit->setEnabled(false);
    ui->pwd_LineEdit->setEchoMode(QLineEdit::Password);
    //ui->pwd_LineEdit->setEnabled(false);
    ui->status_label->setText("");

    ui->loginBtn->setDefault(true);

    tcpSocket = new QTcpSocket(this);
    tcpPort = 60001;

    //�л�������
    //hostAddress = QHostAddress::LocalHost;
    hostAddress = DOMAIN_IP;

    loginResult = TIME_OUT;

    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(getUserInfo()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendOnlineSlot()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveLoginResult()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));
}

Login::~Login()
{
    delete ui;
}



void Login::connectToServer()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    /*if (ui->nickname_LineEdit->text().trimmed().isEmpty()) {
        QMessageBox::critical(this, QObject::tr("��¼ʧ��"), QObject::tr("�������ǳ�"));
        ui->nickname_LineEdit->clear();
        return;
    }*/
    if (ui->qq_LineEdit->text().trimmed().isEmpty()) {
        QMessageBox::critical(this, QObject::tr("LogIN Failed"), QObject::tr("Polese Input Your Account"));
        ui->qq_LineEdit->clear();
        return;
    }
    if (ui->pwd_LineEdit->text().trimmed().isEmpty()) {
        QMessageBox::critical(this, QObject::tr("LogIN Failed"), QObject::tr("Polese Input Your Code"));
        ui->qq_LineEdit->clear();
        return;
    }
    tcpSocket->abort();
    tcpSocket->connectToHost(hostAddress, tcpPort);
    nextBlockSize = 0;
    ui->status_label->setText(QObject::tr("Linking the Sever..."));

    timer = new QTimer(this);
    timer->start(5 * 1000);
    timerID = timer->timerId();
    connect(timer, SIGNAL(timeout()), this, SLOT(toNextFrame()));//Ϊʲô��timer�������ã�
	//����toNextFrame()������ֱ��ֹͣ��ʱ��timer,Ϊʲô�����£����ú���QTimer::singleShot��
	//QTimer::singleShot( 5000,this, SLOT(toNextFrame()));
}

void Login::toNextFrame()
{
	//ע���˴���killTimer�ƺ����û��ˣ�QT�������ֶ�ʱ����QObject��timerStart����QTimer�ࣩ������滻Ϊstop
    //QObject::killTimer(timerID);
	if (timer->isActive() )
	{
		timer->stop();
	}
    tcpSocket->abort();
    switch (loginResult) {
    case LOGIN_SUCCESS:
        qDebug() << "success";
        tcpSocket->abort();
        client = new Client(qq, nickName, ipv4.toString());
        client->show();
        this->close();
        break;
    case TIME_OUT:
        tcpSocket->abort();
        QMessageBox::critical(this, QObject::tr("LogIN Failed"), QObject::tr("Link the Sever OutTime"));
        break;
    default:
        break;
    }
}

void Login::getUserInfo()
{
    //nickName = ui->nickname_LineEdit->text().trimmed();
    qq = ui->qq_LineEdit->text().trimmed();
    pwd=ui->pwd_LineEdit->text().trimmed();
    localHostName = QHostInfo::localHostName();
    info = QHostInfo::fromName(localHostName);
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol&&address != QHostAddress::Null &&
                address != QHostAddress::LocalHost) {
            ipv4 = address.toString();
            qDebug()<<ipv4;
        }
    }
}

void Login::sendOnlineSlot()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << quint16(0) << quint8(LOG_IN) << nickName << qq<<pwd
        << ipv4.toString();
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}

void Login::error()
{
    ui->status_label->setText(tcpSocket->errorString());
    tcpSocket->close();
}

void Login::receiveLoginResult()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QDataStream in;
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_5);

    //nextBlockSize = 0;
    if (nextBlockSize == 0) {
        if (tcpSocket->bytesAvailable() < sizeof(quint16)) return;
        in >> nextBlockSize;
    }
    if (tcpSocket->bytesAvailable() < nextBlockSize) return;
    in >> loginResult;

    if (loginResult == LOGIN_SUCCESS) {
        in>>nickName;
    }

    if (loginResult == LOGIN_FALSE)
    {
        ui->status_label->setText(QObject::tr("your Account or Code is wrong"));
        return;
    }
    toNextFrame();
}
