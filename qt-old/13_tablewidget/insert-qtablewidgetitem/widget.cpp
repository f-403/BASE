#include "widget.h"
#include "QVBoxLayout"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QHeaderView"
#include "QLabel"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *lay = new QVBoxLayout;
    QTableWidget *table = new QTableWidget();
    QStringList header;
    header << "1" << "2" << "status";
    table->setHorizontalHeaderLabels(header);
    table->setColumnCount(3);//注意， 要设置行数才能正常显示
    table->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);//设置第三列占用剩下的空间
    table->verticalHeader()->setHidden(true);//设置不默认显示自带的ID列
    //table->verticalHeader()->setVisible(false);以上面一行代码一样的
    table->setAlternatingRowColors(true);//设置自带有颜色分隔
    table->setSelectionBehavior(QAbstractItemView::SelectRows);//设置单击时选一行
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不允计双击时编辑

    QTableWidgetItem *data[3];//每一行有三个格子， 这里就是三个
    for(int i =0; i < 3; i++) {

        table->insertRow(table->rowCount());//插入前要先获取
        data[0] = new QTableWidgetItem("test");
        data[1] = new QTableWidgetItem("test");
        data[2] = new QTableWidgetItem("test");
        table->setItem(i,0, data[0]);
        table->setItem(i,1, data[1]);
        table->setItem(i,2, data[2]);

    }

    QLabel *label = new QLabel("0");
    lay->addWidget(label);
    connect(table, &QTableWidget::cellClicked, label, [table,label](){
        label->setText(QString::number(table->currentRow()));//获取当前选中的行号
    });
    qDebug() << table->currentRow();
    lay->addWidget(table);






    this->setLayout(lay);
}

Widget::~Widget()
{
}

