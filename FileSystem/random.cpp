#include "random.h"

QString Random::Randomfile(QString path)
{  int count=0;
   QDir dir(path);
   QString s=dir.currentPath();
   if(!dir.exists())
   {
       return -2;
   }
   //dir.setFilter(QDir::Files|QDir::NoSymLinks);
   QFileInfoList list=dir.entryInfoList();

   int file_count=list.count();
   if(file_count<=0)
   {
       return -1;
   }

   QStringList string_list;
   for(int i=0;i<file_count;i++)
   {
       QFileInfo file_info=list.at(i);
       QString suffix=file_info.suffix();//返回后缀名
       if(QString::compare(suffix,QString("rar"),Qt::CaseInsensitive)==0)
       {
           QString name=file_info.baseName();
           string_list.append(name);
           count++;
       }
   }
   //生成随机数
   QTime t;
   t=QTime::currentTime();
   qsrand(t.msec());
   int n=qrand()%count;
   QString fileStr=string_list.at(n);

   return fileStr;
}

QString Random::Choosetxt(QString path, QString Compare)
{
    QDir dir(path);
    QFileInfoList list=dir.entryInfoList();
    int file_count=list.count();
    QStringList string_list;
    for(int i=0;i<file_count;i++)
    {
        QFileInfo file_info=list.at(i);
        QString name=file_info.baseName();
        if(QString::compare(name,Compare,Qt::CaseInsensitive)==0)
        {
            QString absolute_file_path=file_info.fileName();
            string_list.append(absolute_file_path);
        }
    }
    return string_list.at(0);
}
