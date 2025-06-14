---
layout: post
tags: [python]
---

```python
def new_main():
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
#把 new_mai赋值给_out, 再把反回值赋值给 new_main
new_main = _out(new_main) #把new_main传进去后， _out参数就是new_main函数， 在_in里参调用它
new_main() #这样调用， 相当于调用_in函数了， 只是名字不一样， 看打印的doc与name， 都是in函数的
print("-"*50)
```