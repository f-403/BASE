---
layout: post
tags: [c]
---

`<time.h>/clock()/CLOCKS_PER_SEC`

`clock()返回值为tick`

`CLOCKS_PER_SEC表示一秒有多少个tick`

```c
#include <stdio.h>
#include <time.h>

void main(){
    time_t t = clock();
    printf("Time is:%d\n", t);
    for(;clock()-t<CLOCKS_PER_SEC;){
        printf("Time is: %d\n",clock()-t);
    }
}
```

