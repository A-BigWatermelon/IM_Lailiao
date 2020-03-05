/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *online_list_TableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *online_cnt_label;
    QLabel *statusLabel;
    QPushButton *exitBtn;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(520, 360);
        Server->setMinimumSize(QSize(520, 360));
        Server->setMaximumSize(QSize(520, 360));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/Server.png"), QSize(), QIcon::Normal, QIcon::Off);
        Server->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(Server);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 501, 343));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        online_list_TableWidget = new QTableWidget(verticalLayoutWidget);
        if (online_list_TableWidget->columnCount() < 4)
            online_list_TableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        online_list_TableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        online_list_TableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        online_list_TableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QFont font;
        font.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        online_list_TableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        online_list_TableWidget->setObjectName(QStringLiteral("online_list_TableWidget"));
        online_list_TableWidget->setMinimumSize(QSize(0, 310));

        verticalLayout->addWidget(online_list_TableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        online_cnt_label = new QLabel(verticalLayoutWidget);
        online_cnt_label->setObjectName(QStringLiteral("online_cnt_label"));

        horizontalLayout->addWidget(online_cnt_label);

        statusLabel = new QLabel(verticalLayoutWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setLineWidth(2);
        statusLabel->setMidLineWidth(2);

        horizontalLayout->addWidget(statusLabel);

        exitBtn = new QPushButton(verticalLayoutWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout->addWidget(exitBtn);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 4);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "\346\234\215\345\212\241\345\231\250\347\253\257", 0));
        QTableWidgetItem *___qtablewidgetitem = online_list_TableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Server", "\347\231\273\351\231\206IP\345\234\260\345\235\200", 0));
        QTableWidgetItem *___qtablewidgetitem1 = online_list_TableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Server", "\345\270\220\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = online_list_TableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Server", "\346\230\265\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = online_list_TableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Server", "\347\231\273\351\231\206\346\227\266\351\227\264", 0));
        label->setText(QApplication::translate("Server", "\345\234\250\347\272\277\344\272\272\346\225\260:", 0));
        online_cnt_label->setText(QApplication::translate("Server", "0", 0));
        statusLabel->setText(QApplication::translate("Server", "\347\212\266\346\200\201:", 0));
        exitBtn->setText(QApplication::translate("Server", "\345\205\263\351\227\255\346\234\215\345\212\241\347\253\257", 0));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
