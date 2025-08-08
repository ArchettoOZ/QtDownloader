#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QUrl>
#include <QFile>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *code = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(code);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
