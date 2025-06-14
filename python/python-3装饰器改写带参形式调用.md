---
layout: post
tags: [python]
---

```python
def new_main(a):
    """这是new_main()函数的__doc__文档"""
    print("函数名字是:", new_main.__name__)
    print(f"new_main函数接收到参数:{a}\n")
    print("函数文档是:{}".format(new_main.__name__))
    print(f"函数 {new_main.__name__} 运行结束.") #新格式化字符串

def _out(params): #这个参数用上_in函数里面调用
    """这是_out函数文档"""
    print(f"这是 {_out.__name__} 函数.")
    def _in(*args):
        """这是_in函数文档"""
        print(f"_in函数接受到参数:{args}\n")
        print(f"这是 {_in.__name__} 函数.")
        params(args)
    return _in   #把_in函数返加， 在外面调用就加上括号即可

print("-"*50)
#a = (1,2)
new_main(()) #注意， 接收一个参数， 可以接收一个空元组， 一个空元组也是一个参数
new_main = _out(new_main)
new_main(1223) #相当于有参数调用 _in(123),但内部会调用一次new_main(a)(_out函数参数为new_main)， _in内部相当于调用new_main(123)
new_main()
print("-"*50)
```