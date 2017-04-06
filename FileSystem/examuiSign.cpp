#include "examuiSign.h"
#include<QTextCodec>
#include<QDebug>
#include<topbar.h>
#include<QApplication>
#include<QRect>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
examui::examui(QWidget *parent):QDialog(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    setWindowState(Qt::WindowFullScreen);//窗口全屏

    mainLayout=new QGridLayout(this);//背景布局
    signLayout=new QGridLayout();
    this->setAutoFillBackground(true);

    QPalette palette;
    QPixmap pixmap(":/background/back");//设置背景图

    palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));//设置图片拉伸
    this->setPalette(palette);

    signin=new QWidget;//登录窗口
    signin->setWindowFlags(Qt::FramelessWindowHint);
    signLayout=new QGridLayout(signin);//登陆布局
    num=new QLabel;
    num->setText("输入准考证号");
    title=new QLabel;
    title->setText("MS Office二级考试");
    title->setGeometry(rect().x()+50,rect().y()+50,200,20);
    title->setParent(this);
    numEdit=new QLineEdit;
    next1=new QPushButton;
    next1->setText("下一步");
    quitBtn=new QPushButton();
    quitBtn->setText("退出程序");
    signin->setAutoFillBackground(true);
    palette.setColor(QPalette::Background,QColor("grey"));
    signin->setPalette(palette);
    signin->setFixedSize(200,200);
    //signLayout->addWidget(num,0,0);
    signLayout->addWidget(numEdit,1,0);
    signLayout->addWidget(next1,2,0);
    mainLayout->addWidget(signin,0,0);
    quitBtn->setGeometry(1800,20,70,20);
    quitBtn->setParent(this);
    //手动设置位置
    num->setGeometry(50,10,100,20);
    num->setParent(signin);



    //确认窗口
    confirm=new QWidget;
    confirm->setWindowFlags(Qt::FramelessWindowHint);
    returnBtn=new QPushButton;
    returnBtn->setText("重新输入准考证号");

    next2=new QPushButton;
    next2->setText("下一步");
    confirmLabel=new QLabel;
    confirmLabel->setText("确认准考证号信息");
    confirmLabel->setScaledContents(true);
    IDLabel=new QLabel;
    backlabel=new QLabel;
    //添加确认窗口的背景图片
    /*QImage *p=new QImage;
    p->load(":/background/background1");
    backlabel->setPixmap(QPixmap::fromImage(*p));
    backlabel->setGeometry(1,1,500,500);
    backlabel->setParent(confirm);
    backlabel->setScaledContents(true);*/
    confirmLayout=new QGridLayout(confirm);
    confirmLayout->setMargin(5);
    confirm->setAutoFillBackground(true);
    confirm->setPalette(palette);
    confirm->setFixedSize(200,200);
    confirmLayout->addWidget(confirmLabel,0,0);
    confirmLayout->addWidget(IDLabel,1,0);
    confirmLayout->addWidget(returnBtn,2,0);
    confirmLayout->addWidget(next2,2,1);
    //confirmLabel->setGeometry(60,50,100,20);
   // confirmLabel->setParent(confirm);
   // IDLabel->setGeometry(60,100,100,20);
   // IDLabel->setParent(confirm);
   // next2->setGeometry(120,150,50,25);
   // next2->setParent(confirm);
   // returnBtn->setGeometry(20,150,100,25);
   // returnBtn->setParent(confirm);
    mainLayout->addWidget(confirm,0,0);
    confirm->hide();

    //考试信息
    info=new QWidget;\
    info->setWindowFlags(Qt::FramelessWindowHint);
    check1=new QCheckBox;
    check1->setText("已阅读上述要求");
    testInfo=new QLabel;
    testInfo->setText("二级 MS Office高级应用");
    testInfoLayout=new QGridLayout(info);
    next3=new QPushButton;
    next3->setText("下一步");
    next3->setEnabled(false);
    next3->setFixedWidth(100);
    info->setFixedSize(200,200);
    backlabel1=new QLabel;
    QImage *p1=new QImage;
   // info->setAutoFillBackground(true);
    p1->load(":/background/background1");
    backlabel1->setPixmap(QPixmap::fromImage(*p1));
    testInfoLayout->addWidget(backlabel1,0,0,3,1);
    backlabel1->setScaledContents(true);
    testInfoLayout->addWidget(testInfo,0,0);
    testInfoLayout->addWidget(check1,1,0);
    testInfoLayout->addWidget(next3,2,0);

    mainLayout->addWidget(info,0,0);
    info->hide();

    //连接前进与返回键
    connect(next1,SIGNAL(clicked()),this,SLOT(turnToNext()));
    connect(returnBtn,SIGNAL(clicked()),this,SLOT(returnToSign()));
    connect(next2,SIGNAL(clicked()),this,SLOT(turnToInfo()));
    connect(check1,SIGNAL(clicked()),this,SLOT(buttonable()));
    connect(check1,SIGNAL(clicked()),this,SLOT(checkboxcancel()));
    connect(next1,SIGNAL(clicked()),this,SLOT(showID()));
    connect(next3,SIGNAL(clicked()),this,SLOT(showtopbar()));
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(quit()));
}

void examui::turnToNext()
{
    signin->hide();
    confirm->show();

}

void examui::returnToSign()
{
    confirm->hide();
    signin->show();
}

void examui::turnToInfo()
{
    confirm->hide();
    info->show();
}

void examui::buttonable()
{
    if(check1->isChecked())
        next3->setEnabled(true);
    else
        next3->setEnabled(false);

}
void examui::checkboxcancel()
{
    if(check1->isChecked())
        check1->setChecked(1);
    else
        return;
}

void examui::showID()
{
    QString id=numEdit->text();
    IDLabel->setText("准考证号："+id);

}

void examui::showtopbar()
{   this->close();
    TopBar *t=new TopBar();
    t->show();

}

void examui::quit()
{
    this->close();
}

