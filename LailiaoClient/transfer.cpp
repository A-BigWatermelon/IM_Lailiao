#include "transfer.h"
#include "ui_transfer.h"
#include <QFileDialog>
#include <QMessageBox>

Transfer::Transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);

    //this->setFixedSize(350,180);

    tcpPort = 55555;
    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
    initServer();
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::initServer()//初始化
{
    loadSize = 4*1024;
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;

    ui->statusLabel->setText(tr("Please select a file"));
    ui->progressBar->reset();
    ui->toolButton_select->setEnabled(true);
    ui->sendBtn->setEnabled(false);

    tcpServer->close();
}


void Transfer::sendMessage()  //开始发送数据
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    ui->sendBtn->setEnabled(false);
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(bytesWritten(qint64)),SLOT(updateClientProgress(qint64)));

    ui->statusLabel->setText(tr("start transfering %1 ！").arg(theFileName));

    localFile = new QFile(fileName);
    if(!localFile->open((QFile::ReadOnly))){//以只读方式打开
        QMessageBox::warning(this,tr("Application"),tr("Can't open file' %1:\n%2").arg(fileName).arg(localFile->errorString()));
        return;
    }
    TotalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_5);
    time.start();  //开始计时
    QString currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    TotalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite = TotalBytes - clientConnection->write(outBlock);
    qDebug()<<currentFile<<TotalBytes;
    outBlock.resize(0);

}

void Transfer::updateClientProgress(qint64 numBytes) //更新进度条
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    bytesWritten += (int)numBytes;
    if (bytesToWrite > 0){
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -= (int)clientConnection->write(outBlock);
        outBlock.resize(0);
    } else {
        localFile->close();
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesWritten);

    float useTime = time.elapsed();
    double speed = bytesWritten / useTime;
    ui->statusLabel->setText(tr("already transfered %1MB (%2MB/s) \n in total %3MB time elapsed: %4秒\n rest time：%5秒")
                                  .arg(bytesWritten / (1024*1024))//已发送
                                  .arg(speed*1000/(1024*1024),0,'f',2)//速度
                                  .arg(TotalBytes / (1024 * 1024))//总大小
                                  .arg(useTime/1000,0,'f',0)//用时
                                  .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//剩余时间

    //num.sprintf("%.1f KB/s", (bytesWritten*1000) / (1024.0*time.elapsed()));
    if (bytesWritten == TotalBytes)
        ui->statusLabel->setText(tr("File %1 transfered successfully").arg(theFileName));

}

void Transfer::refused()   //被对方拒绝
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    tcpServer->close();
    ui->statusLabel->setText(tr("Request Denied."));
}

void Transfer::on_toolButton_select_clicked()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        theFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
        ui->statusLabel->setText(tr("sending file：%1 ").arg(theFileName));
        ui->sendBtn->setEnabled(true);
        ui->toolButton_select->setEnabled(false);
    }
}

void Transfer::on_sendBtn_clicked()
{
     //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    if(!tcpServer->listen(QHostAddress::Any,tcpPort))//开始监听
    {
        qDebug() << tcpServer->errorString();
        close();
        return;
    }
    ui->statusLabel->setText(tr("wait to send..."));
    emit sendFileName(theFileName);
}

void Transfer::on_quitBtn_clicked()
{
    if (tcpServer->isListening()) {
        tcpServer->close();
        clientConnection->abort();
    }
    this->close();
}
