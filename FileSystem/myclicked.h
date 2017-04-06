#ifndef MYCLICKED_H
#define MYCLICKED_H
#include<QObject>
class myclicked:public QObject
{
    Q_OBJECT
  signals:
    void sendpath(QString path);

};

#endif // MYCLICKED_H
