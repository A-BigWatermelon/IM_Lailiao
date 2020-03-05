/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelBtn;
    QPushButton *sendBtn;
    QPushButton *adduserButton;
    QSplitter *splitter;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *qqRadioButton;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *qqLineEdit;
    QWidget *verticalLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *user_id;
    QLabel *user_nickName;
    QLabel *user_ip;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QStringLiteral("Search"));
        Search->resize(282, 164);
        QIcon icon;
        icon.addFile(QStringLiteral(":/QQ/icon/qq/titlebar_function_fileTransfer_hover@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        Search->setWindowIcon(icon);
        layoutWidget = new QWidget(Search);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 120, 239, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelBtn = new QPushButton(layoutWidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);

        sendBtn = new QPushButton(layoutWidget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        adduserButton = new QPushButton(layoutWidget);
        adduserButton->setObjectName(QStringLiteral("adduserButton"));

        horizontalLayout->addWidget(adduserButton);

        splitter = new QSplitter(Search);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 10, 244, 41));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget_2 = new QWidget(splitter);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        qqRadioButton = new QRadioButton(layoutWidget_2);
        qqRadioButton->setObjectName(QStringLiteral("qqRadioButton"));

        verticalLayout->addWidget(qqRadioButton);

        splitter->addWidget(layoutWidget_2);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        qqLineEdit = new QLineEdit(layoutWidget_3);
        qqLineEdit->setObjectName(QStringLiteral("qqLineEdit"));

        verticalLayout_2->addWidget(qqLineEdit);

        splitter->addWidget(layoutWidget_3);
        verticalLayoutWidget = new QWidget(Search);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 60, 231, 50));
        formLayout = new QFormLayout(verticalLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        user_id = new QLabel(verticalLayoutWidget);
        user_id->setObjectName(QStringLiteral("user_id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, user_id);

        user_nickName = new QLabel(verticalLayoutWidget);
        user_nickName->setObjectName(QStringLiteral("user_nickName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, user_nickName);

        user_ip = new QLabel(verticalLayoutWidget);
        user_ip->setObjectName(QStringLiteral("user_ip"));

        formLayout->setWidget(2, QFormLayout::FieldRole, user_ip);


        retranslateUi(Search);
        QObject::connect(cancelBtn, SIGNAL(clicked()), Search, SLOT(close()));

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QApplication::translate("Search", "\346\267\273\345\212\240\345\245\275\345\217\213", 0));
        cancelBtn->setText(QApplication::translate("Search", "\345\217\226\346\266\210\346\267\273\345\212\240", 0));
        sendBtn->setText(QApplication::translate("Search", "\346\237\245\346\211\276\347\224\250\346\210\267", 0));
        adduserButton->setText(QApplication::translate("Search", "\346\267\273\345\212\240\347\224\250\346\210\267", 0));
        qqRadioButton->setText(QApplication::translate("Search", "\347\224\250\346\210\267\350\264\246\345\217\267", 0));
        label->setText(QApplication::translate("Search", "\347\224\250\346\210\267\350\264\246\345\217\267:", 0));
        label_2->setText(QApplication::translate("Search", "\347\224\250\346\210\267\346\230\265\347\247\260:", 0));
        label_3->setText(QApplication::translate("Search", "\347\224\250\346\210\267IP:", 0));
        user_id->setText(QString());
        user_nickName->setText(QString());
        user_ip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
