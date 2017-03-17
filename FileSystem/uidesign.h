#ifndef UIDESIGN_H
#define UIDESIGN_H
#include<dialog.h>
#include<QMainWindow>

class uidesign : public QDialog
{
    Q_OBJECT
public:
    explicit uidesign(QWidget *parent = 0);
private:
      QPushButton *startexam;
      QGridLayout *mainLayout;
signals:

public slots:
      void showFileSystem();
};

#endif // UIDESIGN_H
