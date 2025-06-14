// 1.3回声服务.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")  // 告诉编译器链接ws2_32.lib

int main()
{
    //初始化
    WSAData wsadata;//结构体
    if (WSAStartup(MAKEWORD(2, 2), &wsadata)!= 0) {
        //成功时返回0
        std::cout << "socket error!" << std::endl;
        return 0;
    }

    SOCKET ser;//定义一个服务端

    ser = socket(PF_INET,SOCK_STREAM, 0);//创建一个服务器
    if (ser == INVALID_SOCKET) {
        std::cout << "ser创建失败." << std::endl;
        return 0;
    }

    //填充
    SOCKADDR_IN seraddr;//用于设置服务端结构体
    memset(&seraddr, 0, sizeof(seraddr));
    //设置ser信息
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = htonl(ADDR_ANY);//本机地址转换到网络地址
    seraddr.sin_port = htons(1234);//本机端口转换到网络端口

    //监听
    if (bind(ser, (SOCKADDR*)&seraddr, sizeof(seraddr)) == SOCKET_ERROR) {
        /*
        #define INVALID_SOCKET  (SOCKET)(~0)
        #define SOCKET_ERROR            (-1)
        */
        std::cout << "bind调用失败." << std::endl;
        return 0;
    }
    if (listen(ser, 5) == SOCKET_ERROR) {
        std::cout << "listen调用失败." << std::endl;
        return 0;
    }
    std::cout << "listen正在监听......" << std::endl;

    //接受连接
    SOCKADDR_IN cliaddr;//用于设置客户结构体
    int cliaddr_size = sizeof(cliaddr);
    SOCKET cli;//客户端
    cli = accept(ser, (SOCKADDR*)&cliaddr, &(cliaddr_size));
    //连接成功时， 返回客户端对象cli, 用于下面发送信息到cli
    if (cli == SOCKET_ERROR) {
        std::cout << "accept调用失败." << std::endl;
        return 0;
    }

    //发送数据
    const char* message = "hello, world";
    std::cout << "准备发送的message的信息是:" << message << std::endl;
    send(cli, message, strlen(message), 0);//这里的cli， 是服务端要发过去的对象


    //清理
    closesocket(cli);
    closesocket(ser);
    WSACleanup();
    return 0;
}

