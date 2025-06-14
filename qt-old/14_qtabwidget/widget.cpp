#include "widget.h"
#include "QPushButton"
#include "QVBoxLayout"
#include "QTabWidget"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton("btn");
    QVBoxLayout *v = new QVBoxLayout();
    QTabWidget *tab = new QTabWidget();
    tab->addTab(new QWidget(), "new1");
    tab->addTab(new QWidget(), "new2");
    tab->addTab(new QWidget(), "new3");
    v->addWidget(btn);
    v->addWidget(tab);


    this->setLayout(v);
}

Widget::~Widget()
{
}

