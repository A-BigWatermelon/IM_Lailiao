#include "dbhelper.h"

DBHelper::DBHelper()
{
}

bool DBHelper::createConnection()
{
	//原始代码，采用“QODBC”驱动失败，可能
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;" //服务器名称
                               "DATABASE=%2;"//数据库名
                               "UID=%3;"     //登录名
                               "PWD=%4;"     //密码
                               ).arg(".")
                       .arg("Lailiao")
                       .arg("sa")
                       .arg("810291")
                       );
	//QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
 //   db.setHostName("asus-IM");          //设置数据库主机名
 //   db.setDatabaseName("qtDB.db");              //设置数据库名
 //   db.setUserName("lsp");                //设置数据库用户名
 //   db.setPassword("123456");                   //设置数据库密码
    if (!db.open()) {
        return false;
    }
    return true;
}
