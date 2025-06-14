#include "widget.h"

#include <QApplication>
/*
信号与槽
connect
connect(信号发送者， 发送的信号-类中的(函数)， 信号接收者， 处理函数-类中的（槽)) ->最常用法， 还有其他重载
信号:函数声明(用户自定义)，不用实现 -> 系统大多数类都定义了信号(内置信号)
槽: 信号处理函数， 有内置的可用。自写义的话， 要声明与实现。
//另一种处理方式
connect(信号发送者， 发送的信号， 匿名处理函数)
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
