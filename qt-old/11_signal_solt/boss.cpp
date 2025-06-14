#include "boss.h"
#include "QRandomGenerator" //用于生成随机数

boss::boss(QWidget *parent)
    : QWidget{parent}
{

}

boss::~boss()
{
    qDebug() << "boss释放了";
}
void boss::BossDead(){
    qDebug() << "从按扭上获得了KILL, 准备发送BossDead_signal信号到player中";
    int xp = QRandomGenerator::global()->bounded(100);
    qDebug() << xp;
    emit BossDead_signal(xp);

}

