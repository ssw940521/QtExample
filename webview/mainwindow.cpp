#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ini配置
    QSettings *set=new QSettings("setting.ini",QSettings::IniFormat);
    QString seturl=set->value("/url/first").toString();


    //初始化网页
    view =new QWebEngineView(this);
    view->load(QUrl(seturl));

    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    view->resize(this->size());
}
