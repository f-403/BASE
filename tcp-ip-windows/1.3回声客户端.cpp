// 1.3回声客户端.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>  // 包含inet_pton的声明
#pragma comment(lib, "ws2_32.lib")  // 关键行

int main()
{
    SOCKET cli;
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        std::cout << "wsastartup启动失败" << std::endl;
        return 0;
    }

    //设置客户端
    cli = socket(PF_INET, SOCK_STREAM, 0);
    if (cli == INVALID_SOCKET) {
        std::cout << "socket调用失败" << std::endl;
        return 0;
    }
    //结构体清0
    SOCKADDR_IN cliaddr;
    memset(&cliaddr, 0, sizeof(cliaddr));
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(1234);
    //cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //cliaddr.sin_addr.s_addr = inet_addr("192.168.1.1");已弃用

    int check_cliaddr = inet_pton(AF_INET, "127.0.0.1", &cliaddr.sin_addr);//成功返回1,失败返回-1或0
    if (check_cliaddr <= 0) {
        std::cout << "设置地址出错" << std::endl;
        return 0;
    }

    //打印客户端信息
    //char ip_addr[16] = {};
    char ip_addr[INET_ADDRSTRLEN] = {};
    if (inet_ntop(AF_INET, &cliaddr.sin_addr, ip_addr, INET_ADDRSTRLEN) != NULL) {
        std::cout << "连接地址为:" << ip_addr << std::endl;
    }
    else {
        std::cout << "转换IP地址出错" << std::endl;
        return 0;
    }
    std::cout << "端口号为: " << ntohs(cliaddr.sin_port) << std::endl;
     
    
    //连接
    if (connect(cli, (SOCKADDR*)&cliaddr, sizeof(cliaddr)) == SOCKET_ERROR) {
        std::cout << "connect出错" << std::endl;
        return 0;
    }

    //发送数据， 如果连接成功， 这个cli会跟服务端绑定一起了，能相互发数据
    char message[1024];
    memset(message, 0, sizeof(message) / sizeof(char));
    int recv_size = recv(cli, message, sizeof(message)/sizeof(char) - 1, 0);
    if (recv_size == -1) {
        std::cout << "recv读取数据出错" << std::endl;
        return 0;
    }

    //打印接收到的数据
    std::cout << "接收到的字节大小为: " << recv_size << ", 接收到的数据为: " << message << std::endl;

    //清理
    closesocket(cli);
    WSACleanup();
}

