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
    quint8 loginResult;//��¼״̬���
    QTimer *timer;
    int timerID;
    QTcpSocket *tcpSocket;//�׽���
    quint16 tcpPort;//�˿ں�
    quint16 nextBlockSize;
    QHostAddress hostAddress;
    QHostInfo info;
    QHostAddress ipv4;
    QString localHostName;
    QString nickName;//�ǳ�
    QString qq;//����
    QString pwd;//����
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
