---
layout: post
tags: [c]
---

> 在头文件 `<stddef.h>中定义`

```c
#include <stdio.h>
#include <stddef.h>
void main(){
    char c = 0;
    wchar_t wc = 0;
    printf("The sizeof c is: %d\n", sizeof(c));
    printf("The sizeof wc is: %d\n", sizeof(wc));

}
```

```bash
The sizeof c is: 1
The sizeof wc is: 4

```



