#include "chat.h"
#include "ui_chat.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopWidget>

Chat::Chat(QString qq_s, QString qq_t,
           QString name_s, QString name_t,
           QString ip_s, QString ip_t) :
    //QMainWindow(parent),
    ui(new Ui::Chat)
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    ui->setupUi(this);
    this->qq_s = qq_s;
    this->qq_t = qq_t;

    qDebug() << "init qq_t = " << this->qq_t;
    this->name_s = name_s;
    this->name_t = name_t;
    this->ip_s = ip_s;
    this->ip_t = ip_t;

    this->setWindowTitle(QStringLiteral("与%1聊天中").arg(name_t));

    ui->sendTextEdit->setFocus();

    //网络设定
    tcpport = 60001;
    p2pport = 60008;

    //address = QHostAddress::LocalHost;

    udpport = 33333;
    clientsocket = new QTcpSocket(this);
    p2psocket = new QTcpSocket(this);

    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, p2pport);

    udpsocket = new QUdpSocket(this);
    udpsocket->bind(udpport, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    tserver = new Transfer();

    connect(tserver, SIGNAL(sendFileName(QString)),
            this, SLOT(sentFileName(QString)));

    //接收者资料
    ui->qqLabel->setText(qq_t);
    ui->nameLabel->setText(name_t);

    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(sendMessageSlot()));
    connect(udpsocket, SIGNAL(readyRead()), this, SLOT(receiveMessageSlot()));

    connect(ui->sendTextEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),
            this,SLOT(currentFormatChanged(const QTextCharFormat)));

    connect(ui->toolButton_Palette, SIGNAL(clicked()), this, SLOT(setFontColor()));
    connect(ui->toolButton_Font, SIGNAL(clicked()), this, SLOT(setFontxx()));
}

Chat::~Chat()
{
    delete ui;
}

void Chat::closeEvent(QCloseEvent *event)
{
    emit closebutton(qq_t);
    event->accept();
}


void Chat::currentFormatChanged(const QTextCharFormat &format)
{
    ui->toolButton_Bold->setChecked(format.font().bold());
    ui->toolButton_Italic->setChecked(format.font().italic());
    ui->toolButton_Underline->setChecked(format.font().underline());
}

//槽函数，设置输入字体颜色
void Chat::setFontColor()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QColor col = QColorDialog::getColor(ui->sendTextEdit->textColor(), this);
    if (!col.isValid()) return;

    ui->sendTextEdit->setTextColor(col);
    QPixmap pix(16, 16);
    pix.fill(col);
    ui->toolButton_Palette->setIcon(pix);
    this->setStatusTip(QStringLiteral("选择字体颜色"));
}

//槽函数，设置字体大小+选择字体
void Chat::setFontxx()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    if (!ok) return;
    ui->sendTextEdit->setFont(font);
    this->setStatusTip(QStringLiteral("设置字体大小"));
}

//槽函数，把图片放入Textedit内
void Chat::showfaceSlot(QString pic)
{
    ui->sendTextEdit->append("<img src='" + pic + "' />");
}

void Chat::sentFileName(QString fileName)
{
    this->fileName = fileName;
    sendMessage(FileName);
}

void Chat::sendMessage(MessageType type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    //QString localHostName = QHostInfo::localHostName();
    //QString address = ip_s;
    out << type << name_s;

    switch (type) {
    case FileName:
        out << ip_s << ip_t << fileName;
        break;

    case Refuse:
        out << serverAddress;
        break;
    default:
        break;
    }
    udpsocket->writeDatagram(data, data.length(), QHostAddress(ip_t), udpport);
}

void Chat::sendMessageSlot()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    if (ui->sendTextEdit->toPlainText().trimmed() == "") {
        QMessageBox::critical(this, QStringLiteral("Hmmm..."), QStringLiteral("请输入聊天信息"));
        return;
    }
    qDebug() << "sending...";
    QHostAddress address(ip_t);
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << Message << qq_s << name_s << qq_t << name_t;
    out << ui->sendTextEdit->toHtml();

    qDebug() << "ip_t = " << ip_t;
    udpsocket->writeDatagram(datagram, address, (quint16)44444);

    ui->receiveTextEdit->append(name_s + "  " +
                                QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"))
                                );

    ui->receiveTextEdit->append(QStringLiteral("%1\n").arg(ui->sendTextEdit->toHtml()));
    ui->sendTextEdit->clear();

}

//接受聊天信息
void Chat::messagefirmSlot(QString qq_in, QString message, QString name_in)
{
    if (qq_t == qq_in) {
        ui->receiveTextEdit->setAlignment(Qt::AlignLeft);
        ui->receiveTextEdit->append(name_in + "  " +
                                    QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"))
                                   );
        ui->receiveTextEdit->setAlignment(Qt::AlignLeft);
        ui->receiveTextEdit->append(QStringLiteral("%1\n").arg(message));
    }
}

void Chat::receiveMessageSlot()
{
    qDebug() << "receiving...";
    QByteArray datagram;
    do {
        datagram.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(datagram.data(), datagram.size());
    } while (udpsocket->hasPendingDatagrams());

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_5);

    QString userName,ipAddress,serverAddress;
    QString qq_in, name_in, message;
    QString clientAddress, fileName;

    int type;
    in >> type;
    switch (type) {

    case Message:
        in >> qq_in >> name_in >> message;
        qDebug() << "rcv qq_in = " << qq_in;
        qDebug() << "now qq_t = " << qq_t;
        if (qq_in == qq_t) {
            ui->receiveTextEdit->append(name_in + "  " +
                                        QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"))
                                       );
            ui->receiveTextEdit->append(QStringLiteral("%1\n").arg(message));
        }
        break;
    case FileName:

        in >> userName >> ipAddress;
        in >> clientAddress >> fileName;
        hasPendingFile(userName,ipAddress,clientAddress,fileName);

        break;
    case Refuse:
        {
            in >> userName;
            in >> serverAddress;
            ipAddress = ip_s;
            if (ipAddress == serverAddress)
            {
                tserver->refused();
            }
            break;
        }
    default:
        break;
    }
}

void Chat::hasPendingFile(QString userName,QString serverAddress,  //接收文件
                          QString clientAddress,QString fileName)
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QString ipAddress = ip_s;
    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this,QStringLiteral("接收文件"),
                                 QStringLiteral("来自%1(%2)的%3, 是否接受?")
                                 .arg(userName).arg(serverAddress).arg(fileName),
                                 QMessageBox::Yes,QMessageBox::No);
        if(btn == QMessageBox::Yes)
        {
            QString name = QFileDialog::getSaveFileName(0,QStringLiteral("保存文件"),fileName);
            if(!name.isEmpty())
            {
                Download *client = new Download();
                client->setFileName(name);
                client->setHostAddress(QHostAddress(serverAddress));
                client->show();
            }
        }
        else{
            sendMessage(Refuse,serverAddress);
        }
    }
}

void Chat::on_toolButton_Bold_clicked(bool checked)
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    if (checked == true) {
        ui->sendTextEdit->setFontWeight(QFont::Bold);
    } else {
        ui->sendTextEdit->setFontWeight(QFont::Normal);
    }
    this->setStatusTip(QStringLiteral("字体加粗"));
    ui->sendTextEdit->setFocus();
}

void Chat::on_toolButton_Italic_clicked(bool checked)
{
    ui->sendTextEdit->setFontItalic(checked);
    ui->sendTextEdit->setFocus();
}

void Chat::on_toolButton_Underline_clicked(bool checked)
{
    ui->sendTextEdit->setFontUnderline(checked);
    ui->sendTextEdit->setFocus();
}

void Chat::on_toolButton_SendFile_clicked()
{
    //Transfer *t = this->findChild<Transfer *>("tserver");
    //if (t == 0) {
        tserver->show();
        tserver->initServer();
    //}
}

bool Chat::saveFile(const QString &fileName)//保存文件
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,QStringLiteral("保存文件"),
        QStringLiteral("无法保存文件 %1:\n %2").arg(fileName)
        .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << ui->receiveTextEdit->toPlainText();
    return true;
}

//槽函数，快速抓屏
void Chat::on_toolButton_ScreenShot_clicked()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    screenshot = QPixmap::grabWindow(QApplication::desktop()->winId(),0,0,QApplication::desktop()->width(),QApplication::desktop()->height());
    QString format = "png";
    QString picName = QFileDialog::getSaveFileName(this, QStringLiteral("保存为"),
                                   "temp-image/",
                                   QStringLiteral("%1 Files (*.%2);;All Files (*)")
                                   .arg(format.toUpper())
                                   .arg(format));
    if (!picName.isEmpty())
        screenshot.save(picName, format.toLatin1());
    ui->sendTextEdit->append("<img src='temp-image/" + QFileInfo(picName).fileName() + "'  />");

    this->setStatusTip(QStringLiteral("系统截图"));
}

void Chat::on_toolButton_Save_clicked()
{
     //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    if(ui->receiveTextEdit->document()->isEmpty()) {
        QMessageBox::warning(0, QStringLiteral("警告"), QStringLiteral("没有信息需要保存"), QMessageBox::Ok);
    } else {
       //获得文件名
       QString fileName = QFileDialog::getSaveFileName(this,QStringLiteral("保存聊天记录"),QStringLiteral("聊天记录"),QStringLiteral("file(*.txt);;All File(*.*)"));
       if(!fileName.isEmpty()) {
           saveFile(fileName);
       }
    }
}

void Chat::on_toolButton_Nudge_clicked()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    //qDebug() << "sending nudge...";
    QHostAddress address(ip_t);
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << Nudge << qq_s << name_s;// << qq_t << name_t;

    //qDebug() << "ip_t = " << ip_t;
    udpsocket->writeDatagram(datagram, address, (quint16)44444);

    //this->windowAnimation();
    ui->receiveTextEdit->append(QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"))
                                + QStringLiteral("你发送一个窗口震动"));
}

void Chat::windowAnimation()
{
    QPropertyAnimation animation(this, "geometry");
    QRect s = QRect(this->geometry().topLeft() - QPoint(10, 0),
                    this->geometry().size());
    QRect t = QRect(this->geometry().topLeft() + QPoint(10, 0),
                    this->geometry().size());

    for (int i = 0; i < 5; ++i) {
        animation.setDuration(100);
        animation.setStartValue(s);
        animation.setEndValue(t);
        animation.setEasingCurve(QEasingCurve::Linear);
        //animation.setLoopCount(6);
        animation.start();
        animation.setDuration(100);
        animation.setStartValue(t);
        animation.setEndValue(s);
        animation.setEasingCurve(QEasingCurve::Linear);
        //animation.setLoopCount(6);
        animation.start();
    }
}

void Chat::getWindowAnimation(QString name_sender)
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    this->windowAnimation();
    ui->receiveTextEdit->append(QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"))
                                + " " + name_sender + QStringLiteral(" 发送了一个窗口震动"));
}
