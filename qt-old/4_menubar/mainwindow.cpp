#include "mainwindow.h"
#include "QMenuBar"
//菜单栏

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *menubar = new QMenuBar();//在这里加this也行， 但效果不一样
    this->setMenuBar(menubar);//添加菜单到windows上
    //创建好菜单，并设置父窗口为mainwindows
    //在menubar栏上添加东西
    QMenu *setting = menubar->addMenu("设置");//准备为它下面添加子菜单,//在设置下面再添加东西
    setting->addMenu("代理")->addMenu("主题");//这是在代理的里面一层添加东西
    setting->addMenu("其他");

    //在设置同一层添加东西
    setting->addAction("在'设置同一层'");



    QMenu* filesetting =menubar->addMenu("文件操作");
    //以'文件操作'为主， 在同一列添加东西
    filesetting->addAction("打开");
    filesetting->addSeparator();//添加一个分隔符
    filesetting->addAction("新建");
    QMenu* filesetting_othersetting = filesetting->addMenu("其他操作")->addMenu("自带操作");//在自带操作下面再添加东西
    filesetting_othersetting->addAction("A");
    filesetting_othersetting->addAction("B");

    //**
    // *  上下级关系图
    // *  先添加QMenuBar到主窗口
    // *  1. 你要在QMenuBar上添加菜单的话， 要在QMenuBar里addMenu
    // *  2. 你要在每一栏的里面添加东西，
    // *
    // *  QMenuBar(QMenuBar) <-返回QMenu
    // *          addMenu -> QMenu(QMenu1) <-返回QMenu                -> QMenu(QMenu2)
    // *                  -> addAction(QMenu的方法)                   -> QMenu(QMenu3)   -> QMenu(QMenu4)
    // *                   -> addAction(QMenu的方法)                                     -> addAction(QMenu的方法)
    // *                                                                                -> addAction(QMenu的方法)
    // *
    // *
    // * /

}

MainWindow::~MainWindow()
{
}

