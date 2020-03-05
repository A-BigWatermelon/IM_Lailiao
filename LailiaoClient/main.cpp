#include <QApplication>
#include "client.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    login.show();
    return a.exec();
}

