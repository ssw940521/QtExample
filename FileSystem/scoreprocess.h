#ifndef SCOREPROCESS_H
#define SCOREPROCESS_H
#include<QDialog>
#include<QPushButton>
#include<QLabel>
#include<QGridLayout>
#include<question.h>
#include<QStackedWidget>
#include<QTextEdit>
class ScoreProcess : public QDialog
{
    Q_OBJECT
public:
    ScoreProcess(QWidget *parent=0);
private:
    QPushButton *word;
    QPushButton *excel;
    QPushButton *ppt;
    QPushButton *quit;
    QLabel *score;
    QGridLayout *mainLayout;
    QStackedWidget *stack;
    QTextEdit *wordtext;
    QTextEdit *exceltext;
    QTextEdit *ppttext;

private slots:
    void wordBtn();
    void excelBtn();
    void pptBtn();
};

#endif // SCOREPROCESS_H
