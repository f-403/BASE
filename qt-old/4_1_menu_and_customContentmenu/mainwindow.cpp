#include "mainwindow.h"
#include "QAction"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //右键菜单方式1
    //添加QAction, 之后设置setContextMenuPolicy属性
    QAction *file = new QAction("file");
    QAction *editor = new QAction("Editor");
    this->setContextMenuPolicy(Qt::ActionsContextMenu);//有多种值, 书p145页有说明
    this->addAction(file);
    this->addAction(editor);
    //this->customContextMenuRequested(QCursor::pos());//不用添加这一句也行
    //添加信号处理
    connect(file, &QAction::triggered, this, [=]()->void{
        QFileDialog *log = new QFileDialog();
        log->getOpenFileName(this, "打开文件", ".", "*.*");
    });


}

MainWindow::~MainWindow()
{
}

