
#include <QApplication>
#include<uidesign.h>
#include<examuiSign.h>
#include<question.h>
#include<topbar.h>
#include<random.h>
#include<scoreprocess.h>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uidesign w;
    w.show();
//    Random *file=new Random;
//    QDir dir;
//    QString currentpath=dir.currentPath();
//    currentpath+="\\paper";
//    QString filepath=file->Randomfile(currentpath);
//    QString number_of_paper=filepath.right(2);
//    QString excel="Excel"+number_of_paper;
//    QString excel_path=file->Choosetxt(currentpath,excel);
//    qDebug()<<filepath;
//    qDebug()<<excel_path;


    return a.exec();
}
