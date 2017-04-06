#ifndef CLOSEMESSAGE_H
#define CLOSEMESSAGE_H
#include <QCloseEvent>
#include<QMessageBox>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
class closemessage
{
public:
    closemessage();
private:
    void closeEvent(QCloseEvent *event);
};

#endif // CLOSEMESSAGE_H
