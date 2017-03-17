#include "dialog.h"
#include <QApplication>
#include<uidesign.h>
#include<examui.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     examui w;

    w.show();

    return a.exec();
}
