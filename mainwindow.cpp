#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <Qauthenticator>
#include <QMessageBox>

// #pragma execution_character_set("GBK")

// https://dldir1v6.qq.com/weixin/Universal/Windows/WeChatWin.exe


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("QtDownloader"));


    networkManager = new QNetworkAccessManager(this);
    connect(ui->downloadButton, &QPushButton::clicked, this, &MainWindow::startDownload);
    connect(networkManager, &QNetworkAccessManager::authenticationRequired,
            this, &MainWindow::onAuthenticationRequired);
    connect(ui->preViewButton, &QPushButton::clicked, this, &MainWindow::setPreviewAddress);

    connect(ui->urlLineEdit, &QLineEdit::editingFinished, this, &MainWindow::autoSetUserAndPassword);



}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
槽函数实现
*/

void MainWindow::autoSetUserAndPassword(){
    QUrl url(ui->urlLineEdit->text(), QUrl::TolerantMode);

    ui->userNameEdit->setText(url.userName());
    ui->passwordEdit->setText(url.password());
}


void MainWindow::setPreviewAddress(){

    qDebug() << "setPreviewAddress";

    QUrl url(ui->urlLineEdit->text(), QUrl::TolerantMode);
    QString filename = QFileInfo(url.path()).fileName();

    QString suffix = QFileInfo(filename).suffix().toLower();
    QString filter;

    if (suffix == tr("jpg") || suffix == tr("jpeg")) {
        filter = tr("JPEG 图片 (*.jpg *.jpeg)");
    } else if (suffix == tr("png")) {
        filter = tr("PNG 图片 (*.png)");
    } else if (suffix == tr("txt")) {
        filter = tr("文本文件 (*.txt)");
    } else if (suffix == tr("pdf")) {
        filter = tr("PDF 文件 (*.pdf)");
    } else if (suffix == tr("exe")) {
        filter = tr("可执行文件 (*.exe)");
    } else {
        filter = tr("所有文件 (*.*)");
    }

    QString savePath = QFileDialog::getSaveFileName(
        this,
        tr("文件保存路径"),
        QDir::homePath() + tr("/") + filename,
        filter
    );
    ui->savePathEdit->setText(savePath);
}


void MainWindow::startDownload(){


    //获取url
    QString urlString = ui->urlLineEdit->text();
    if(urlString.isEmpty()){
        qDebug() << "url不能为空";
        return;
    }


    QUrl url(urlString, QUrl::TolerantMode);
    if(url.isValid()){
        qDebug() << "url格式正确";
    } else {
        qDebug() << "url格式错误";
        return;
    }

    // 提取 URL 组成部分
    QString scheme = url.scheme();         // 协议
    QString host = url.host();            // 主机
    int port = url.port();                // 端口
    QString path = url.path();            // 路径
    QString userName = url.userName();    // 用户名
    QString password = url.password();    // 密码
    QString fileName = QFileInfo(url.path()).fileName(); // 文件名

    // 调试输出解析结果
    qDebug() << "协议:" << scheme;
    qDebug() << "主机:" << host;
    qDebug() << "端口:" << (port == -1 ? tr("默认") : QString::number(port));
    qDebug() << "路径:" << path;
    qDebug() << "用户:" << userName;
    qDebug() << "密码:" << password;
    qDebug() << "文件:" << fileName;


    // ftp://127.0.0.1:21/picture/1.jpg


    //获取文件保存路径，默认为 C:\Users\用户名
    // QString savePath = QFileDialog::getSaveFileName(this, tr("保存文件路径"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    QString savePath = ui->savePathEdit->text();
    if(savePath.isEmpty()){
        QMessageBox::warning(this, tr("警告"), tr("请选择保存路径"));
        qDebug() << "addressWarning";
        return;
    }

    file = new QFile(savePath);
    //尝试以只写模式打开
    if(!file->open(QIODevice::WriteOnly)){
        qDebug() << tr("无法保存");
        delete file;
        file = nullptr;
        return;
    } else {
        qDebug() << "startDownload" << urlString;
    }

    //请求并下载
    QNetworkRequest request(urlString);
    reply = networkManager->get(request);

    ui->downloadButton->setEnabled(false);


    connect(reply, &QNetworkReply::finished, this, &MainWindow::onDownloadCompleted);
    connect(reply, &QNetworkReply::readyRead, this, &MainWindow::onReadyRead);
}

void MainWindow::onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    // 提供 FTP 用户名和密码
    authenticator->setUser(ui->userNameEdit->text());
    authenticator->setPassword(ui->passwordEdit->text());
    qDebug() << "提供认证信息: 用户名=" << authenticator->user() << ", 密码=" << authenticator->password();
}

void MainWindow::onReadyRead()
{
    if (file && file->isOpen()) {
        qint64 bytes = file->write(reply->readAll());
        file->flush(); // 确保数据写入磁盘
        qDebug() << "写入字节数:" << bytes;
    } else {
        qDebug() << tr("文件未打开，无法写入数据   ");
    }
}

void MainWindow::onDownloadCompleted()
{
    // 检查下载状态和文件状态
    bool success = (reply->error() == QNetworkReply::NoError);
    QString errorString = reply->errorString();
    qint64 fileSize = file ? file->size() : 0;
    QString fileName = file ? file->fileName() : tr("未知文件");

    // 处理下载结果
    if (success && file && fileSize > 0) {
        qDebug() << "下载完成，文件:" << fileName << ", 大小:" << fileSize << "字节";
        QMessageBox::information(this, tr("提示"), tr("下载完成，文件大小: %1 字节").arg(fileSize));
    } else {
        // 详细信息
        QString errorMsg = tr("下载失败: %1").arg(errorString);
        if (!file) {
            errorMsg += tr("文件对象未创建     ");
        } else if (!file->exists()) {
            errorMsg += tr("文件未创建: %1").arg(fileName);
        } else if (fileSize == 0) {
            errorMsg += tr("文件为空: %1").arg(fileName);
        }
        qDebug() << "下载出错: 错误代码=" << reply->error() << ", 描述=" << errorString
                 << ", 文件=" << fileName << ", 大小=" << fileSize;

        errorMsg += reply->error();
        qDebug() << "replyError:" << reply->error();

        if (file && file->isOpen()) {
            file->close();
            file->remove();
            qDebug() << "文件已删除:" << fileName;
        }

        QMessageBox::critical(this, tr("错误"), errorMsg);
    }

    // 清理
    if (file) {
        if (file->isOpen()) {
            file->close();
            qDebug() << "文件关闭:" << fileName;
        }
        delete file;
        file = nullptr;
        qDebug() << "文件对象已释放     ";
    }

    reply->deleteLater();
    ui->downloadButton->setEnabled(true);
    qDebug() << "结束 onDownloadCompleted()";
}
