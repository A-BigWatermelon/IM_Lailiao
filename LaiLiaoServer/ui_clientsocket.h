#ifndef UI_CLIENTSOCKET_H
#define UI_CLIENTSOCKET_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientSocket
{
public:

    void setupUi(QWidget *ClientSocket)
    {
        if (ClientSocket->objectName().isEmpty())
            ClientSocket->setObjectName(QString::fromUtf8("ClientSocket"));
        ClientSocket->resize(520, 360);

        retranslateUi(ClientSocket);

        QMetaObject::connectSlotsByName(ClientSocket);
    } // setupUi

    void retranslateUi(QWidget *ClientSocket)
    {
        ClientSocket->setWindowTitle(QApplication::translate("ClientSocket", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientSocket: public Ui_ClientSocket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSOCKET_H
