#include "dbhelper.h"

DBHelper::DBHelper()
{
}

bool DBHelper::createConnection()
{
	//ԭʼ���룬���á�QODBC������ʧ�ܣ�����
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;" //����������
                               "DATABASE=%2;"//���ݿ���
                               "UID=%3;"     //��¼��
                               "PWD=%4;"     //����
                               ).arg(".")
                       .arg("Lailiao")
                       .arg("sa")
                       .arg("810291")
                       );
	//QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
 //   db.setHostName("asus-IM");          //�������ݿ�������
 //   db.setDatabaseName("qtDB.db");              //�������ݿ���
 //   db.setUserName("lsp");                //�������ݿ��û���
 //   db.setPassword("123456");                   //�������ݿ�����
    if (!db.open()) {
        return false;
    }
    return true;
}
