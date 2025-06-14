#include "mainwindow.h"
#include "QMenuBar"
#include "QAction"
#include "QFileDialog"

//创一个右键菜单
//右键菜单为一个事件
//重写函数， 在函数里实现QMenuBar就行


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event){
    qDebug() << "右键点了一下";
    qDebug() << typeid(this).name();
    //添加一个菜单栏
    QMenu *my_menu = new QMenu(this);
    QAction *open_ = new QAction("OPEN", this);
    QAction *exit_  = new QAction("EXIT", this);
    my_menu->addAction(open_);
    my_menu->addAction(exit_); //创这两个变量目的是connect， 点相应菜单时调用相应函数

    qDebug() << open_ << exit_;
    connect(exit_, &QAction::triggered, this, &MainWindow::close); //注意， 这里要放在exec函数上面才能触 发
    connect(open_, &QAction::triggered, this, [=]()->void{//
        //这里测试打开一个文件
        QFileDialog::getOpenFileName(this, "标题这里设置", "d:", "*.*");//
    });

    my_menu->exec(QCursor::pos());//查exec文档， 这个QCursor::post是鼠标位置
    //实际中， 你还要判断鼠标在不在某个插件里， 如表格的列， 按钮里之类的。
    //像菜刀那样的工具， 要先创建一个treeview， 再利用qtmodelindex获取元素， 判断元素， 在相应元素上弹右键菜单， 如果没选中元素， 就在主界面弹出右键菜单。
}

