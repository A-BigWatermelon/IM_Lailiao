#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QtNetwork>
#include "constant.h"

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QString ip, QString qq, QString name);
    ~Search();
    quint16 tcpPort;
    quint16 clientPort;
    quint16 nextBlockSize;
    quint8 loginResult;
    QHostAddress hostAddress;
    QHostAddress address;
    QTcpSocket *tcpSocket;
    QTcpSocket *clientSocket;
    //QUdpSocket *udpSocket;

private slots:
    void connectSlot();
    void connectSlot1();
    void sendAddQuerySlot();
    void displayError(QAbstractSocket::SocketError);
    void receiveAddResult();
    void sendFriendRequest();
    void getFriendRequest();
private:
    Ui::Search *ui;
    QString qq_s;   // self
    QString qq_t;   // other
    QString target_ip;
    QString source_ip;
    QString nickName;
    QString qq;

signals:
    void newFriend(QString, QString, QString);

};

#endif // SEARCH_H
