#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>

namespace Ui {
class Download;
}

class Download : public QWidget
{
    Q_OBJECT

public:
    explicit Download(QWidget *parent = 0);
    ~Download();
    void setHostAddress(QHostAddress address);
    void setFileName(QString fileName){localFile = new QFile(fileName);}

private:
    Ui::Download *ui;
    QTcpSocket *tcpClient;
    quint16 blockSize;
    QHostAddress hostAddress;
    qint16 tcpPort;

    qint64 TotalBytes;
    qint64 bytesReceived;
    qint64 bytesToReceive;
    qint64 fileNameSize;
    QString fileName;
    QFile *localFile;
    QByteArray inBlock;

    QTime time;

private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);

    void on_quitBtn_clicked();
    void on_cancelBtn_clicked();
};

#endif // DOWNLOAD_H
