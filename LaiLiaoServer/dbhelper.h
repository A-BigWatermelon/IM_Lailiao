#ifndef DBHELPER_H
#define DBHELPER_H

#include <QSqlDatabase>
#include <QSqlQuery>

class DBHelper
{
public:
    DBHelper();
    static bool createConnection();
};

#endif // DBHELPER_H
