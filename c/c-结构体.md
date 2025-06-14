---
layout: post
tags: [c]
---





`结构体`

```c
#include <stdio.h>

struct user {
    char *name;
    int age;
    char* address;
};
int main() {
    struct user xm;
    xm.name = "xiaomin";
    xm.age=18;
    xm.address="guozhou";
    printf("name:%s\nage:%d\naddress:%s\n",xm.name,xm.age,xm.address);
    return 0;
}
```

> 注意: 结构体定义时不能初始化， 结构体数组定义时可以。





`结构体数组`

```c
#include <stdio.h>
struct user {
    char *name;
    int age;
    char* address;
} users[2]={0};
//数组定义时可以初始化， 也可以不初始化
int main() {
    users[0].name="xm";
    users[1].name="xf";
    users[0].age=10;
    users[0].address="xf";
    users[1].address="xm";
    users[1].age=90;
    printf("%s|%d|%s\n%s|%d|%s\n",users[0].name,users[0].age,users[0].address,users[0].name,users[0].age,users[0].address);
    return 0;
}
```

> 可以起一个别名:

```c
#include <stdio.h>

struct user {
    char *name;
    int age;
    char* address;
};
/*
typedef struct user {
    char *name;
    int age;
    char* address;
}USER;
*/
typedef struct user USER;//别名
int main() {
    struct user xm;
    xm.name = "xiaomin";
    xm.age=18;
    xm.address="guozhou";
    printf("name:%s\nage:%d\naddress:%s\n",xm.name,xm.age,xm.address);
    USER xf = {"XF",18,"HK"};//另一种初始化方式
    printf("name:%s\nage:%d\naddress:%s\n",xm.name,xm.age,xm.address);
    return 0;
}


```

> 如果是用指针访问， 把`.`号改为`->`号：

```c
#include <stdio.h>

struct USER {
    char *name;
    int scor;
};
int main() {
    struct USER test ={"this", 100};
    struct USER *ptest = &test;
    printf("name:%s, scor:%d\n",test.name,test.scor);
    printf("name:%s, scor:%d\n",ptest->name,ptest->scor);
}

```







