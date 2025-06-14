---
layout: post
tags: [c]
---

`void* malloc(size_t)`

```c
#include <stdio.h>
#include <stdlib.h>
#define N 10
int main() {
    int* p = (int*)malloc(N*(sizeof(int)));
    for(int i = 0;i<N;i++){
        (*(p+i))=i;
        printf("write done!->%d\n", i);
    }
    for(int i = 0;i<N;i++){
        printf("%d\n", *(p+i));
    }
    
}
```



`void calloc(数组大小, 数组类型的字节大小)-> calloc(10,sizeof(int))->值自动填0`

`void* realloc(malloc或calloc或realloc返回的指针， 新内存字节数)`

`void free(void*) -> 参数为所有指针类型 ，所有指针类型都能转为void*类型`





