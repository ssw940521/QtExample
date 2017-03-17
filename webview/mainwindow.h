#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtWebView/QtWebView>
#include<QtWebView>
#include<QtWebEngine/QtWebEngine>
#include<QWebEngineView>
#include<QSettings>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent *);
private:
    Ui::MainWindow *ui;
    QWebEngineView *view;
    QSettings *set;
};

#endif // MAINWINDOW_H
