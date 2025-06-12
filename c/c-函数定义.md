---
layout: post
tags: [c]
---

`先声明， 注明参数类形，个数等:`

```c
#include <stdio.h>
int p(void);//函数声明
void main(){
    p();
}
int p() {
    printf("HELLO, PPP!\n");
    return 0;
}
```



`可变参数的函数:`

```c
//
// Created by who on 18/4/2021.
//
#include <stdio.h>
#include<stdarg.h>
int add(int,...);
void main(){
    add(10,2,3,4,99);//注意最后一个参数用于标识参数结束
}
int add(int get,...) {
    int count = 0;//the argv number
    va_list argvs;
    va_start(argvs,get);//第二个参数为定义add时可变参数中的最后一个参数
    while(1){
        int value = va_arg(argvs,int);//提取
        if(value==99){
            break;
        }
        printf("argv's is: %d\n", value);
        count++;
    }
    va_end(argvs);//釋放va_list
    printf("you input argvs number is: %d\n",count);

}
```

> 除此之外，我们还需要注意一个陷阱，即`va_arg`宏的第2个参数不能被指定为`char、short`或者`float`类型。`《C和C++经典著作：C陷阱与缺陷》`在可变参数函数传递时，因为char和short类型的参数会被提升为int类型，而float类型的参数会被提升为double类型 。



`main函数的参数:`

```c
#include <stdio.h>
void main(int argc, char *argv[]){
    printf("argv number is: %d\n",argc);
    for(int i=0;i<argc; i++){
        printf("The number %d argv is:%s\n", i, argv[i]);
    }
}
```



```bash
└──╼ $./a.out 1 2 3 4
argv number is: 5
The number 0 argv is:./a.out
The number 1 argv is:1
The number 2 argv is:2
The number 3 argv is:3
The number 4 argv is:4

```





