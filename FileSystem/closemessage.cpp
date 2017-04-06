#include "closemessage.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
closemessage::closemessage()
{

}

void closemessage::closeEvent(QCloseEvent *event)
{
    switch( QMessageBox::information(this,("提示"),("你确定退出该软件?"),("确定"), ("取消"),0,1))
        {
        case 0:
            event->accept();
            break;
        case 1:
        default:
            event->ignore();
            break;
        }
}
