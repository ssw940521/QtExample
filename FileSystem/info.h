#ifndef INFO_H
#define INFO_H
#include<QDialog>
#include<QMessageBox>
class info : public QDialog
{
    Q_OBJECT
public:
    info(QWidget *parent()=0);
    void showinfo();


};

#endif // INFO_H
