---
layout: post
tags: [c]
---

`assert`



```c
#include <stdio.h>
#include <assert.h>
int main() {
    int a = 10;
    assert(a != 10);
    printf("assert not here!");
}
```



`strerror`

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main() {

 FILE* p = fopen("111.txt","r");
 char* e_msg = strerror(errno);
 printf("%s\n", e_msg);

}
```

