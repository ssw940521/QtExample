#include "uidesign.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

uidesign::uidesign(QWidget *parent) : QDialog(parent)
{
      setWindowTitle("MS Office考试程序");
      setWindowIcon(QIcon(":/Icon/user.png"));
//      this->setFixedSize(300,100);
//      this->setStyleSheet ("background-color: rgb(0,0,0);color: rgb(255,255,255);");
//      this->setStyleSheet ("venus--TitleBar {background-color: rgb(0,0,0);color: rgb(255,255,255);}");
//      this->setStyleSheet ("border:2px groove gray;border-radius:10px;padding:2px 4px;");
//      this->setWindowOpacity(0.7);//设置窗口半透明

      startexam=new QPushButton;
      startexam->setText("开始考试");
      startexam->setAutoFillBackground(true);
      startexam->setFixedSize(100,20);
      startexam->setStyleSheet("QPushButton{border-image: url(:/Icon/normal);}"
                                    "QPushButton:hover{border-image: url(:/Icon/hover);}"
                                    "QPushButton:pressed{border-image: url(:/Icon/push);}");

      mainLayout=new QGridLayout(this);
      mainLayout->addWidget(startexam,0,0);

      connect(startexam,SIGNAL(clicked()),this,SLOT(startExam()));

}
//调出解压缩对话框
void uidesign::showFileSystem()
{
    Dialog *d=new Dialog();
    d->show();
}

void uidesign::startExam()
{
    examui *exam=new examui();
    exam->show();

    this->hide();
}

void uidesign::closeEvent(QCloseEvent *event)
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
