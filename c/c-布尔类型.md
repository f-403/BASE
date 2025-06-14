---
layout: post
tags: [c]
---

> 头文件 `<stdbool.h>`

`可以存放布尔真假`



```c
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
void main(){
    char c = 0;
    wchar_t wc = 0;
    _Bool tf = 10;
    printf("The sizeof c is: %d\n", sizeof(c));
    printf("The sizeof wc is: %d\n", sizeof(wc));
    printf("The bool type tf is:%d\n", tf);

}
```

`可以自行测试如下值:`

```c
_Bool tf = false;
_Bool tf = true;
_Bool tf = '';
_Bool tf = "";
_Bool tf = ' ';
_Bool tf = " ";
_Bool tf = "a";
...
```

