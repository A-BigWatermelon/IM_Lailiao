#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
#include "constant.h"
#include <QSqlQuery>

namespace Ui {
class ClientSocket;
}

class ClientSocket : public QWidget
{
    Q_OBJECT

public:
    explicit ClientSocket(QWidget *parent, QTcpServer*, QUdpSocket*);
    ~ClientSocket();

private slots:
    void readClient();
    void sendQueryResult(QString);

private:
    void log_in();
    void log_out();
    void add_friend_query();
    void send_friend_ip();
    void broadcast_inform(int xtype, QString xqq, QString xname);

private:
    Ui::ClientSocket *ui;

    quint16 udpPort;
    quint16 tcpPort;
    quint16 nextBlockSize;

    QTcpSocket *tcpSocket;
    QTcpSocket *clientSocket;
    QTcpServer *tcpServer;
    QUdpSocket *udpSocket;

    QString nickName;
    QString ipv4;
    QString qq;
    QString pwd;
    QString qq_s, qq_t;
    QString senderNickname;

    QString message;
    QString clientAddress;
    QHostAddress address;

    QStringList fields;
    QDataStream in;
    QTimer *timer;
    int timerID;

signals:
    void userGetOnLineInform(QStringList);
    void userGetOffLineInform(QStringList);
    void userAddFriendRequest(QStringList);

};

#endif // CLIENTSOCKET_H
