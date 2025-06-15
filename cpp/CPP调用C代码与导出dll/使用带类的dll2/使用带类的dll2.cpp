// 使用带类的dll2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
class myclass;
int main()
{
    //导入dll
    HMODULE dll = LoadLibraryA(R"(C:\Users\who\Desktop\allthethings\c#\导出类2\x64\Debug\导出类2.dll)");
    std::cout << dll << std::endl;
    myclass* (*create_myclass)() = (myclass * (*)())GetProcAddress(dll, "create_myclass");//创建类
    void (*delete_myclass)(myclass*) = (void (*)(myclass*))GetProcAddress(dll, "delete_myclass");//删除类
    //查找对象方法
    void (*myclass_function)(myclass *) = (void (*)(myclass*))GetProcAddress(dll, "myclass_function");
    myclass* my_class = create_myclass();
    myclass_function(my_class);
    delete_myclass(my_class);
}

