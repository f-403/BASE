---
layout: post
tags: [c]
---

```c
#include <stdio.h>
void main(){
    int *ip = NULL;
    int number = 100;
    ip = &number;
    printf("the address is: %p\n",ip);
    printf("The *ip values is: %d, and the address is: %p",*ip,ip);

}
```

> 注意不能直接把一个数值放到指针里去: `int *p=NULL;*p=100;`
>
> 指针要先有指向地址才能放东西进去。



`对于运算符优先级，可以多加点括号， 如:`

```c
++*p;
++(*p);
(*p)++;

```



`常量指针：`

```c
#include <stdio.h>
void main(){
   int const *cp = NULL;//相当于const int number, 也就是说， *cp这一整块不能改变，但是cp本身可以改变(像int const (a))
   int* const cp2 = NULL;//cp2不能改变， 但是它指向的值是可以改变的
   int const * const cp3 = NULL;//cp3不能改变， 而且*cp3一整块也不能改变, 像int const a

}
```

> 可以写一条语句， 如:` int const number = 100;`这样的来对比一下
>
> 对于局部变量, `const`后就成了局部常量， 你虽然不能直接修改， 但还是能用 `*p = 123;`这种形式去修改它。
>
> 对于全局变量， `const`后就成了全局常量， 你用`*p=123;`这种形式也不能修改。



`数组与指针:`

```c
#include <stdio.h>
void main(){
    char name[10] = {0};
    scanf("%s", name);
    printf("name is:%s\n", name);
    printf("name[1] is:%c\n", name[1]);
    char *ps = name;
    scanf("%s", ps);
    printf("name is:%s\n", ps);
    printf("name[1] is:%c\n", *(ps+1));
    /*
12345
name is:12345
name[1] is:2
12345
name is:12345
name[1] is:2
      */
}
```

> 注意数组名的`&name`形式， 这虽然也跟数组`name,name[0]`的址址相同， 但是还是有区别的。
>
> `name,name[0]`这种是数组首元素的地址， 每次指针+-操作的话， 是按照定义的类型的字节进行运算的。
>
> 而`&name`这种是一整个数组的地址，每次指针进行+-操作的话， 是按一整个数组的大小来进来运算的。要注意。





`多维数组的指针:`

> `int *pa = NULL;int array[1][2]={};`这里定义了`*pa`与`array`, 注意这里的`pa`类型与`array`不一样， 你不能`pa=array`, 因为`array`是一个指向整形数组的指针， 而`pa`是指向整形的指针

```c
#include <stdio.h>
void main(){
    char b[3][3] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'},
    };
    printf("The array[1][2] is: %c\n",b[1][2]);
    char (*pb)[3] = b;//要注意这里的pb声明， 你不能声明为 char *bp=b, 因为这样声明的话跟b的类型不一样
    printf("b address: %p\n",b);
    printf("b[0] address: %p\n",b[0]);
    printf("b[1] address: %p\n",b[1]);
    printf("b[2] address: %p\n",b[2]);
    printf("b[0][0] address: %p\n",&b[0][0]);
    printf("b[1][0] address: %p\n",&b[1][0]);
    printf("b[2][0] address: %p\n",&b[2][0]);
    printf("---------------------\n");
    printf("pb address: %p\n",pb);
    printf("pb[0] address: %p\n",pb+0);
    printf("pb[1] address: %p\n",pb+1);
    printf("pb[2] address: %p\n",pb+2);
    printf("pb[0][0] address: %p\n",((pb+0)+0));
    printf("pb[1][0] address: %p\n",((pb+1)+0));
    printf("pb[2][0] address: %p\n",((pb+2)+0));
}
```



`指向指针的指针:`

```c
int* *pp;// int*定义指针， 指针变量定义时要加*, 所以就是int* *p=NULL;
```



`指针数组:`

```c
int* p[10]={NULL};	//int*类型的数组， 内容肯定是存放指针了。 就比如int a[1], 因为是int类型，所以只用来存int
```

```c
#include <stdio.h>
int main(void) {
	int a = 1;
	int b = 2;
	int* pa = &a;
	int* pb = &b;
	int* p[2] = { &a, &b };//p与[]结合， 说明是个数组， int*指定每个元素是指针,相当于int* (p[2]),两个元素，每个元素是	//int*
}
//指针数组，  存放指针的数组
 
```

`数组指针`

```c
#include <stdio.h>
void main() {
	//分段解说
	//p 是一个变量
	//*p是一个指针
	//int p[10]是一个数组p，类型为int， p指向10个元素,每个元素为int
	//int[10] (*p) 是一个指针(*p)，类型为int[10]， (*p)指向10个元素,每个元素为int
	//关键是[]号扰先级， 这里的(*p)要加括号, 说明定义了一个指针变量
	//综合上面， 定义一个如下结构:
	//int (*p)[10]， 定义了一个指针(*p)， (*p)指向10个元素， 每个元素类型为int 
	//相当于:int[10] (*p), *p是一个指针， 指向的类型为int[10](包含10个int元素的数组)
	//
	int a[10] = { 0 };
	//int[10](*p) = &a;
	int (*p)[10] = &a; 

	//可以用如下方式理解
	//int* p[10] 一个p数组([]号运算符优先级高)， 10个元素，每个元素是int*
	//int[10] (*p), 一个p指针(*p)，类型为int[10]* ,相当于指向一个包含10个int的数组(int[10])

}
```

> 对于二维数组， 如下:

```c
#include<stdio.h>
void main(void) {
	int a[3][3] = {1,2,3,
	4,5,6,
	7,8,9};
	printf("%d\n",a[0][2]);
	int(*p)[3][3] = &a;//p是一个指针， 指向的类型为int[3][3]
}
```

> 看一个其他类型:

```c
#include<stdio.h>
void main(void) {
	char* arr[10];//一个数组， 每个元素是char*
	char* (*pa1)[10] = &arr;//一个指针， 指向的每个元素都是char[10]*
	char* (*pa2) = &arr[0];//一个指针， 指向的每个元素都是char*
}
```

> 一定要注意整个数组的地址与数组首地址的不同。

```c
#include<stdio.h>
void test(int (*)[5],int,int);
void main(void) {
	int a[3][5] = { {1,2,3,4,5},{4,5,6,7,8},{7,8,9,10,11} };
	test(a, 3, 5);
}
void test(int (*p)[5], int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ",*(*(p+i)+j));//p+i说明是在整个数组间移动， *(p+i)取得首元素地址， *(p+i)+j在每组数组间移动
		}							//(*(*(p+i)+j))取每组数组里面的每一个值 
		printf("\n");
	}
}
```

`一个例子：int (*array[10])[5]`

> `[10]`优先级高， 说明它是一个数组, 拿掉里面的`array[10]`后， 外面的是`int(*)[5]`，说明这个数组每个元素都是`int(*)[5]`类型的， 因为有`*`号， 又说明这个数组每个元素是一个指针， 指向的元素是`int[5]`, 最终， 这个表达式的意思就是， 一个数组， 10个元素， 每个元素是指向`int[5]`的指针, 也就是每个元素都是指向一个一维数组(含5`个int`元素)的子针。













`函数指针:`

```c
int (*pfunc)(int,int);	
```

```c
#include<stdio.h>
void test() {
	printf("test function");
}
void main(void) {
	void (*p)() = &test;
	p();
	(&test)();
	(*p)();
	(*****p)();//多层解引用也是一样的
}
```

`(*(void (*)())8)()理解:`

> 最内层 `(void (*)())`这是一个函数指针， 在`8`前两加个括号括住它， 说明把`8`强制类型转换成了一个函数指针。
>
> `(*  (void(*)()8)   )`在里面一整块前面加个`*`号说明是解引用， 后面有一个`()`号， 说明这是解引用后调用了一个函数。最终目的也就是把`8`强制转换成函数指针之后再调用。
>
> 以后写`shellcode`时要用到这种方式。

`void(*signal(int, void(*)(int)))(int)理解:`

> 最里面层， `signal(int, void(*)(int))`说明这是一个函数调用， 第1个参数为int, 第2个参数为函数指针。
>
> 之后返回值为最外层的:`void(*     )(int)`， 这也是一个函数指针。也就是， 里面一层的 `signal(int,void(*)(int))`的返回值又是一个函数指针。







`函数指针数组:`

```c
int(*pfunc[10])(int,int,char);
```

```c
#include<stdio.h>
int a() {
	return 1;
}
int b() {
	return 2;
}
int c() {
	return 3;
}
void main(void) {
	int (*pf[3])() = {a,b,c};//[]号优先级高， 说明是一个数组， 3个元素
	//每个数组的元素类型为 int (*)(), 也就是函数指针， 跟a,b,c函数一样
	for (int i = 0; i < 3; i++) {
		printf("%d\n",pf[i]() );
	}
}
```

`指向函数指针数组的指针:`

```c
#include<stdio.h>
void main(void) {
	int(* pfunc[10])(int, int, char);
	//pfunc是一个数组， 每个数组元素是int(*)(int,int,char)类型
	//我们下面定义一个指针指向它:
	// *p =  &pfunc
	//它的类型为: int(*)(int,int,char)[10](注意这里的类型不是int(*)(int,int,char), 因为我们是取&pfunc的地址， 不是取&pfunc[0]， 就像取数组的一整个地址， 而不是取第一个元素的地址一样。), 相当于是:
	//int(*)(int,int,char)[10] (*p) = &pfunc;
	//写成正确形式为:
	//int (*(*p)[10])(int,int,char) = &pfunc;
	int (*(*p)[10])(int, int, char) = &pfunc;
    //p是一个指针，指向的数组有10个元素， 每个元素类型为int(*)(int,int,char)

}
```

> 如果是取数组的第一位地址而不是整个数组的地址， 代码应如下所示:

```c
#include<stdio.h>
void main(void) {
	int(* pfunc[10])(int, int, char);
	//pfunc是一个数组， 每个数组元素是int(*)(int,int,char)类型
	//我们下面定义一个指针指向它:
	// *p =  &pfunc
	//它的返回类型为: int(*)(int,int,char)[10], 相当于是:
	//int(*)(int,int,char)[10] (*p) = &pfunc;
	//写成正确形式为:
	//int (*(*p)[10])(int,int,char) = &pfunc;
	int (*(*p))(int, int, char) = &pfunc[0];

}
```













`32平台4个字节， 64平台8字节`

`指针也是一个变量， 关键是你定义的时候的类型不同， 你解引用 *p 的时候，因为类型不同， 修改的内存字节大小不一样`

```c
void main(void){
	int a =0x11223344;
	int* pa = &a;
	chr* pca = &a;
    *pa=0;//修改了4个字节
    *pca=0;//修改了1个字节
		
}
```

