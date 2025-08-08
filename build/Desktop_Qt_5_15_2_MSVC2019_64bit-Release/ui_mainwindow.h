/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *downloadButton;
    QLineEdit *urlLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *userNameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *savePathEdit;
    QLabel *label_4;
    QPushButton *preViewButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setLayoutDirection(Qt::RightToLeft);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        downloadButton = new QPushButton(centralwidget);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setGeometry(QRect(220, 390, 191, 91));
        urlLineEdit = new QLineEdit(centralwidget);
        urlLineEdit->setObjectName(QString::fromUtf8("urlLineEdit"));
        urlLineEdit->setGeometry(QRect(120, 190, 411, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 190, 61, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setLineWidth(4);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 250, 71, 31));
        label_2->setFont(font);
        label_2->setLineWidth(4);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 250, 61, 31));
        label_3->setFont(font);
        label_3->setLineWidth(4);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);
        userNameEdit = new QLineEdit(centralwidget);
        userNameEdit->setObjectName(QString::fromUtf8("userNameEdit"));
        userNameEdit->setGeometry(QRect(120, 250, 161, 31));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(370, 250, 161, 31));
        savePathEdit = new QLineEdit(centralwidget);
        savePathEdit->setObjectName(QString::fromUtf8("savePathEdit"));
        savePathEdit->setGeometry(QRect(120, 310, 361, 31));
        savePathEdit->setCursor(QCursor(Qt::IBeamCursor));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 310, 61, 31));
        label_4->setFont(font);
        label_4->setLineWidth(4);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);
        preViewButton = new QPushButton(centralwidget);
        preViewButton->setObjectName(QString::fromUtf8("preViewButton"));
        preViewButton->setGeometry(QRect(490, 310, 41, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        downloadButton->setText(QCoreApplication::translate("MainWindow", "downloadPicture", nullptr));
        urlLineEdit->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        userNameEdit->setText(QString());
        passwordEdit->setText(QString());
        savePathEdit->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275\345\210\260", nullptr));
        preViewButton->setText(QCoreApplication::translate("MainWindow", "\351\242\204\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
