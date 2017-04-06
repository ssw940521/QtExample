#include "topbar.h"
#include<question.h>
#include<scoreprocess.h>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
TopBar::TopBar(QWidget *parent):QDialog(parent)
{
    int width=QApplication::desktop()->width();
    this->setFixedWidth(width);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::Dialog|Qt::WindowStaysOnTopHint );
    setWindowTitle("bar");
    this->setGeometry(0,0,width,50);
    time=610;
    timer=new QTimer(this);
    timer->start(1000);
    label=new QLabel;
    label->setText("MS office");
    timelabel=new QLabel;
    file=new QPushButton;
    file->setText("考生文件夹");
    showq=new QPushButton;
    showq->setText("显示题目");
    process=new QPushButton;
    process->setText("考试进度");
    help=new QPushButton;
    help->setText("帮助");
    submit=new QPushButton;
    submit->setText("提交考卷");
    mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(timelabel);
    mainLayout->addStretch();
    mainLayout->addWidget(file);
    mainLayout->addWidget(showq);
    mainLayout->addWidget(process);
    mainLayout->addWidget(help);
    mainLayout->addWidget(submit);
    q=new question;
    q->show();
    //q->setWindowFlags(Qt::SubWindow|Qt::Tool);
    flag=false;
    //托盘气泡
     trayicon=new QSystemTrayIcon(this);
     trayicon->setIcon(QIcon(":/Icon/user.png"));
     trayicon->show();
    //连接槽函数
    connect(timer, SIGNAL(timeout()), this, SLOT(subTime()));
//  connect(timer,SIGNAL(timeout()),this,SLOT(showwarn()));
    connect(showq,SIGNAL(clicked()),this,SLOT(showquestion()));
    connect(submit,SIGNAL(clicked()),this,SLOT(showjudge_confirm()));
    connect(file,SIGNAL(clicked()),this,SLOT(showfile()));
}

void TopBar::subTime()
{
    time--;  //剩余时间减一秒
    showTime(); //显示时间
}

void TopBar::showTime()
{
    //转换剩余时间为时，分，秒
    int m_time1;
    m_time1=time%3600;
    int m=m_time1/60;
    int s=m_time1%60;
    QString strm,strs;
    strm.setNum(m);
    strs.setNum(s);
    timelabel->setText("考试剩余时间："+strm+":"+strs);
    if(time==600)
    {
//       trayicon=new QSystemTrayIcon(this);
       trayicon->showMessage(QString("快没时间啦!!!"),QString("还剩10分钟"));

    }
    if(time==0)
    {
        timer->stop();
        QMessageBox::information(this,"提示","考试结束");
    }
}

void TopBar::showquestion()
{
    if(!flag)
    {
        flag=true;
        q->show();

    }
    else
    {
        flag=false;
        q->hide();
    }

}
void TopBar::showjudge()
{
    ScoreProcess *s=new ScoreProcess;
    s->show();
}
void TopBar::showjudge_confirm()
{
    switch (QMessageBox::question(this,"作答进度","是否打开评分系统？",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok)) {
    case QMessageBox::Ok:
        showjudge();
        this->close();
        q->close();
        break;

    default:
        break;
    }

}

void TopBar::showfile()
{
         QString filename;
         QFileDialog *filedialog;
         QDir dir;
         QString currentpath=dir.currentPath();
         currentpath+="\\paper\\examOffice";
         filename=filedialog->getOpenFileName(this,"file dialog",currentpath,"all files(*.*)");
        //使用默认程序打开文件
         QDesktopServices bs;
         bs.openUrl(QUrl(filename));
}

void TopBar::showwarn()
{
    if(time==600)
    {   subTime();
        QMessageBox::information(this,"考试时间","距离考试结束还有10分钟");

    }
}
