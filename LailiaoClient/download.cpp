#include "download.h"
#include "ui_download.h"
#include <QMessageBox>

Download::Download(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Download)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("File Download"));
    //this->setFixedSize(350,180);

    TotalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;

    tcpClient = new QTcpSocket(this);
    tcpPort = 55555;
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,
            SLOT(displayError(QAbstractSocket::SocketError)));

}

Download::~Download()
{
    delete ui;
}

void Download::displayError(QAbstractSocket::SocketError socketError) //错误处理
{
    switch(socketError)
    {
        case QAbstractSocket::RemoteHostClosedError : break;
        default : qDebug() << tcpClient->errorString();
    }
}

void Download::setHostAddress(QHostAddress address)  //设置服务器地址并连接服务器
{
    hostAddress = address;
    newConnect();
}

void Download::newConnect()
{
    blockSize = 0;
    tcpClient->abort();
    tcpClient->connectToHost(hostAddress, tcpPort);
    time.start();
}

void Download::readMessage()
{
    QDataStream in(tcpClient);
    in.setVersion(QDataStream::Qt_5_5);

    float useTime = time.elapsed();
    if(bytesReceived <= sizeof(qint64)*2){
        if((tcpClient->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0)){
            in>>TotalBytes>>fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if((tcpClient->bytesAvailable() >= fileNameSize) && (fileNameSize != 0)){
            in>>fileName;
            bytesReceived +=fileNameSize;

            if(!localFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this,tr("Application"),tr("cannot read the file %1:\n%2.").arg(fileName).arg(localFile->errorString()));
                return;
            }
        }else{
            return;
        }
    }
    if(bytesReceived < TotalBytes){
        bytesReceived += tcpClient->bytesAvailable();
        inBlock = tcpClient->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesReceived);
    qDebug()<<bytesReceived<<"received"<<TotalBytes;

    double speed = bytesReceived / useTime;
    ui->statusLabel->setText(tr("already received %1MB (%2MB/s) \n total %3MB time elapsed:%4s\ntime left：%5s")
                                   .arg(bytesReceived / (1024*1024))//已接收
                                   .arg(speed*1000/(1024*1024),0,'f',2)//速度
                                   .arg(TotalBytes / (1024 * 1024))//总大小
                                   .arg(useTime/1000,0,'f',0)//用时
                                   .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//剩余时间

    if (bytesReceived == TotalBytes)
    {
        tcpClient->close();
        ui->statusLabel->setText(tr("file %1 received").arg(fileName));
        localFile->close();   //接收完文件后，一定要关闭，不然可能出问题
    }
}


void Download::on_quitBtn_clicked()
{
    tcpClient->abort();
    this->close();
}

void Download::on_cancelBtn_clicked()
{
    tcpClient->abort();
}
