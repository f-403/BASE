#ifndef BOSS_H
#define BOSS_H

#include <QWidget>

class Boss : public QWidget
{
    Q_OBJECT
public:
    explicit Boss(QWidget *parent = nullptr);

signals:
    void send_s();//定义一个信号
public slots:
    void Boss_send_message();

};

#endif // BOSS_H
