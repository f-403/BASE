#include "widget.h"
#include "QPushButton"
#include "QAbstractButton"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *b = new QPushButton("close", this);
    //信号与信号处理函数是传送函数地址
    connect(b, &QAbstractButton::clicked, this, &Widget::close);

    int test = 123,test2=456;
    //c++匿名函数
    //[可访问外部参数列表](参数)->返回值 {函数体}
    //[=], 按值获取外部所有变量， 但不能修改
    //[&], 按引用获取外部所有变量， 但能修改
    [test, &test2]()->void {
        qDebug() << "c++匿名函数测试";
        test2 = 112233;
        qDebug() << test <<test2;
    }();
}

Widget::~Widget()
{
}

