#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QWidget>
#include <QPushButton>

class mybutton : public QPushButton
{
public:
    mybutton();
    //两种方法
    /*
    mybutton(QString name, QWidget *par):QPushButton(name, par) {
        //显式调用父类中的有参构造
    }
*/
    //或者直接重写
    mybutton(QString name, QWidget *par){
        this->setText(name);
        this->setParent(par);
    }
};

#endif // MYBUTTON_H
