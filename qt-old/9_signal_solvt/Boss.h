#ifndef BOSS_H
#define BOSS_H

#include <QWidget>

class boss : public QWidget
{
public:
    //explicit 使参数不能自动转换
    explicit boss(QWidget *parent = nullptr);

 //signals下面写自定义信号， 只声明不实现
signals:
    void Dead_signal();//定义一个信号

//下面自定义槽函数， 注意格式
public slots:
    void BossDeadSlot();

};

#endif // BOSS_H
