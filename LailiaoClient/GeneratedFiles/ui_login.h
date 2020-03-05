/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *status_label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *qq_LineEdit;
    QLineEdit *pwd_LineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginBtn;
    QPushButton *cancelBtn;
    QLabel *label;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(330, 250);
        Login->setMinimumSize(QSize(330, 250));
        Login->setMaximumSize(QSize(330, 250));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon/Chat-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QStringLiteral(""));
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 120, 191, 111));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_3->setContentsMargins(1, 0, 1, 0);
        status_label = new QLabel(verticalLayoutWidget);
        status_label->setObjectName(QStringLiteral("status_label"));
        status_label->setStyleSheet(QStringLiteral("background:rgba(255, 255, 255,0)"));
        status_label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(status_label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background:rgba(255, 255, 255,0)"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background:rgba(255, 255, 255,0)"));

        verticalLayout->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        qq_LineEdit = new QLineEdit(verticalLayoutWidget);
        qq_LineEdit->setObjectName(QStringLiteral("qq_LineEdit"));
        qq_LineEdit->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(qq_LineEdit);

        pwd_LineEdit = new QLineEdit(verticalLayoutWidget);
        pwd_LineEdit->setObjectName(QStringLiteral("pwd_LineEdit"));

        verticalLayout_2->addWidget(pwd_LineEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loginBtn = new QPushButton(verticalLayoutWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        horizontalLayout->addWidget(loginBtn);

        cancelBtn = new QPushButton(verticalLayoutWidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout_3->addLayout(horizontalLayout);

        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 331, 251));
        label->setStyleSheet(QStringLiteral("background:url(:/icons/icon/Login.png)"));
        label->raise();
        verticalLayoutWidget->raise();

        retranslateUi(Login);
        QObject::connect(cancelBtn, SIGNAL(clicked()), Login, SLOT(close()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\346\235\245\350\201\212", 0));
        status_label->setText(QApplication::translate("Login", "stat", 0));
        label_2->setText(QApplication::translate("Login", "\347\224\250\346\210\267\350\264\246\345\217\267", 0));
        label_3->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        loginBtn->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        cancelBtn->setText(QApplication::translate("Login", "\351\200\200\345\207\272", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
