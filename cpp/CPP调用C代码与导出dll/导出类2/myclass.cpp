#include "myclass.h"
#include <iostream>

myclass::myclass() {
	std::cout << "myclass构造函数被 调用" << std::endl;
}

myclass::~myclass() {
	std::cout << "myclass对象被删除了" << std::endl;

}

void myclass::my_class_test() {
	std::cout << "我是对象的方法my_class_test(),现在正在被 调用" << std::endl;
}

myclass* create_myclass() {
	return new myclass();//返回对象
}
void delete_myclass(myclass* my_class) {
	delete my_class;//删除传过来的对象
}

void myclass_function(myclass* my_class) {
	std::cout << "对象准备调用它的函数" << std::endl;
	my_class->my_class_test();
}