#ifndef BOSS_H
#define BOSS_H

#include <QWidget>


class boss : public QWidget
{
    Q_OBJECT
public:
    explicit boss(QWidget *parent = nullptr);
    ~boss();

signals:
    void BossDead_signal(int);//用于把信号发送到player中， 并传参
public slots:
    void BossDead();
};

#endif // BOSS_H
