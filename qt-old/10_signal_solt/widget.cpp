#include "widget.h"
#include "QPushButton"
#include "boss.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    //定义一个按钮， 点下去时， 调用一个函数， 这个函数用来发送信号， 之后connet连接， 当connect收到相应的函数时处理相应事件
    QPushButton *btn = new QPushButton("send", this);
    btn->move(0,100);//这里移动一下， 要不会让后面的boss类挡住

    //定义一个按钮， 用来调用boss发送信号:emit, 之后connect连接到其他事件， 这里是widget中的print_message
    Boss *boss = new Boss(this);

    connect(btn, &QPushButton::clicked, boss,&Boss::Boss_send_message);//这里主要是为了调用sloat函数， 用于广翻信号， 好让下面的connect触发信号
    //广播信号出去， 让widget接收吧
    connect(boss, &Boss::send_s, this, &Widget::print_message);
    //如果你直接写上面这一条的话， 信号是有， 但你触 发不了， 所以， 要绕一下， 点按钮， boss调用它的信号处理函数来emit广播信号出来， 之后第二个connect在等待的，
    //接到到send_s的话， 调用widget自定义的信号处理函数再处理。
}

Widget::~Widget()
{
}
void Widget::print_message(){
    qDebug()<< "I GET THE signal....";

}
