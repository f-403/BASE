// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "for_dll.h"
#include <iostream>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::cout << "dll已导入，可以使用test()或add(a,b)函数了" << std::endl;//dll加载时运行
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

/*
PS C:\Users\who\Desktop\allthethings\c#\cpp导出DLL\x64\Debug> python
Python 3.10.6 (tags/v3.10.6:9c7b4bd, Aug  1 2022, 21:53:49) [MSC v.1932 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license" for more information.
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