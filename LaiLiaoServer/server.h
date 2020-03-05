#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtNetwork>
#include "clientsocket.h"
#include "constant.h"


namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private slots:
    void newConnectionSlot();
    void addToList(QStringList);
    void removeFromList(QStringList);

    void sendAddFriendResult(QStringList);


private:
    Ui::Server *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QUdpSocket *udpSocket;
    quint16 tcpPort;
    quint16 udpPort;
    quint16 nextBlockSize;

    //QStringList online_list_ip;
    QDataStream in;

    virtual void closeEvent(QCloseEvent*);

signals:
    void addResultInform(QString);
};

#endif // SERVER_H
