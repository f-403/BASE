#include "mainwindow.h"
#include "QHeaderView"
#include "QTableWidget"
#include "QHBoxLayout"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //下面这个代码块用于设置表格自适应窗口的变化
    //-- 适配不同大小分辨率的屏幕
    //***************************************************************************
    //这个控件新建用来绕开mainwindow的自带layout， mainwindow本身自带有layout, 而widget没有自带layout
    QWidget *widget = new QWidget(this);
    //新建一个表格
    QTableWidget *Table = new QTableWidget(100,8,widget);
    QStringList title;
    title << "ID" << "URL" << "IP" << "脚本类型" << "os" << "备注" << "添加时间" << "状态";
    Table->setHorizontalHeaderLabels(title);
    //表列随着表格变化而自适应变化
    Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //表行随着表格变化而自适应变化
    //Table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Table->setSelectionBehavior(QTableWidget::SelectRows);//只一行一行的选
    //将widget设置为窗口的中心控件
    Table->setShowGrid(false);//是否显示线条
    setCentralWidget(widget);
    //添加布局器     -- 垂直
    QHBoxLayout *windowLayout = new QHBoxLayout;
    windowLayout->addWidget(Table);
    widget->setLayout(windowLayout);
}

MainWindow::~MainWindow()
{
}
