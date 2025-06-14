#include "widget.h"
#include "QTextEdit"
#include "QResizeEvent"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextEdit *txt = new QTextEdit("write here", this);
    qDebug() << this->geometry().height();//打印长宽可以用这个函数
    qDebug() << this->geometry().width();//打印长宽可以用这个函数
    //
    if (this->geometry().width() > 800 ){ //这个不能改，  好像要用事件， 不是信号， 目前是获取刚打开运行时的宽度，达多多少就民入。一次性
        txt->setText("达到大于800宽度，文字自动改了");
    }


}

Widget::~Widget()
{
}

