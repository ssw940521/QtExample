#ifndef EXAMUI_H
#define EXAMUI_H
#include<QDialog>
#include<QLabel>
class examui : public QDialog
{
public:
    examui(QWidget *parent=0);
private:
    QLabel *labelpix;
};

#endif // EXAMUI_H
