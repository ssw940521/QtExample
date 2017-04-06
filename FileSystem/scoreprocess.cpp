#include "scoreprocess.h"
#include<QLibrary>
#include<QDebug>
#include<QDir>
#include<QByteArray>
#include<QCoreApplication>
#include<question.h>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
ScoreProcess::ScoreProcess(QWidget *parent):QDialog(parent)
{
     //界面布局
     setWindowTitle("评分系统");
     mainLayout=new QGridLayout(this);
     score=new QLabel;
     word=new QPushButton;
     excel=new QPushButton;
     ppt=new QPushButton;
     stack=new QStackedWidget;
     wordtext=new QTextEdit;
     exceltext=new QTextEdit;
     ppttext=new QTextEdit;
     wordtext->setReadOnly(true);
     exceltext->setReadOnly(true);
     ppttext->setReadOnly(true);
     stack->addWidget(wordtext);
     stack->addWidget(exceltext);
     stack->addWidget(ppttext);

     mainLayout->addWidget(score,0,0);
     mainLayout->setColumnStretch(0,2);
     mainLayout->addWidget(word,0,1);
     mainLayout->addWidget(excel,0,2);
     mainLayout->addWidget(ppt,0,3);
     mainLayout->addWidget(stack,1,0,1,4);
//     mainLayout->addWidget(wordtext,1,0,1,4);
//     mainLayout->addWidget(exceltext,1,0,1,4);
//     mainLayout->addWidget(ppttext,1,0,1,4);
//     ppttext->hide();
//     exceltext->hide();
     //参数
     QByteArray arr= QCoreApplication::applicationDirPath().toLatin1();//先将QString转换为QByteArray
     char *exepath=arr.data();//第一个参数：程序所在的位置
     qDebug()<<exepath;
     QString numstr=question::returnnum();
     int num=numstr.toInt();//第三个参数：试卷的编号

     //答案路径
     QDir dir;
     QString strpath=dir.currentPath()+"\\paper\\examOffice";
     QByteArray arrpath=strpath.toLatin1();
     char *answerpath=arrpath.data();
     //分数
     double getscore;
     double totalscore;
     char result[8192*5];
     //加载dll
     typedef bool (*FUN)(const char*,int,int,const char*,double*,double*,char*);
     QLibrary lib("OfficeScore.dll");
     if(lib.load())
     {
         qDebug()<<"load ok!";
         FUN OfficeScore=(FUN)lib.resolve("OfficeScoreProcess");
         if (OfficeScore)
         {
             qDebug()<<"load score is ok!";
             qDebug()<<num;
             int total=0;
             OfficeScore(exepath,1,num,answerpath,&totalscore,&getscore,result);
             word->setText("WORD得分\n"+QString::number(getscore)+"\\"+QString::number(totalscore));
             qDebug()<<total;

             QString str = QString::fromLocal8Bit(result);
             qDebug()<<str;
             wordtext->setText(str);
             total+=getscore;
             OfficeScore(exepath,2,num,answerpath,&totalscore,&getscore,result);
             excel->setText("EXCEL得分\n"+QString::number(getscore)+"\\"+QString::number(totalscore));
             total+=getscore;
              qDebug()<<total;
              str=QString::fromLocal8Bit(result);
              exceltext->setText(str);
             OfficeScore(exepath,3,num,answerpath,&totalscore,&getscore,result);
             ppt->setText("PPT得分\n"+QString::number(getscore)+"\\"+QString::number(totalscore));
             total+=getscore;
             qDebug()<<total;
             str=QString::fromLocal8Bit(result);
             ppttext->setText(str);
             score->setText("总分为："+QString::number(total));
         }
     }
     else
     {
         qDebug()<<"load error";
     }

     //切换堆栈窗口
     connect(word,SIGNAL(clicked()),this,SLOT(wordBtn()));
     connect(excel,SIGNAL(clicked()),this,SLOT(excelBtn()));
     connect(ppt,SIGNAL(clicked()),this,SLOT(pptBtn()));
}

void ScoreProcess::wordBtn()
{

    stack->setCurrentIndex(0);
}

void ScoreProcess::excelBtn()
{
    stack->setCurrentIndex(1);
}

void ScoreProcess::pptBtn()
{
    stack->setCurrentIndex(2);

}
