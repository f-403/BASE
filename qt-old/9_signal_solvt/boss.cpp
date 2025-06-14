#include "Boss.h"

boss::boss(QWidget *parent)
    : QWidget{parent}
{

}
void boss::BossDeadSlot(){
    qDebug() << "BossDead, from boss class";
}
