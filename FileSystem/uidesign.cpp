#include "uidesign.h"

uidesign::uidesign(QWidget *parent) : QDialog(parent)
{
      setWindowTitle("uidesign");
      this->setFixedSize(200,50);
      startexam=new QPushButton;
      startexam->setText("start");
      mainLayout=new QGridLayout(this);

      mainLayout->addWidget(startexam,0,0);

      connect(startexam,SIGNAL(clicked()),this,SLOT(showFileSystem()));

}

void uidesign::showFileSystem()
{
    Dialog *d=new Dialog();
    d->show();
}
