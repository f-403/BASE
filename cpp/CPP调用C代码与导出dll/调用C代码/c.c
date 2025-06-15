#include "c.h"
#include <stdio.h>

void c_print() {
	printf("%s\n", "这个信息来自c.c文件中的函数调用");
}

int add(int a, int b) {
	return a + b;
}