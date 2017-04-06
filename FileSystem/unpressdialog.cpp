#include "unpressdialog.h"
#include<QGridLayout>
#include<QFileDialog>
#include<QPushButton>
#include<QByteArray>
#include<QProcess>
#include<QDebug>
#include<QMessageBox>
#include<QCloseEvent>
using namespace std;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    fileBtn=new QPushButton;
    fileBtn->setText("choose file");
    fileLineEdit=new QLineEdit;
    uncompressBtn=new QPushButton;
    uncompressBtn->setText("uncompress");

    //布局管理
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    mainLayout->addWidget(uncompressBtn,1,0);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    connect(uncompressBtn,SIGNAL(clicked()),this,SLOT(juge()));

}

Dialog::~Dialog()
{

}

void Dialog::showFile()
{
    QFileDialog *filedialog;
    QString s= filedialog->getOpenFileName(this,"open file dialog","/","all files(*.*)");
    fileLineEdit->setText(s);
}

void Dialog::unpress(QString path){
        QDir dir;
        QString outpath="-o"+dir.currentPath()+"\\paper\\examOffice";
        QStringList args;
        QString command ="7z.exe";
        args.append("x");
        args.append(path);
        args.append(outpath);
        args.append("-y");
        //使用winrar.exe
        // args.append("e");
        // args.append(file);
        //args.append("E:\\");
        //qDebug()<<FilePath ;
        QProcess *pro=new QProcess;
        pro->start(command,args);
    }

void Dialog::juge()
{
    if(fileLineEdit->text().isEmpty())
    {
        QMessageBox::information(this,("info"),("choose a file"));
        return;
    }
    else
        return;

}

