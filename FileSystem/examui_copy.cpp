﻿#include "examui.h"

examui::examui(QWidget *parent):QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    setWindowState(Qt::WindowFullScreen);//窗口全屏
    setStyleSheet("background-image:url(:/new/prefix1/background.png)");
    //QWidget *backpix=new QWidget;
    //backpix->setAutoFillBackground(true);
   // QPalette palette;
   // QPixmap pixmap(":/new/prefix1/background.png");
   // palette.setBrush(QPalette::Window, QBrush(pixmap));
   // backpix->setPalette(palette);
   // backpix->show();
}
