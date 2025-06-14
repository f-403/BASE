---
layout: post
tags: [python]
---


```python
from functools import wraps #用于显示原函数的doc与name
def _out(params): #这个参数用上_in函数里面调用
    """这是_out函数文档"""
    print(f"这是 {_out.__name__} 函数.")
    @wraps(params)#用于显示的来函数的__doc__与__name__
    def _in(*args):
        """这是_in函数文档"""
        print(f"_in函数接受到参数:{args}")
        print(f"这是 {_in.__name__} 函数.")
        params(args)
    return _in   #把_in函数返加， 在外面调用就加上括号即可

@_out
def new_main(a):
    """这是new_main()函数的__doc__文档"""
    print("--> 函数名字是:", new_main.__name__)
    print(f"--> new_main函数接收到参数:{a}")
    print("---> 函数文档是:{}".format(new_main.__name__))
    print(f"---> 函数 {new_main.__name__} 运行结束.") #新格式化字符串

#new_main = _out(new_main)能简写成如下形式
#在调用它的函数头上添加上:
#
"""
@_out
def c(xx):
    pass

相当于c = _out(c), 也就是， 函数c传进_out里去， 并且返回 c, 注意你在_out里要去处理一下参数(这里是函数c)。
在写好装饰器后， 你后面所有的 c(xx)调用,都是相当于把 c当做参数传给_out:
1. ----> c = _out(c)
2. ----> c(xxx)
内部会自动调用这两步
"""
print("-"*50)
new_main(123)
print("-"*50)

#如果要把函数文档隐藏起来， 要用到 from functools import wraps 这个包
#如上面的， new_main()是一个_in的别名，显示的doc与name就是_in本身的。 但你还是想让它显示的是new_main字面值函数的doc与name, 就要在装饰器里写上：
#@wrasp(函数名)

```

