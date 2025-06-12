---
layout: post
tags: [c]
---

> 单个字符的录入
>
> `scanf()`



```c
#include <stdio.h>
int main(void){
    char input= 0;
    printf("The input char is: %c\n", input);
    printf("Input a char:");
    scanf("%c", &input);
    printf("The input char is: %c\n", input);
    return 0;
}
```

```bash
The input char is: 
Input a char:ui
The input char is: u

```

> 注意输出时截断。`char`只能存放单个字符， `''`与`""`定义不一样， `'`为字符， `"`为字符串



`利用scanf()读入一串字符串`

```c
void main(){
    char a[100] = {};
    printf("size of a: %d\n", sizeof a);
    printf("size of a: %d\n", strlen(a));
    printf("Input your name:");
    scanf("%[^\n]", a);

    //scanf("%s",swap);
    //strcat(a,swap);
    printf("string of a: %s\n", a);
}
```

> `%[...]`说明:  `[^\n]`代表不包含`\n`的最长匹配串。这样的话就会连同空格一起读入。
>
> 而`%s` 的解释为：string of non-white space characters，即不包含空格，tab的最长匹配串
> `man scanf() -> linux`
>
> `scanf("%[^#]", a);`可以一直录入， 直到录入`#`符后就退出(不包含`#`符)。



`gets(buff)， 出错返回NULL`

`fgets(buff,sizeof(buff),stdin)，出错返回NULL`

```c
void main(){
    char in[100] = {};
    if(gets(in)==NULL){
        printf("gets error!");
    }else {
        printf("%s\n", in);
    }
    if(fgets(in,sizeof(in),stdin)==NULL){
        printf("gets error!");
    }else {
        printf("%s\n", in);
    }
}
```

> `gets()`在字符串后加`\0`, 而`fgets()`在字符串后加`\n\0`
>
> `char [2]`用`fgets()`输入的话， 最多保存1个用户输入的字符， 因为它还要输入一个`\n`



