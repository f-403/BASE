---
layout: post
tags: [c]
---

`类型  xx[length]`

```c
#include <stdio.h>


void main(){
 int a[10] = {0};
 for (int i=0;i<10;i++){
     printf("%d>%d->%p\n",i,a[i],&a[i]);
 }
    printf("address for a:%p", &a);
}
```

> 关于初始化:
>
> 初始化可以`{0}`, 数值全为0， 或部分初始化:`int a[100] = {0,0,0,3,4,5,6,7,8,9,10};`
>
> 初始化时还能不指定大小， 让它自动判断:`int a[] = {1,2,3,4};//int a[4]`
>
> 还可以超过定义的大小， 但超过的值会抛弃 `int a[2] = {1,2,3,4,5};`。有些編译器会报错。







`关于数组地址`

```c
#include <stdio.h>
void main(){
 int a[5] = {1,2,3,4,5};
 for (int i=0;i<5;i++){
     printf("%d>%d->%p\n",i,a[i],&a[i]);
 }
    printf("address for a:%p", &a);
}
```

```bash
0>1->0x7fffd5beb140
1>2->0x7fffd5beb144
2>3->0x7fffd5beb148
3>4->0x7fffd5beb14c
4>5->0x7fffd5beb150
address for a:0x7fffd5beb140
```

> 数组地址相加是按照值的`sizeof`大小增加的， 如上面的int为4字节， 每次地址相加4字节。
>
> 数组首元素的地址与数组名的地址相同。
>
> 数组的`sizeof`为数组所有元素占用的字节数， 比如上面的`sizeof(a)`大小为20。



`多维数组地址:`

`array -> array[0] -> array[0][0]`

​					`array[1] -> array[1][0]`

​					`array[2] -> array[2][0]`



> `array`与`array[0]`与`array[0][0] `的地址是一样的
>
> `array[1]`与`array[1][0]`的地址是一样的
>
> `array[2]`与`array[2][0]`的地址是一样的
>
> 一维数组类似， 其他多维的也一样







