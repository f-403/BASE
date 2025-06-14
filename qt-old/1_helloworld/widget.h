#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget //父类为Qwidget
{
    Q_OBJECT //支持信号与槽

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
