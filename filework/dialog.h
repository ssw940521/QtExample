#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include<QFile>
#include<QFileDialog>
#include<QString>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QPushButton *readfile1;
    QPushButton *readfile2;
    QPushButton *copyfileBtn;
    QLineEdit *fileLineEdit;
    QLineEdit *showfilename;
    QLineEdit *copydir;
    QGridLayout *mainlayout;
private slots:
    void showFile();
    void Choosedir();
    void Copyfile();


};

#endif // DIALOG_H
