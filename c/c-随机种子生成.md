---
layout: post
tags: [c]
---

```c
#include<stdio.h>
#include<time.h> //time()头文件
#include<stdlib.h> //srand(), rand()头文件
void main(){
	srand(time(NULL));//用于生成不同的种子
	int guess = rand();//种子不同随机数就不一样
    //int guess = rand()%10;
}
```

