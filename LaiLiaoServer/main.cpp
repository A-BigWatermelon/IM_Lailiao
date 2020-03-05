#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "server.h"
#include "dbhelper.h"

int main(int argc, char *argv[])
{
    //DBHelper::createConnection();
    if (!DBHelper::createConnection())
    {
        return 1;//qDebug()<<"false";
    }
    QApplication a(argc, argv);
    Server w;
    w.show();

    return a.exec();
}
