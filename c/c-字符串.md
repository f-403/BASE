---
layout: post
tags: [c]
---



`'单引号定义字符， "双引号定义字符串`

`可以用char数组未声明个数的形式定义字符串: char a[]="this is a test";编译器会自动在后面添加\0字符用于结束字符串。`

> `char a[]="abc";`的长度是4, 不是3， 因为后面有一个`\0`空字符， 而`char a[] = {'a','b','c'};`的数组长度为3, 因为里面就只有3个元素。



```c
//一个打印每个字符的代码
void main(){
 char a[] = "this is a test.";
 for (int i = 0; i< (sizeof(a)-1);i++){
     printf("%d>%c\n", i,a[i]);
 }

    printf("%d", sizeof(a));
}
```





`char定义数组问题, 如下代码`

```c
void main(){
 char a[] = {'t','s','\0'};
    printf("%s", a);
}
```

> `printf`时如果数组没有加上`\0`, 会打印到其他字符， 因为`printf(%s)`会一直运行到`\0`字符才结束。



`定义字符串时， 会自动在后面加\0, 如:`

```c
void main(){
 char a[] = "ti";
    printf("%s", a);
    printf("%d", sizeof(a));
}
```

> 跟上面的数组不一样， 数组的话要自动添加`\0`。



`多维数组`

```c
void main(){
    char test[][100] = {"this is test",
                     "for ruby"};
    printf("%d\n",sizeof(test));
    printf("%s\n",test[0]);
    printf("%s\n",test[0]);
    //printf("%c\n",test[0][0]);
    //printf("%c\n",test[0][1]);
    //注意这里的test[0][0]是指明哪一个哪个字符
}
```

> 多少维可以不指定， 但是每一维的大小要指定才行。
>
> 可以用`&`取地址符打印出字符串，如下:

```c
void main(){
    char test[2][100] = {"this is test",
                     "for ruby"};
    printf("%d\n",sizeof(test));
    printf("%s\n",&test[0][1]);
    printf("%s\n",test[1]);
}
200
his is test
for ruby

```



`字符串函数->要包含头文件<string.h>`

`strcpy`

`strncpy`

`strlen()->与sizeof不同， sizeof包含空字符， strlen()返回可见性字符个数， 不计算\0的值`

```c
void main(){
    char a[100] = {};
    printf("size of a: %d\n", sizeof a);
    printf("size of a: %d\n", strlen(a));
}
```

`strcat`

`strncat`

`strcmp`

`strchr 搜索字符串， 返回搜索到的字符串地址->单个字符`

```c
char *p = strchr("this is a test",'i');
printf("%s", p);
//printf("%c", *p);
```

`strrchr 从后面向前查找->单个字符`

`strstr 子字符串查找`

`大小写转换类函数:tolower(),toupper() -> <ctype.h>`

`字符串转数字函数:atof(),atoi(),atol(),atoll()`

```c
char va = "11.23";
float new_va = atof(va);
```

`宽字符串函数 -> <wchar.h>`











