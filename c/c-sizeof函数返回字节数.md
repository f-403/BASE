---
layout: post
tags: [c]
---

```c
#include <stdio.h>
#include <stddef.h>
int main(){
    int test = 1;
    //size_t number = sizeof(int);
    printf("the size of the int is: %d\n", sizeof(test));
    printf("the size of the int is: %d\n", sizeof(int));
    return 0;
}
```

> sizeof返回的值类型为size_t, 你也可以用int接收， size_t类型定义在头文件<stddef.h>中

