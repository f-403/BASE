
#include <iostream>
#include "c.h" //引入c头文件

/* //如果头文件那边没有写这个， 这里可以写
extern "C" {
    #include "c.h"
}
*/

int main()
{
    std::cout << "测试调用c.c中的函数\n";
    c_print();
    std::cout << "a + b = " << add(1, 2) << std::endl;
    return 0;
}

