#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
//定义一个函数， 用于处理接收到信号时调用
public slots:
    void print_message();
};
#endif // WIDGET_H
