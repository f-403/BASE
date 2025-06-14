#include "widget.h"
#include "QPushButton"
#include "player.h" //载入头文件用于创建player
#include "boss.h"  //载入头文件用于创建boss

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //窗口大小
    this->setFixedSize(300,100);


    //信号函数参数可以比槽函数多， 反过来不行。
    //带参信号函数学习。
    //写一个按钮， 点一下后BOSS发送信号， 之后player接收到信号并且信号函数处理， 并打印获取得到的经验

    //定义一个BOSS一个player
    boss *b = new boss(this);//加入对象时， 自动释放
    player *u = new player(this); //

    //定义一个主界面
    QPushButton *btn = new QPushButton(this);
    btn->setText("KiLL");
    //定义BOSS信号， 有一个参数， 用于传递数据
    connect(btn, &QPushButton::clicked, b,&boss::BossDead);//调用信号处理函数

    connect(b, &boss::BossDead_signal, u, &player::Player_getxp);//传送东西过去，

    //player把数据回传并更新label
    connect(u, &player::update_to_widget, this, &Widget::get_score_and_update_label);
    QLabel *lab = new QLabel("score:", this);
    lab->setObjectName("score");//起个名字， 主要是主窗口调用信号处理函时好更新lab上面的文字
    lab->move(100,0);


}

Widget::~Widget()
{
}
void Widget::closeEvent(QCloseEvent *event){
    qDebug()<< "test";
}
void Widget::get_score_and_update_label(int xp){

    qDebug()<< "我是主窗口， 我获取到了数据:" << xp;
    qDebug()<<this->findChild<QLabel *>("score");
    QLabel* lab_swap = this->findChild<QLabel *>("score");
    //QString score = "score:";
    //QString change = (QString::number(xp));//字符串相加
    //qDebug()<< typeid(change).name();
    //lab_swap->setText(score+change);
    lab_swap->setFixedWidth(100);
    lab_swap->setText("score:"+QString::number(xp));



}


