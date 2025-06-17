// 一个简单的createprocess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
int main()
{
        STARTUPINFO si = { sizeof(STARTUPINFO) };//必定要设置第一个cb的大小
        PROCESS_INFORMATION pi;
        //MessageBox(NULL, L"text", L"TEST", 0);
        // 要执行的命令（例如：dir C:\）
        wchar_t cmd[] = LR"(T)";
        //要加 /c 
        // 
        // 创建进程（不显示窗口）
        if (!CreateProcess(
            NULL,           // 不指定可执行文件路径（直接用 cmd）
            cmd,            // 命令行参数（/c 表示执行后关闭）， 要求是能修改的字符串
            NULL,           // 进程句柄不可继承
            NULL,           // 线程句柄不可继承
            FALSE,          // 不继承句柄
            CREATE_NO_WINDOW, // 不显示控制台窗口（静默运行）
            NULL,           // 使用当前环境变量
            NULL,           // 使用当前工作目录
            &si,            // 启动信息
            &pi             // 进程信息
        )) {
        //    printf("CreateProcess failed (%d)\n", GetLastError());
           return 1;
        }

        // 等待进程结束（可选）
        //WaitForSingleObject(pi.hProcess, 10000);//INFINITE);

        //跳过获取返回值， 这里不关心， 我也没学到

        // 关闭句柄（避免资源泄漏）
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        return 0;
}

