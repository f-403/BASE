---
layout: post
tags: [c]
---

`位于头文件<limits.h>`

```c
#include <stdio.h>
#include <limits.h>

int main() {
    printf("Hello, World!\n");
    printf("size of the int: %d\n", sizeof(0));
    int max = INT_MAX;
    printf("the max_int is: %d\n", INT_MAX);
    printf("the max_int is: %d\n", max);
    return 0;
}
```

`如下所示:`

`chr CHAR_MIN CHAR_MAX`

`short SHRT_MIN SHRT_MAX`

`int INT_MIN INT_MAX`

`long LONG_MIN LONG_MAX`

`long long LLONG_MIN LLONG_MAX`

`float FLT_MIN FLT_MAX`

`double DBL_MIN DBL_MAX`

`long double LDBL_MIN LDBL_MAX`

