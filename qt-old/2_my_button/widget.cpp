#include "widget.h"
#include "mybutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mybutton *mybtn = new mybutton();
    mybtn->setText("mybtn");
    mybtn->setParent(this);
    mybtn->show();

    //注意， 你自已创建的类虽灰继承了PUshButton,但是构造函数与析构函数没有继承
    mybutton *mybtn2 = new mybutton("2", this);
    mybtn2->move(100,200);
    mybtn2->show();
}

Widget::~Widget()
{
}

