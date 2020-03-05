#include "server.h"
#include "ui_server.h"
#include <QtGui>

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->online_cnt_label->setNum(0);
    ui->online_list_TableWidget->setRowCount(1);
    ui->online_list_TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
    ui->online_list_TableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    ui->online_list_TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
    ui->online_list_TableWidget->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白

    ui->online_list_TableWidget->setColumnWidth(0, 110);
    ui->online_list_TableWidget->setColumnWidth(1, 110);
    ui->online_list_TableWidget->setColumnWidth(2, 110);
    ui->online_list_TableWidget->setColumnWidth(3, 153);

    tcpServer = new QTcpServer(this);
    udpSocket = new QUdpSocket(this);
    tcpPort = 60001;
    nextBlockSize = 0;

    udpPort = 43434;

    if (!tcpServer->listen(QHostAddress::Any, tcpPort)) {
        qDebug() << "Failed to bind to port";
        return;
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
}

Server::~Server()
{
    delete ui;
}

void Server::closeEvent(QCloseEvent *)
{
    qApp->quit();
}

void Server::newConnectionSlot()
{
    ClientSocket *socket = new ClientSocket(this, tcpServer, udpSocket);
    connect(socket, SIGNAL(userGetOnLineInform(QStringList)),
            this, SLOT(addToList(QStringList)));
    connect(socket, SIGNAL(userGetOffLineInform(QStringList)),
            this, SLOT(removeFromList(QStringList)));
    connect(socket, SIGNAL(userAddFriendRequest(QStringList)),
            this, SLOT(sendAddFriendResult(QStringList)));
}

void Server::addToList(QStringList fields)
{
    int row = ui->online_list_TableWidget->rowCount();
    ui->online_list_TableWidget->setRowCount(row + 1);
    for (int i = 0; i < fields.count(); ++i) {
        ui->online_list_TableWidget->setItem(row - 1, i,
                                             new QTableWidgetItem(fields[i]));
    }
    int online_cnt = ui->online_cnt_label->text().toInt();
    ui->online_cnt_label->setNum(online_cnt + 1);

    ui->statusLabel->setText(tr("%1 刚刚登录客户端.").arg(fields[2]));
}

void Server::removeFromList(QStringList fields)
{
    QTableWidget *t = ui->online_list_TableWidget;
    qDebug() << "in it!!!!!!!!";
    for (int i = 0; i < t->rowCount() - 1; ++i) {
        if (t->item(i, 1)->text() == fields[0]) {
            t->setItem(i, 1, new QTableWidgetItem("off"));
            break;
        }
    }
    int online_cnt = ui->online_cnt_label->text().toInt();
    ui->online_cnt_label->setNum(online_cnt - 1);

    ui->statusLabel->setText(tr("%1 刚刚下线").arg(fields[1]));
}

void Server::sendAddFriendResult(QStringList fields)
{
    bool target_online = false;
    QString target_address;
    target_address.clear();

    QTableWidget *t = ui->online_list_TableWidget;
    for (int i = 0; i < t->rowCount() - 1; ++i) {
        if (t->item(i, 1)->text() == fields[1]) {
            target_online = true;
            target_address = t->item(i, 0)->text();
        }
    }

    qDebug() << "isTargetOnline = " << target_online << target_address;
    emit addResultInform(target_address);
}


