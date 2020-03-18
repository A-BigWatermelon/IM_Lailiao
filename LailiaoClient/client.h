#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtNetwork>
#include <QMap>
//#include <QString>
#include <QtWebKitWidgets/QWebView>
#include <QSystemTrayIcon>
#include <QTreeWidgetItem>
#include "constant.h"
#include "chat.h"
#include "search.h"

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Chat *chat;
    Search *search;

    QTimer *timer;
    int timerID;

    int userid;
    int id;
    int w;
    QString sname;
    QString kname;

    QString ip_s;
    QString nickname_s;
    QString qq_s;

    QString ip_t;
    QString nickname_t;
    QString qq_t;

    QList<Chat *> chat_list;  //聊天窗口列表
    QList<QString> firm_list;
    QStringList id_list;

	//mark2 设计一个树节点和qq号的映射是解决树节点不能setitemdata的问题
	//只后双击好友（树节点，会从该map中找到树节点对应的qq号）
	//此外该map应该接受数据库的好友信息，用来初始化好友列表
	QMap<QTreeWidgetItem*,QString> mapFriendQQ;

public:
    explicit Client(QString qq, QString nickName, QString ipv4);
    ~Client();
    //void windowAnimation(Chat *wnd);


private slots:

    void newConnectionSlot();
    void sendOnlineSlot();
    void sendOffLineSlot();
    void checkConnectionStateSLot();
    void timerToCheckConnection();

    void searchFormSlot();
    void showChatForm(QTreeWidgetItem*, int);

    void readTCPMessageSlot();
    void readMessageSlot();

    void addNewFriendToList(QString, QString, QString);
    void outputlist(QString);


    void on_comboBox_currentIndexChanged(int index);

    void on_treeWidget_customContextMenuRequested(const QPoint &pos);
    void on_actionDelete_activated(int arg1);

    void on_actionAdd_activated();


private:
    Ui::Client *ui;

    QString nickName;
    QString ipv4;
    QString qq;
    QString f_qq;
    QString f_name;
    quint16 tcpPort;
    quint16 udpPort;
    QTcpServer *server;
    QTcpSocket *clientSocket;
    QTcpSocket *serverSocket;
    QUdpSocket *udpSocket;
    QHostAddress address;
    QHostAddress ipAddresses;

    quint16 nextBlockSize;
    QSystemTrayIcon *trayIcon;

private:
    void closeEvent(QCloseEvent *event);
    void sendAddResult(quint8);
    void createNewChatForm(QString, QString, QString);
    void openRelevantChatForm(QString name_sender, QString qq_sender, QString mes);
    void nudgeRelevantChatForm(QString name_sender, QString qq_sender);
signals:
    void toQuit();

};

#endif // CLIENT_H
