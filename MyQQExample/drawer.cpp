#include "drawer.h"
#include<QGroupBox>
#include<QVBoxLayout>
Drawer::Drawer(QWidget *parent, Qt::WindowFlags f):QToolBox(parent,f)
{
    setWindowTitle("My QQ");
    toolBtn1=new QToolButton;
    toolBtn1->setText("jack");
    toolBtn1->setIcon(QPixmap("11.png"));
    toolBtn1->setIconSize(QPixmap("11.png").size());
    toolBtn1->setAutoRaise(true);
    toolBtn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QGroupBox *groupBox1=new QGroupBox;
    QVBoxLayout *layout1=new QVBoxLayout(groupBox1);

    layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignHCenter);
    //add button
    layout1->addWidget(toolBtn1);
    //add zhanweifu
    layout1->addStretch();
    toolBtn2=new QToolButton;
    toolBtn2->setText("tom");
    toolBtn2->setIcon(QPixmap("11.png"));
    toolBtn2->setIconSize(QPixmap("11.png").size());
    toolBtn2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QGroupBox *groupBox2=new QGroupBox;
    QVBoxLayout *layout2=new QVBoxLayout(groupBox2);

    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolBtn2);

    this->addItem((QWidget*)groupBox1,("my friends"));
    this->addItem((QWidget*)groupBox2,("stranger"));
}
