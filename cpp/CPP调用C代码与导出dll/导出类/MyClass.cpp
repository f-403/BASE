
#include "MyClass.h"
#include <iostream>

// 实现 MyClass 类
MyClass::MyClass() {
    std::cout << "MyClass 构造函数" << std::endl;
}

MyClass::~MyClass() {
    std::cout << "MyClass 析构函数" << std::endl;
}

void MyClass::sayHello() {
    std::cout << "你好，来自 DLL 的 MyClass！,我是sayHello（）函数" << std::endl;
}

// 导出工厂函数
extern "C" MyClass* __cdecl CreateMyClass() {
    return new MyClass();
}

extern "C" void __cdecl DeleteMyClass(MyClass* ptr) {
    delete ptr;
}
extern "C" __declspec(dllexport) void MyClass_sayHello(MyClass* obj) {
    obj->sayHello();
}
/*
//也可以这样写
extern "C"  void __cdecl MyClass_sayHello(MyClass* obj) {
    obj->sayHello();
}

*/