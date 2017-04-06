#ifndef QUESTION_H
#define QUESTION_H
#include<QDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QTabWidget>
#include<QLabel>
#include<QTextEdit>
#include<QPushButton>
#include<QCheckBox>
#include<QWidget>
#include<random.h>
#include<QDir>
#include<unpressdialog.h>
#include<readtxt.h>

class question : public QDialog
{
    Q_OBJECT
public:
    question(QWidget *parent=0);
    static QString returnnum();
    void closeEvent(QCloseEvent *event);
private:
    QTabWidget *tabbar;
    QTextEdit *Text1;
    QTextEdit *Text2;
    QTextEdit *Text3;
    QTextEdit *Text4;
    QPushButton *word1;
    QPushButton *excel1;
    QPushButton *ppt1;
    QPushButton *word2;
    QPushButton *excel2;
    QPushButton *ppt2;
    QPushButton *word3;
    QPushButton *excel3;
    QPushButton *ppt3;
    QPushButton *startExam;
    QPushButton *file1;
    QPushButton *file2;
    QPushButton *file3;
    QCheckBox *front;
    QVBoxLayout *Layout1;
    QVBoxLayout *Layout2;
    QVBoxLayout *Layout3;
    QVBoxLayout *Layout4;
    QGridLayout *mainLayout;
    QHBoxLayout *hLayout1;
    QHBoxLayout *hLayout2;
    QHBoxLayout *hLayout3;
    QWidget *first;
    QWidget *second;
    QWidget *third;
    QWidget *forth;
    QString currentpath;
    QString filepath;


private slots:
    void openfile();
};

#endif // QUESTION_H
