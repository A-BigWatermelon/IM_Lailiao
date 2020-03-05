
#include "clientsocket.h"
#include "ui_clientsocket.h"


ClientSocket::ClientSocket(QWidget *parent, QTcpServer *tcpServer, QUdpSocket *udpSocket) :
    QWidget(parent), ui(new Ui::ClientSocket)
{
    ui->setupUi(this);

    tcpPort = 54545;
    udpPort = 43434;

    this->udpSocket = udpSocket;
    this->tcpServer = tcpServer;
    tcpSocket = new QTcpSocket(this);
    tcpSocket = tcpServer->nextPendingConnection();

    //qDebug() << "new client!";
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
    nextBlockSize = 0;
}

ClientSocket::~ClientSocket()
{
    delete ui;
}

void ClientSocket::readClient()
{
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_5);

    if (nextBlockSize == 0) {
        if (tcpSocket->bytesAvailable() < sizeof(quint16)) return;
        in >> nextBlockSize;
    }
    if (tcpSocket->bytesAvailable() < nextBlockSize) return;

    quint8 type;
    in >> type;
    qDebug() << "type = " << type;

    switch (type) {
    case LOG_IN:
        log_in();
        break;
    case LOG_OUT:
        log_out();
        break;
    case ADD_REQUEST:
        add_friend_query();
        break;
    case ADD_FRIEND:
        qDebug()<<"I win";
        send_friend_ip();
        break;
    default:
        break;
    }
}
void ClientSocket::send_friend_ip()
{
     in>>qq;
     QSqlQuery query;
     query.exec("SELECT * FROM tbl_userinfo WHERE id='"+qq+"'");
     QByteArray block;
     QDataStream out(&block, QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_5_5);
     //tcpSocket->abort();
     if(query.next())
     {
         out << (quint16)0 << (quint8)ADD_FRIEND_SUCCESS<<query.value(1).toString().trimmed()
             <<query.value(3).toString().trimmed();
         out.device()->seek(0);
         out << (quint16)(block.size() - sizeof(quint16));
         tcpSocket->write(block);

         qDebug()<<query.value(3).toString().trimmed();
     }
     else
     {
         out << (quint16)0 << (quint8)ADD_FRIEND_FALSE;
         out.device()->seek(0);
         out << (quint16)(block.size() - sizeof(quint16));
         tcpSocket->write(block);
     }
}
void ClientSocket::log_in()
{
    in >> nickName >> qq >>pwd>> ipv4;
    QSqlQuery query;
    query.exec("SELECT * FROM tbl_userinfo WHERE id='"+qq+"' AND password='"+pwd+"'");

    if(query.next())
    {
    // send login result back
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    //out.setDevice(tcpSocket);

//////////////////////////添加好友列表////////////////////////////////////
    nickName=query.value(1).toString().trimmed();
    // login success
    out << (quint16)0 << (quint8)LOGIN_SUCCESS<<nickName;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);

///////////////////////////////////////////////////////////////////////
    query.clear();

    query.exec("UPDATE tbl_userinfo SET ip='"+ipv4+"' WHERE id='"+qq+"'");
    // emit the signal
    fields.clear();
    fields << ipv4
           << qq
           << nickName
           << QDateTime::currentDateTimeUtc().toString();
    emit userGetOnLineInform(fields);

    broadcast_inform(USER_ONLINE, qq, nickName);
    }
    else
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_5);

        // login false
        out << (quint16)0 << (quint8)LOGIN_FALSE;
        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));
        tcpSocket->write(block);
    }
}

void ClientSocket::log_out()
{
    qDebug() << "logout!!";
    in >> qq >> nickName;

    fields.clear();
    fields << qq << nickName;
    emit userGetOffLineInform(fields);

    broadcast_inform(USER_NOT_ONLINE, qq, nickName);
}

void ClientSocket::broadcast_inform(int xtype, QString xqq, QString xname)
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << xtype << xqq << xname;// << qq_t << name_t;

    //qDebug() << "ip_t = " << ip_t;
    udpSocket->writeDatagram(datagram, QHostAddress::Broadcast, udpPort);
}

void ClientSocket::add_friend_query()
{
    in >> qq_s >> qq_t;

    fields.clear();
    fields << qq_s << qq_t;
    qDebug() << qq_s << qq_t;
}

void ClientSocket::sendQueryResult(QString ip)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    //out.setDevice(tcpSocket);

    qDebug() << "online ip = " << ip;
    out << quint16(0);
    if (ip.isEmpty()) {
        out << (quint8)USER_NOT_ONLINE;
    } else {
        out << (quint8)USER_ONLINE << qq_t << ip;
    }
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}
