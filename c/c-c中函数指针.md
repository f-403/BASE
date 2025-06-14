---
layout: post
tags: [c]
---





`C语言中， 函数跟变量没什么 不同， 函数只是指向了可执行代码的变量`

```c
#include <stdio.h>
void print_hello(void);
void print_hello(void){
    printf("hello, world!\n");
}
void main(int argc, char *argv[]){
    printf("print_hello = %p\n", print_hello);//address for print_hello function打印地址
    int (*p)(void) = (void(*)())print_hello;
    printf("address: %p\n",p);//the same address地址是一样的
    p();//调用
    print_hello();//调用
}
```



`执行函数都 有一个入口地址， 地址变量里放着可以执行的代码变是shellcode了。`

`比如定义一段内存空间， 里面存放着可执行代码的片段，调用那个地址即可。`

`SHELLCODE都是一段字符串， 我们可以用一个char payload[]=""数组定义。再在这个payload字符数组地址上调用一下就行。`



```c
#include <stdio.h>
void main(){
    unsigned char buf[] =
            "shellcode";
    void (*p)(void) = (void(*)())buf;
    //(*(void(*)())buf)();
    p();
}
```



`一些说明:`

```c
  int (*ret)() = (int(*)())code;
  ~~~~~~~~~~~~   ~~~~~~~~~~~~~~
        1              2

  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              3
```

> 1. It defines `ret` as a pointer to a function which has no parameter `()` and returns `int`. So, Those `()` indicates the definition of parameters of a function.
> 2.  It's for casting `code` to a pointer to a function which has no parameter `()` and returns `int`.
> 3.  Casts `code` as a function and assigns it to `ret`. After that you can call `ret();`.



`linux下编译WINDOWS程序:`

```bash
i686-w64-mingw32-gcc test.c 
#a.exe
```



