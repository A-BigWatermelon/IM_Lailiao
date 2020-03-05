#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QtGui>
#include <QtNetwork>
#include <QPixmap>
#include <QFileInfo>
#include "transfer.h"
#include "download.h"

namespace Ui {
class Chat;
}

enum MessageType{Message,NewParticipant,ParticipantLeft,FileName,Refuse,Nudge};
//枚举变量标志信息的类型，分别为消息，新用户加入，和用户退出

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chat(QString, QString, QString, QString, QString, QString);
    //Chat() {}
    ~Chat();
    void windowAnimation();
    void getWindowAnimation(QString name_sender);
    bool saveFile(const QString &fileName);

private:
    Ui::Chat *ui;

    QString qq_s;
    QString qq_t;
    QString name_s;
    QString name_t;
    QString ip_s;
    QString ip_t;

    quint16 tcpport;
    quint16 udpport;
    quint16 p2pport;
    QTcpServer *server;
    QTcpSocket *clientsocket;
    QTcpSocket *p2psocket;
    QUdpSocket *udpsocket;
    //QUdpSocket *sendsocket;
    QHostAddress address;

    QPixmap screenshot;

    Transfer *tserver;
    QString fileName;

protected:
    void sendMessage(MessageType type,QString serverAddress="");
    void closeEvent(QCloseEvent *event);

public:
    void messagefirmSlot(QString qq_in, QString message, QString name_in);

private slots:
    void sendMessageSlot();
    void receiveMessageSlot();

    void setFontxx();
    void setFontColor();
    //void windowShot();
    void showfaceSlot(QString);

    void currentFormatChanged(const QTextCharFormat&);
    void sentFileName(QString);
    void hasPendingFile(QString userName,QString serverAddress,
                        QString clientAddress,QString fileName);

    void on_toolButton_Bold_clicked(bool checked);

    void on_toolButton_Italic_clicked(bool checked);

    void on_toolButton_Underline_clicked(bool checked);

    void on_toolButton_SendFile_clicked();

    void on_toolButton_ScreenShot_clicked();

    void on_toolButton_Save_clicked();


    void on_toolButton_Nudge_clicked();

signals:
    void closebutton(QString);

};

#endif // CHAT_H
