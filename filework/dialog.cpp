#include "dialog.h"
#include<QTextCodec>
#include<QString>
#include<QGridLayout>
#include<QFileDialog>
#include<QPushButton>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{   setWindowTitle("文件操作");

    readfile1=new QPushButton;
    readfile1->setText("choose file");
   /* QPushButton *readfile2=new QPushButton;
    readfile2->setText("选择路径");
    QPushButton *copyfileBtn=new QPushButton;
    copyfileBtn->setText("复制");
    QLineEdit *fileLineEdit=new QLineEdit;

    QLineEdit *showfilename=new QLineEdit;*/
    QGridLayout *mainlayout=new QGridLayout(this);
    mainlayout->addWidget(readfile1,0,0);
    mainlayout->addWidget(fileLineEdit,0,1);
   // mainlayout->addWidget(readfile2,1,0);
    //mainlayout->addWidget(showfilename,1,1);
    //mainlayout->addWidget(copyfileBtn,2,0);
    connect(readfile1,SIGNAL(clicked()),this,SLOT(showFile()));


}

Dialog::~Dialog()
{

}

void Dialog::showFile()
{
    QString s=QFileDialog::getOpenFileName(this,"open file dialog","/","all files(*.*)");
    fileLineEdit->setText(s);
}

void Dialog::Choosedir()
{


}

void Dialog::Copyfile()
{

}
