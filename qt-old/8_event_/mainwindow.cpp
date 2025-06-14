#include "mainwindow.h"
#include "QTableWidget"
#include "QCloseEvent"
#include "QMessageBox"
#include "QEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


}

MainWindow::~MainWindow()
{
}
void MainWindow::closeEvent(QCloseEvent *event){
    //event->clone();这是对事件做出的响应， 可以判断
    //直接重写就行， 会自动调用
    qDebug() << "窗口被关掉了";
    auto result = QMessageBox::question(this, "TITLE","this is a test");
    qDebug() << result;//yes -> QMessageBox::YES , no-> QMessage::NO

}
void MainWindow::resizeEvent(QResizeEvent *event){
    qDebug()<< this->size().height();//当窗口改变时会自动调用这个事件函数
    //this->oldsize(), this->size()
    qDebug() << event->size().height();
}


