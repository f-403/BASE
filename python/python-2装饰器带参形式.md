---
layout: post
tags: [python]
---

```python
def new_main(a):
    """这是new_main()函数的__doc__文档"""
    print("函数名字是:", new_main.__name__)
    print("函数文档是:{}".format(new_main.__name__))
    print(f"函数 {new_main.__name__} 运行结束.") #新格式化字符串

def _out(params): #这个参数用上_in函数里面调用
    """这是_out函数文档"""
    print(f"这是 {_out.__name__} 函数.")
    def _in():
        """这是_in函数文档"""
        print(f"这是 {_in.__name__} 函数.")
        params()
    return _in   #把_in函数返加， 在外面调用就加上括号即可

print("-"*50)

#传带参数的话，就特别点，如果new_main2带参， 你要这样调用 new_main2(123), 相当于调用 _in(123)， 但_in是无参的
#你像下面这样写的话
new_main = _out(new_main)
new_main() #相当于没有参数调用 _in(),但内部会调用一次new_main(a)(_out函数参数)， 你这样调用没法传参进去给new_main(a)。
#TypeError: new_main() missing 1 required positional argument: 'a'
#要用不定参数的形式:
#要改写函数接收不定参数
print("-"*50)
```