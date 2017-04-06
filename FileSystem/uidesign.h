#ifndef UIDESIGN_H
#define UIDESIGN_H
#include<unpressdialog.h>
#include<QMainWindow>
#include<examuiSign.h>
#include <QCloseEvent>
#include<QIcon>
class uidesign : public QDialog
{
    Q_OBJECT
public:
    explicit uidesign(QWidget *parent = 0);
private:
      QPushButton *startexam;
      QGridLayout *mainLayout;
      void closeEvent(QCloseEvent *event);
signals:

public slots:
      void showFileSystem();
      void startExam();

};

#endif // UIDESIGN_H
