#include "readtxt.h"

QString Readtxt::Read_txt(QString filepath)
{
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QTextStream in(&file);
    QString data;
    while (!in.atEnd())
           {
               QString line = in.readLine();
               line = line + "\n";
               data = data + line;
           }
    file.close();
    return data;
}
