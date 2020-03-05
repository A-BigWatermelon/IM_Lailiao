/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QAction *action_Exit;
    QAction *actionDelete;
    QAction *actionAdd;
    QWidget *centralwidget;
    QPushButton *searchBtn;
    QComboBox *comboBox;
    QLabel *nameLabel;
    QToolButton *toolButton_tx;
    QTreeWidget *treeWidget;
    QLabel *background;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(208, 485);
        Client->setMinimumSize(QSize(208, 485));
        Client->setMaximumSize(QSize(208, 485));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon/Chat-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Client->setWindowIcon(icon);
        action_Exit = new QAction(Client);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        actionDelete = new QAction(Client);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionAdd = new QAction(Client);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        searchBtn = new QPushButton(centralwidget);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setGeometry(QRect(160, 447, 31, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icon/search-icon-hi.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchBtn->setIcon(icon1);
        comboBox = new QComboBox(centralwidget);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/QQ/icon/qq/Header+Search_Online_Normal@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/QQ/icon/qq/Header+Search_Offline_Hover@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon3, QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 50, 111, 21));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(80, 10, 100, 16));
        toolButton_tx = new QToolButton(centralwidget);
        toolButton_tx->setObjectName(QStringLiteral("toolButton_tx"));
        toolButton_tx->setGeometry(QRect(10, 10, 61, 61));
        toolButton_tx->setIconSize(QSize(60, 60));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(-1, 80, 210, 360));
        treeWidget->setMinimumSize(QSize(210, 360));
        treeWidget->setMaximumSize(QSize(210, 360));
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        background = new QLabel(centralwidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 210, 485));
        background->setStyleSheet(QStringLiteral("background:url(:/icons/icon/chat.png)"));
        Client->setCentralWidget(centralwidget);
        background->raise();
        searchBtn->raise();
        comboBox->raise();
        nameLabel->raise();
        toolButton_tx->raise();
        treeWidget->raise();

        retranslateUi(Client);
        QObject::connect(action_Exit, SIGNAL(triggered()), Client, SLOT(close()));

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "\346\235\245\350\201\212", 0));
        action_Exit->setText(QApplication::translate("Client", "&Exit", 0));
        actionDelete->setText(QApplication::translate("Client", "\345\210\240\351\231\244\345\245\275\345\217\213", 0));
        actionAdd->setText(QApplication::translate("Client", "\347\274\226\350\276\221\345\244\207\346\263\250", 0));
        searchBtn->setText(QString());
        comboBox->setItemText(0, QApplication::translate("Client", "\345\234\250\347\272\277", 0));
        comboBox->setItemText(1, QApplication::translate("Client", "\347\246\273\347\272\277", 0));

        nameLabel->setText(QApplication::translate("Client", "TextLabel", 0));
        toolButton_tx->setText(QApplication::translate("Client", "...", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Client", "\346\210\221\347\232\204\345\245\275\345\217\213", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
