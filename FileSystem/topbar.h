#ifndef TOPBAR_H
#define TOPBAR_H
#include<QDialog>
#include<QApplication>
#include<QDesktopWidget>
#include<QLabel>
#include<QPushButton>
#include<QTimer>
#include<QString>
#include<QHBoxLayout>
#include<question.h>
#include<QWidget>
#include<QCloseEvent>
#include<QMessageBox>
#include<QFileDialog>
#include<QDesktopServices>
#include<QSystemTrayIcon>
class TopBar : public QDialog
{
    Q_OBJECT
public:
    TopBar(QWidget *parent=0);

private:
    QLabel *label;
    QLabel *timelabel;
    QPushButton *file;
    QPushButton *showq;
    QPushButton *process;
    QPushButton *help;
    QPushButton *submit;
    QTimer *timer;
    QSystemTrayIcon *trayicon;
    QHBoxLayout *mainLayout;
    int time;
    question *q;
    bool flag;

private slots:
    void subTime();
    void showTime();
    void showquestion();
    void showjudge_confirm();
    void showjudge();
    void showfile();
    void showwarn();

};

#endif // TOPBAR_H
