#include "widget.h"
#include "QPushButton"
#include "stu.h"
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)//列表初始化， 自身创建时顺便初始化父类
{
    this->setWindowTitle("hello,world");
    this->resize(100,200);//窗口大小
    //this->setFixedSize(100,200)//设置固定大小
    QPushButton * btn = new QPushButton;
    btn->setText("ok");
    btn->setParent(this);//设置父类为当前对像， 也就是w
    btn->show();
    //css
    //btn->setStyleSheet("QPushButton{background-color:red;}");
    //创建一个学生
    Stu *s = new Stu;
    std::cout << typeid(s).name()<<std::endl;
    s->setParent(this);//让其继承一下，  设置它的父类， 当窗口关掉时， 会释放， 要不要手动释放。
    //delete s;//手动释放指针指向的空间

}

Widget::~Widget()
{
}

