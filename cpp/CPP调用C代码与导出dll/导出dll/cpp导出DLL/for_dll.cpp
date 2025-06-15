#include "pch.h"  // 如果你启用了 PCH 就保留，否则删除, 这个要在第一行
#include <iostream>

#include "for_dll.h"  // 确保一致

using namespace std;
void test() {
	cout << "dll中的test()函数被 调用了" << endl;
}

int add(int a, int b) {
	return a + b;
}
