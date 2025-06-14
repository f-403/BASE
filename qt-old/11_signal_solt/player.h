#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include "QLabel"

class player : public QWidget
{
    Q_OBJECT
public:
    explicit player(QWidget *parent = nullptr);
    ~player();
signals:
    void update_to_widget(int);
public slots:
    void Player_getxp(int);//用于打印获取到的数据

};

#endif // PLAYER_H
