#include "info.h"

info::info(QWidget *parent):QDialog(parent)
{

}

void info::showinfo()
{
    QMessageBox::information(this,("Info"),("choose a file!"));
    return;
}
