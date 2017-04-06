#ifndef EXAMUI_H
#define EXAMUI_H
#include<QDialog>
#include<QLabel>
#include<QImage>
#include<QGridLayout>
#include<QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<unpressdialog.h>
#include<QPainter>
#include<QCheckBox>
#include<QButtonGroup>
#include<topbar.h>
#include <QCloseEvent>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
class examui : public QDialog
{
    Q_OBJECT
public:
    examui(QWidget *parent=0);
private:
    QLabel *num;
    QLabel *confirmLabel;
    QLabel *backlabel;
    QLabel *backlabel1;
    QLabel *IDLabel;
    QLabel *testInfo;
    QLabel *title;
    QLineEdit *numEdit;
    QPushButton *next1;
    QPushButton *next2;
    QPushButton *next3;
    QPushButton *returnBtn;
    QPushButton *quitBtn;
    QGridLayout *mainLayout;
    QGridLayout *signLayout;
    QGridLayout *confirmLayout;
    QGridLayout *testInfoLayout;
    QWidget *signin;
    QWidget *confirm;
    QWidget *info;
    QCheckBox *check1;


public slots:
    void turnToNext();
    void returnToSign();
    void turnToInfo();
    void buttonable();
    void checkboxcancel();
    void showID();
    void showtopbar();
    void quit();
};

#endif // EXAMUI_H
