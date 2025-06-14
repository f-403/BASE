#include "widget.h"
#include "Boss.h"
#include "QPushButton"


//自定义信号与信号处理函数
//我们可以自定义自已的， 或重写自带的

/*

  1.槽定义(信号处理函数)
    1.1 有函数声明且要实现
    1.2 返回值 为 void
    1.3 可带参可重载, 参数是从信号来的
  2.信号
    2.1 只要声明不要实现
    2.2 返回值 为 void
    2.3 可带参可重载, 参数是从信号来的
 */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    boss *b = new boss;
    //设置一下父路， 放进对象树
    b->setParent(this);

    QPushButton *btn = new QPushButton("kill", this);
    //点btn时， 打印BOSS死了
    connect(btn, &QPushButton::clicked, b, &boss::BossDeadSlot);

    //测试自定义信号
    //connect(btn, &QPushButton::Dead, b, &boss::BossDeadSlot);
    qDebug() << &Widget::Dead_singal;



}

Widget::~Widget()
{
}


