```c++
PF_INET	Protocol Family INET	socket() 函数的第一个参数	指定协议族（如 IPv4、IPv6），决定底层使用的协议栈。
AF_INET	Address Family INET	sockaddr 结构体的 sin_family 字段	指定地址族（如 IPv4、IPv6），决定地址的格式和含义。

SOCKET sock = socket(PF_INET, SOCK_STREAM, 0);
// 或等价写法：
SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);  // 现代系统中两者通用


struct sockaddr_in addr;
addr.sin_family = AF_INET;  // 必须使用 AF_INET，指定 IPv4 地址格式
addr.sin_port = htons(8080);
inet_pton(AF_INET, "192.168.1.1", &addr.sin_addr);



SOCKET sock = socket(PF_INET6, SOCK_STREAM, 0);  // 创建 IPv6 TCP 套接字
struct sockaddr_in6 addr;
addr.sin6_family = AF_INET6;  // 指定 IPv6 地址族


```