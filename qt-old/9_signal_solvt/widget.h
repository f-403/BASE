#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals: //它的子类也能用这个信号
    void Dead_singal();//定义一个信号
};
#endif // WIDGET_H
