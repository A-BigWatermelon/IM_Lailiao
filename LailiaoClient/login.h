#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtNetwork>
#include <QtGui>
#include <QTimer>
#include "constant.h"
#include "client.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;
    Client *client;
    quint8 loginResult;//µÇÂ¼×´Ì¬½á¹û
    QTimer *timer;
    int timerID;
    QTcpSocket *tcpSocket;//Ì×½Ó×Ö
    quint16 tcpPort;//¶Ë¿ÚºÅ
    quint16 nextBlockSize;
    QHostAddress hostAddress;
    QHostInfo info;
    QHostAddress ipv4;
    QString localHostName;
    QString nickName;//êÇ³Æ
    QString qq;//ºÅÂë
    QString pwd;//ÃÜÂë
private slots:
    void connectToServer();
    void sendOnlineSlot();
    void getUserInfo();
    //void connectionClosedByServer();
    void error();
    void toNextFrame();
    void receiveLoginResult();
};

#endif // LOGIN_H
