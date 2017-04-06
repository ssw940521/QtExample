#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QDir>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    void unpress(QString path);
private:
    QPushButton *fileBtn;
    QPushButton *uncompressBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;

private slots:
    void showFile();
    void juge();


};

#endif // DIALOG_H
