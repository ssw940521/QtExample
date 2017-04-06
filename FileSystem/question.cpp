#include "question.h"
#include<QFile>
#include<QString>
#include<random.h>
#include<QFileDialog>
#include<QProcess>
#include<QDesktopServices>
#include<QUrl>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
static QString number_of_paper;
question::question(QWidget *parent):QDialog(parent)
{
    setWindowTitle("MS office题目");
    this->resize(QSize(500,500));
    //添加最大化、最小化按钮
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinMaxButtonsHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    //选择一个随机的试题包
    Random *ran=new Random;//随机选择试题包
    QDir dir;
    currentpath=dir.currentPath();
    currentpath+="\\paper";
    filepath=ran->Randomfile(currentpath);
    number_of_paper=filepath.right(2);//获取文件尾部的序号
    QString excel="Excel"+number_of_paper;
    QString word="Word"+number_of_paper;
    QString ppt="Powerpoint"+number_of_paper;
    //txt文件的路径
    QString excel_path=ran->Choosetxt(currentpath,excel);
    QString word_path=ran->Choosetxt(currentpath,word);
    QString ppt_path=ran->Choosetxt(currentpath,ppt);
    //解压缩试题包到当前目录
    QString unpresspath=currentpath+"\\"+filepath+".rar";
    Dialog *unpress=new Dialog;
    unpress->unpress(unpresspath);
    //所有标签页的按钮
    word1=new QPushButton;
    word1->setText("启动word");
    excel1=new QPushButton;
    excel1->setText("启动excel");
    ppt1=new QPushButton;
    ppt1->setText("启动ppt");
    word2=new QPushButton;
    word2->setText("启动word");
    excel2=new QPushButton;
    excel2->setText("启动excel");
    ppt2=new QPushButton;
    ppt2->setText("启动ppt");
    word3=new QPushButton;
    word3->setText("启动word");
    excel3=new QPushButton;
    excel3->setText("启动excel");
    ppt3=new QPushButton;
    ppt3->setText("启动ppt");

    startExam=new QPushButton;
    startExam->setText("开始考试");
    file1=new QPushButton;
    file1->setText("文件");
    file1->setFixedWidth(100);
    file2=new QPushButton;
    file2->setText("文件");
    file2->setFixedWidth(100);
    file3=new QPushButton;
    file3->setText("文件");
    file3->setFixedWidth(100);
    //4个tab的文本显示标签
    Readtxt *readt=new Readtxt;
    Text1=new QTextEdit;
    Text1->setReadOnly(true);
    //将读取的文本放入textedit中

    Text2=new QTextEdit;
    Text2->setReadOnly(true);
    Text2->setText(readt->Read_txt("\paper\\"+word_path));
    Text3=new QTextEdit;
    Text3->setText(readt->Read_txt("\paper\\"+excel_path));
    Text4=new QTextEdit;
    Text4->setText(readt->Read_txt("\paper\\"+ppt_path));
    //标签&布局
    tabbar=new QTabWidget;
    mainLayout=new QGridLayout;
    this->setLayout(mainLayout);
    mainLayout->addWidget(tabbar,1,1);

    front=new QCheckBox;
    front->setText("set to front");
    mainLayout->addWidget(front,0,1);
//    QTabBar::tab{border-bottom-color: #C2C7CB;
//                 border-top-left-radius: 0px;
//                 border-top-right-radius: 0px;
//                 max-width: 75px; min-width:75px; min-height:25px;
//                 font:14px Times New Roman;
//                     padding: 0px;
//                     }
    tabbar->setStyleSheet("QTabWidget::pane{border-width:1px;border-color:rgb(48, 104, 151);\
                          border-style: outset;background-color: rgb(132, 171, 208);\
                          background: transparent;}\QTabBar::tab{border-bottom-color: #C2C7CB;\
                                                                border-top-left-radius: 0px;\
                                                                border-top-right-radius: 0px;\
                                                                max-width: 75px; min-width:75px; min-height:25px;\
                                                                font:14px Times New Roman;\
                                                                    padding: 0px;\
                                                                    }");
    //四个标签的页面
    first=new QWidget;
    second=new QWidget;
    third=new QWidget;
    forth=new QWidget;
    //每个标签的页面布局
    Layout1=new QVBoxLayout();
    Layout2=new QVBoxLayout();
    Layout3=new QVBoxLayout();
    Layout4=new QVBoxLayout();
    first->setLayout(Layout1);
    second->setLayout(Layout2);
    third->setLayout(Layout3);
    forth->setLayout(Layout4);
    //放置按钮的布局
    hLayout1=new QHBoxLayout();
    hLayout2=new QHBoxLayout();
    hLayout3=new QHBoxLayout();
    //first tab
    Layout1->addWidget(Text1);
    Layout1->addWidget(startExam);
    tabbar->addTab(first,"选择题");
    //second tab
    Layout2->addLayout(hLayout1);
    Layout2->addWidget(Text2);
    Layout2->addWidget(file1);
    hLayout1->addWidget(word1);
    hLayout1->addWidget(excel1);
    hLayout1->addWidget(ppt1);
    hLayout1->addStretch();
    tabbar->addTab(second,"字处理");
    //third tab
    Layout3->addLayout(hLayout2);
    Layout3->addWidget(Text3);
    Layout3->addWidget(file2);
    hLayout2->addWidget(word2);
    hLayout2->addWidget(excel2);
    hLayout2->addWidget(ppt2);
    hLayout2->addStretch();
    tabbar->addTab(third,"电子表格");
    //forth tab
    Layout4->addLayout(hLayout3);
    Layout4->addWidget(Text4);
    Layout4->addWidget(file3);
    hLayout3->addWidget(word3);
    hLayout3->addWidget(excel3);
    hLayout3->addWidget(ppt3);
    hLayout3->addStretch();
    tabbar->addTab(forth,"演示文稿");
    //连接槽函数
    connect(file1,SIGNAL(clicked()),this,SLOT(openfile()));
    connect(file2,SIGNAL(clicked()),this,SLOT(openfile()));
    connect(file3,SIGNAL(clicked()),this,SLOT(openfile()));
}

void question::openfile()
{    QString filename;
     QFileDialog *filedialog;
     QString studentfile=currentpath+"\\examOffice";
     filename=filedialog->getOpenFileName(this,"file dialog",studentfile,"all files(*.*)");
    //使用默认程序打开文件
     QDesktopServices bs;
     bs.openUrl(QUrl(filename));
}

QString question::returnnum()
{
    return number_of_paper;
}

void question::closeEvent(QCloseEvent *event)
{

    switch( QMessageBox::information(this,"MS office","确定要退出程序吗?","是","否",0,1)  )
    {
    case 0:
        event->accept();
        break;
    case 1:
    default:
        event->ignore();
        break;
    }
}
