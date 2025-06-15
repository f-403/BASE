#include <iostream>
#include "dll.h"
void test() {
	std::cout << "这个是dll2, test()函数被调用" << std::endl;
}

void add(int a, int b) {
	std::cout << "a+b=" << a + b << std::endl;
}