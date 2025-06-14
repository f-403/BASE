#include "widget.h"
#include "QPushButton"
#include "QProgressBar"//进度条

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QProgressBar *probar = new QProgressBar(this);
    probar->setValue(10);//初始值
    probar->setMaximumWidth(100);

    //设置按一下BUTTON， 进度就加一下
    QPushButton *btn = new QPushButton("up", this);
    btn->move(0,100);
    //qDebug() << this->size();
    connect(btn, &QPushButton::clicked, probar, [probar]()->void{
        probar->setValue(probar->value()+1);//获取当前值之后 +1
    });//设置点按钮时， 增加probar的值



}

Widget::~Widget()
{
}

