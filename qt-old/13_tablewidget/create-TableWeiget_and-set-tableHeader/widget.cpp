#include "widget.h"
#include "QVBoxLayout"
#include "QPushButton"
#include "QTableWidget"
#include "QHeaderView"
#include "QTableWidgetItem"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vblayout = new QVBoxLayout();//添加布局， 要不表格不会自动扩张

    QTableWidget *table = new QTableWidget();

    QStringList header;
    header << "ID" << "URL" << "IP" << "类型" << "OS" << "TIME" << "备注" << "STATUS";
    table->setColumnCount(8);
    table->setHorizontalHeaderLabels(header);
    vblayout->addWidget(table);
    table->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);//备注那一列占用空间多一些




    this->setLayout(vblayout);
}

Widget::~Widget()
{
}

