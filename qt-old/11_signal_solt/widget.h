#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "player.h"
#include "boss.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void closeEvent(QCloseEvent *event);
public slots:
    void get_score_and_update_label(int);
};
#endif // WIDGET_H
