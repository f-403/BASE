---
layout: post
tags: [c]
---

`1. goto`

```c
#include <stdio.h>


void main(){
    int input = 0;
    printf("Input a number:");
    scanf("%d", &input);
//input = 5;
    if (input > 5) {
        goto hig_f;
    }else {
        goto low_f;
    }
    low_f: printf("You input the number is low_f: %d\n", input);
    hig_f: printf("You input the number is hig_f: %d\n", input);

    printf("DONE!!!\n");
}
```

> 注意这里的`goto`, 如果你输入小于5的话， 下面的两个标签`low_f`, `hig_f`都会执行。



`2. if`

```c
if(){

}
if(){

}else {

}
```





`3.for`

```c
int i =0;
for(i=0;i < 10; i++) {}

for(int i = 0; i<100;i++){	}
for(;;){break;}
```





`4.switch`

```c
switch(value) {
	case 1:
	{
		break;
	}
	case 2: cast 3:
	{
		break;
	}
	default{
	
	}
}

```



`5.while/do while`

```c
while(){}
do{}while()	
```



