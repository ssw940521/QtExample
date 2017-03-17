#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include<QMessageBox>
#include <QFile>
#include<info.h>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QPushButton *fileBtn;
    QPushButton *uncompressBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;

private slots:
    void showFile();
    void on_pushButton_clicked();
    void juge();
};

#endif // DIALOG_H
