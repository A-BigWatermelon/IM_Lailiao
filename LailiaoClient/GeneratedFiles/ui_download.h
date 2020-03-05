/********************************************************************************
** Form generated from reading UI file 'download.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_H
#define UI_DOWNLOAD_H

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

class Ui_Download
{
public:
    QProgressBar *progressBar;
    QLabel *statusLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *quitBtn;
    QPushButton *cancelBtn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *fileNameLabel;
    QToolButton *lookupToolButton;

    void setupUi(QWidget *Download)
    {
        if (Download->objectName().isEmpty())
            Download->setObjectName(QStringLiteral("Download"));
        Download->resize(381, 219);
        progressBar = new QProgressBar(Download);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 130, 331, 20));
        progressBar->setValue(24);
        statusLabel = new QLabel(Download);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(60, 40, 271, 20));
        statusLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(Download);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 160, 160, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        quitBtn = new QPushButton(layoutWidget);
        quitBtn->setObjectName(QStringLiteral("quitBtn"));

        horizontalLayout->addWidget(quitBtn);

        cancelBtn = new QPushButton(layoutWidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);

        layoutWidget1 = new QWidget(Download);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 90, 331, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        fileNameLabel = new QLabel(layoutWidget1);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));

        horizontalLayout_2->addWidget(fileNameLabel);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        lookupToolButton = new QToolButton(layoutWidget1);
        lookupToolButton->setObjectName(QStringLiteral("lookupToolButton"));

        horizontalLayout_3->addWidget(lookupToolButton);


        retranslateUi(Download);

        QMetaObject::connectSlotsByName(Download);
    } // setupUi

    void retranslateUi(QWidget *Download)
    {
        Download->setWindowTitle(QApplication::translate("Download", "\344\270\213\350\275\275\346\226\207\344\273\266", 0));
        statusLabel->setText(QApplication::translate("Download", "none...", 0));
        quitBtn->setText(QApplication::translate("Download", "&Quit", 0));
        cancelBtn->setText(QApplication::translate("Download", "&Cancel", 0));
        label->setText(QApplication::translate("Download", "File:", 0));
        fileNameLabel->setText(QApplication::translate("Download", "...", 0));
        lookupToolButton->setText(QApplication::translate("Download", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Download: public Ui_Download {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_H
