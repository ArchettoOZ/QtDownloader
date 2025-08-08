#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void startDownload();//按钮点击后开始下载

    void onDownloadCompleted();//检查下载是否完成

    void onReadyRead();//将下载的数据写入文件

    void onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);//显式提供用户名和密码

    void setPreviewAddress();//按按钮，设置保存地址

    void autoSetUserAndPassword();//根据输入的url自动补全user和pw


private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *networkManager;// 网络请求管理器
    QNetworkReply *reply;// 网络回复，用于获取下载数据
    QFile *file;// 用于将下载的数据写入文件

};
#endif // MAINWINDOW_H
