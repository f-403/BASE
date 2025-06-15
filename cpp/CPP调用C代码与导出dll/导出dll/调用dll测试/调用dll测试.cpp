// 调用dll测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h> //hmodule声明
int main()
{
    std::cout << "调用dll测试" << std::endl;
    //HMODULE dll = LoadLibraryA(R"(C:\Users\who\Desktop\allthethings\c#\cpp导出DLL\x64\Debug\cpp导出DLL.dll)");
    HMODULE dll = LoadLibraryA(R"(C:\Users\who\Desktop\allthethings\c#\cpp写DLL2\x64\Debug\cpp写DLL2.dll)");
    //std::cout << dll << std::endl;
    if (!dll) {
        std::cout << "dll导入出错" << std::endl;
        return 0;
    }
    /*
    int add(int,int);
    void test();
    */
    //获取函数地址
    int (*add)(int ,int ) = (int(*)(int,int))GetProcAddress(dll, "add");
    int sum = add(12, 12);//C:\Users\who\Desktop\allthethings\c#\cpp写DLL2\x64\Debug\cpp写DLL2.dll这里的add没有返回值
    std::cout << "add(a,b) = " << sum << std::endl;

    void (*test)() = (void(*)())GetProcAddress(dll, "test");
    test();
    FreeLibrary(dll);            // 卸载 DLL
}

/*
如果使用 静态链接（编译时链接 .lib），则必须：
包含头文件（mydll.h）。
链接 .lib 文件（DLL 的导入库）。
方法 1：项目属性设置
右键项目 → 属性 → 链接器 → 输入 → 附加依赖项
添加 mydll.lib（或完整路径如 $(SolutionDir)lib\mydll.lib）。
链接器 → 常规 → 附加库目录
添加 .lib 文件所在目录（如 $(SolutionDir)lib）。

方法 2：代码中直接指定（不推荐）
cpp
#pragma comment(lib, "mydll.lib")  // 在代码中指定链接库
*/

/*
* //python调用
>>> from ctypes import cdll,c_int
>>> mydll=cdll.LoadLibrary("./cpp导出DLL.dll")
dll已导入，可以使用test()或add(a,b)函数了
>>> mydll.test()
dll中的test()函数被 调用了
1765089216
>>> mydll.add(1,2)
3
>>>
*/