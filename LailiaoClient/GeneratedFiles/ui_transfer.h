/********************************************************************************
** Form generated from reading UI file 'transfer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_H
#define UI_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transfer
{
public:
    QProgressBar *progressBar;
    QLabel *statusLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendBtn;
    QPushButton *quitBtn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QToolButton *toolButton_select;

    void setupUi(QWidget *Transfer)
    {
        if (Transfer->objectName().isEmpty())
            Transfer->setObjectName(QStringLiteral("Transfer"));
        Transfer->resize(370, 138);
        progressBar = new QProgressBar(Transfer);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 70, 291, 21));
        progressBar->setValue(24);
        statusLabel = new QLabel(Transfer);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(40, 20, 291, 20));
        statusLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(Transfer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 100, 158, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendBtn = new QPushButton(layoutWidget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        quitBtn = new QPushButton(layoutWidget);
        quitBtn->setObjectName(QStringLiteral("quitBtn"));

        horizontalLayout->addWidget(quitBtn);

        layoutWidget1 = new QWidget(Transfer);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 40, 291, 28));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        toolButton_select = new QToolButton(layoutWidget1);
        toolButton_select->setObjectName(QStringLiteral("toolButton_select"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_select->setIcon(icon);

        horizontalLayout_3->addWidget(toolButton_select);


        retranslateUi(Transfer);

        QMetaObject::connectSlotsByName(Transfer);
    } // setupUi

    void retranslateUi(QWidget *Transfer)
    {
        Transfer->setWindowTitle(QApplication::translate("Transfer", "\345\217\221\351\200\201\346\226\207\344\273\266", 0));
        statusLabel->setText(QApplication::translate("Transfer", "stat", 0));
        sendBtn->setText(QApplication::translate("Transfer", "\345\217\221\351\200\201", 0));
        quitBtn->setText(QApplication::translate("Transfer", "\351\200\200\345\207\272", 0));
        label_2->setText(QApplication::translate("Transfer", "\350\257\267\351\200\211\346\213\251\345\217\221\351\200\201\346\226\207\344\273\266\357\274\232", 0));
        label_3->setText(QApplication::translate("Transfer", "...", 0));
        toolButton_select->setText(QApplication::translate("Transfer", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Transfer: public Ui_Transfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_H
