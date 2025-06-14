#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//重写函数
protected:
    void contextMenuEvent(QContextMenuEvent *event);//这是右键事件， 在里面添加菜单即可实现右键菜单功能

};
#endif // MAINWINDOW_H
