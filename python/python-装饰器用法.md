---
layout: post
tags: [python]
---


```python
def test(test):
    print('test')
    return test#如果这时没返回值， 默认返回None, 相当于None()这样调用函数， 所以会出错

@test
def myprint():
    print('myprint')

#myprint = test(myprint) 装饰器相当于这种写法
#可以用 test.__name__或test.__doc__查看当前函数名或文档字符串
myprint()
```