
### VS相关设置
#### ox1  c/c++
基础运行检测：默认选项
#### 0x2 c/c++
优化选项：关
#### 0x3 c/c++
SDL: 关闭禁止使用不安全函数
#### 0x4 Linker
ASLR：关闭debug时的随机地址

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//char name[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x12,0xEE};
//char name[] = "AAAAAAAAB";
char name[] = {'A','A', 'A', 'A', 'A', '\xee', '\x12', '\x41','\x00'};
void test_();
int main(char argc, char *argv[]) {
	
	//printf("%x\n", test_);
	//004112EE
	//0xee,0x12,0x41,0x00
	char check_[1]{};
	strcpy(check_, name);

	//printf("%s\n", check_);
	//((void(*)())0x004112EE)();
	return 0;
}
void test_() {
	printf("helloworld\n");
}

```

> 关闭相关保护: https://bbs.kanxue.com/thread-259665.htm