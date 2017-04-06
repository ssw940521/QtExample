#ifndef RANDOM_H
#define RANDOM_H
#include<cstdlib>
#include<QString>
#include<QList>
#include<QDir>
#include<QtGlobal>
#include<QTime>
#include <QCloseEvent>
class Random
{
public:
    QString Randomfile(QString path);
    QString Choosetxt(QString path,QString Compare);

};

#endif // RANDOM_H
