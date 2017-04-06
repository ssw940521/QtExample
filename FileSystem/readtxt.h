#ifndef READTXT_H
#define READTXT_H
#include<QString>
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include <QCloseEvent>
class Readtxt
{
public:
    QString Read_txt(QString filepath);
};

#endif // READTXT_H
