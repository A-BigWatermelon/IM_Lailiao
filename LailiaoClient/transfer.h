#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>

namespace Ui {
class Transfer;
}

class Transfer : public QWidget
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = 0);
    ~Transfer();
    void refused();
    void initServer();

private:
    Ui::Transfer *ui;

    qint16 tcpPort;
    QTcpServer *tcpServer;
    QString fileName;
    QString theFileName;
    QFile *localFile;

    qint64 TotalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QByteArray outBlock;//缓存一次发送的数据

    QTcpSocket *clientConnection;

    QTime time;//计时器
private slots:
    void sendMessage();
    void updateClientProgress(qint64 numBytes);

    void on_toolButton_select_clicked();

    void on_sendBtn_clicked();

    void on_quitBtn_clicked();

signals:
    void sendFileName(QString fileName);
};

#endif // TRANSFER_H
