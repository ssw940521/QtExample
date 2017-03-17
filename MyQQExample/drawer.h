#ifndef DRAWER_H
#define DRAWER_H
#include<QToolBox>
#include<QToolButton>

class Drawer : public QToolBox
{
    Q_OBJECT
public:
    Drawer(QWidget *parent=0,Qt::WindowFlags f=0);
private:
    QToolButton *toolBtn1;
    QToolButton *toolBtn2;
    QToolButton *toolBtn3;
};

#endif // DRAWER_H
