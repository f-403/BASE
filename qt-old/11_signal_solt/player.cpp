#include "player.h"


player::player(QWidget *parent)
    : QWidget{parent}
{

}

player::~player(){
    qDebug() << "player 释放了";
}
void player::Player_getxp(int xp) {
    qDebug() << "I get" << xp << "xp";
    //把这个传到widget中并更新
    emit update_to_widget(xp);

}
