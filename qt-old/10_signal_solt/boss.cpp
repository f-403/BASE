#include "boss.h"

Boss::Boss(QWidget *parent)
    : QWidget{parent}
{


}
void Boss::Boss_send_message(){
    //这个函数在这里主要是用来收到按钮信号后， 广播信号出去， 好让widget收到
    qDebug() << "i send the signal";
    emit send_s();//广播信号出去。
}
