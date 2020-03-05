/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QAction *action_Send_File;
    QAction *action_Exit;
    QWidget *centralwidget;
    QTextEdit *receiveTextEdit;
    QTextEdit *sendTextEdit;
    QToolButton *YouToolButton;
    QToolButton *myToolButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *qqLabel;
    QLabel *nameLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeBtn;
    QPushButton *sendBtn;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_Font;
    QToolButton *toolButton_Palette;
    QToolButton *toolButton_Bold;
    QToolButton *toolButton_Italic;
    QToolButton *toolButton_Underline;
    QToolButton *toolButton_ScreenShot;
    QToolButton *toolButton_Nudge;
    QToolButton *toolButton_SendFile;
    QToolButton *toolButton_Save;

    void setupUi(QMainWindow *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(470, 485);
        Chat->setMinimumSize(QSize(470, 485));
        Chat->setMaximumSize(QSize(470, 485));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon/Chat-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Chat->setWindowIcon(icon);
        action_Send_File = new QAction(Chat);
        action_Send_File->setObjectName(QStringLiteral("action_Send_File"));
        action_Exit = new QAction(Chat);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        centralwidget = new QWidget(Chat);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        receiveTextEdit = new QTextEdit(centralwidget);
        receiveTextEdit->setObjectName(QStringLiteral("receiveTextEdit"));
        receiveTextEdit->setGeometry(QRect(20, 10, 341, 271));
        receiveTextEdit->setReadOnly(true);
        sendTextEdit = new QTextEdit(centralwidget);
        sendTextEdit->setObjectName(QStringLiteral("sendTextEdit"));
        sendTextEdit->setGeometry(QRect(20, 340, 341, 101));
        YouToolButton = new QToolButton(centralwidget);
        YouToolButton->setObjectName(QStringLiteral("YouToolButton"));
        YouToolButton->setGeometry(QRect(370, 10, 81, 81));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icon/icq_online.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        YouToolButton->setIcon(icon1);
        YouToolButton->setIconSize(QSize(64, 64));
        myToolButton = new QToolButton(centralwidget);
        myToolButton->setObjectName(QStringLiteral("myToolButton"));
        myToolButton->setGeometry(QRect(370, 340, 81, 81));
        myToolButton->setIcon(icon1);
        myToolButton->setIconSize(QSize(64, 64));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(370, 90, 81, 42));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        qqLabel = new QLabel(layoutWidget);
        qqLabel->setObjectName(QStringLiteral("qqLabel"));

        verticalLayout->addWidget(qqLabel);

        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(200, 450, 158, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        closeBtn = new QPushButton(layoutWidget1);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);

        sendBtn = new QPushButton(layoutWidget1);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 290, 341, 44));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_Font = new QToolButton(layoutWidget2);
        toolButton_Font->setObjectName(QStringLiteral("toolButton_Font"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qq/icon/qq/aio_favourite_cell_normal@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Font->setIcon(icon2);

        horizontalLayout_2->addWidget(toolButton_Font);

        toolButton_Palette = new QToolButton(layoutWidget2);
        toolButton_Palette->setObjectName(QStringLiteral("toolButton_Palette"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icon/textcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Palette->setIcon(icon3);

        horizontalLayout_2->addWidget(toolButton_Palette);

        toolButton_Bold = new QToolButton(layoutWidget2);
        toolButton_Bold->setObjectName(QStringLiteral("toolButton_Bold"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icon/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Bold->setIcon(icon4);
        toolButton_Bold->setCheckable(true);

        horizontalLayout_2->addWidget(toolButton_Bold);

        toolButton_Italic = new QToolButton(layoutWidget2);
        toolButton_Italic->setObjectName(QStringLiteral("toolButton_Italic"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icon/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Italic->setIcon(icon5);
        toolButton_Italic->setCheckable(true);

        horizontalLayout_2->addWidget(toolButton_Italic);

        toolButton_Underline = new QToolButton(layoutWidget2);
        toolButton_Underline->setObjectName(QStringLiteral("toolButton_Underline"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icon/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Underline->setIcon(icon6);
        toolButton_Underline->setCheckable(true);

        horizontalLayout_2->addWidget(toolButton_Underline);

        toolButton_ScreenShot = new QToolButton(layoutWidget2);
        toolButton_ScreenShot->setObjectName(QStringLiteral("toolButton_ScreenShot"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/QQ/icon/qq/toolbar_screenCapture_hover@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ScreenShot->setIcon(icon7);
        toolButton_ScreenShot->setIconSize(QSize(16, 16));

        horizontalLayout_2->addWidget(toolButton_ScreenShot);

        toolButton_Nudge = new QToolButton(layoutWidget2);
        toolButton_Nudge->setObjectName(QStringLiteral("toolButton_Nudge"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/QQ/icon/qq/toolbar_shake_hover@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Nudge->setIcon(icon8);

        horizontalLayout_2->addWidget(toolButton_Nudge);

        toolButton_SendFile = new QToolButton(layoutWidget2);
        toolButton_SendFile->setObjectName(QStringLiteral("toolButton_SendFile"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/QQ/icon/qq/titlebar_function_fileTransfer_hover@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SendFile->setIcon(icon9);

        horizontalLayout_2->addWidget(toolButton_SendFile);

        toolButton_Save = new QToolButton(layoutWidget2);
        toolButton_Save->setObjectName(QStringLiteral("toolButton_Save"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/QQ/icon/qq/toolbar_history_hover@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Save->setIcon(icon10);

        horizontalLayout_2->addWidget(toolButton_Save);

        Chat->setCentralWidget(centralwidget);
        QWidget::setTabOrder(sendBtn, sendTextEdit);
        QWidget::setTabOrder(sendTextEdit, toolButton_Font);
        QWidget::setTabOrder(toolButton_Font, toolButton_Palette);
        QWidget::setTabOrder(toolButton_Palette, toolButton_Bold);
        QWidget::setTabOrder(toolButton_Bold, toolButton_Italic);
        QWidget::setTabOrder(toolButton_Italic, toolButton_Underline);
        QWidget::setTabOrder(toolButton_Underline, toolButton_SendFile);
        QWidget::setTabOrder(toolButton_SendFile, YouToolButton);
        QWidget::setTabOrder(YouToolButton, myToolButton);
        QWidget::setTabOrder(myToolButton, receiveTextEdit);

        retranslateUi(Chat);
        QObject::connect(action_Exit, SIGNAL(triggered()), Chat, SLOT(close()));
        QObject::connect(closeBtn, SIGNAL(clicked()), Chat, SLOT(close()));

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QMainWindow *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "MainWindow", 0));
        action_Send_File->setText(QApplication::translate("Chat", "&Send File", 0));
        action_Exit->setText(QApplication::translate("Chat", "&Exit", 0));
        YouToolButton->setText(QApplication::translate("Chat", "...", 0));
        myToolButton->setText(QApplication::translate("Chat", "...", 0));
        qqLabel->setText(QApplication::translate("Chat", "TextLabel", 0));
        nameLabel->setText(QApplication::translate("Chat", "TextLabel", 0));
        closeBtn->setText(QApplication::translate("Chat", "\345\205\263\351\227\255\345\257\271\350\257\235", 0));
        sendBtn->setText(QApplication::translate("Chat", "\345\217\221\351\200\201\344\277\241\346\201\257", 0));
        toolButton_Font->setText(QApplication::translate("Chat", "...", 0));
        toolButton_Palette->setText(QApplication::translate("Chat", "...", 0));
        toolButton_Bold->setText(QApplication::translate("Chat", "...", 0));
        toolButton_Italic->setText(QApplication::translate("Chat", "...", 0));
        toolButton_Underline->setText(QApplication::translate("Chat", "...", 0));
        toolButton_ScreenShot->setText(QApplication::translate("Chat", "...", 0));
        toolButton_Nudge->setText(QApplication::translate("Chat", "...", 0));
        toolButton_SendFile->setText(QApplication::translate("Chat", "...", 0));
        toolButton_Save->setText(QApplication::translate("Chat", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
