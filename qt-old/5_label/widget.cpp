#include "widget.h"
#include "QLabel" //文字控件
#include "QSlider"//滑动条控件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //文字控件
    QLabel *label = new QLabel(this);
    label->setText("这文字来自label控件");

    //流动条控件
    QSlider *slider = new QSlider(this);
    slider->move(0,50);
    slider->setMaximum(100);//设置最大值
    slider->setValue(10);//设置初始值
    //将滑动条跟文字关联起来
    connect(slider, &QAbstractSlider::valueChanged, label, [label](int value)->void{
        qDebug() << value;//打印传进来的值
        label->setFont(QFont("楷书", value, QFont::Bold));//设置字体与字体大小
    });//利用一个匿名函数处理信号， 这个信号会发送一个int过来


}

Widget::~Widget()
{
}

