
##### 字符串与C-style风格
```cpp
const int size = 10;
int main() {
	
	char name[size]{};
	std::string name2{};

	std::cout << "c-style input:";
	std::cin.getline(name, size);//长度为size-1(如果换行符不在size范围里， 会设置cin.fail为真)
	std::cout << "you input c-syle is:" << name << std::endl;

	std::cout << "string style input:";
	//cin >> name2
	std::getline(std::cin, name2);//可以任意长度
	std::cout << "you input string style is:" << name2 << std::endl;
}
```

##### 结构体
```cpp
//#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <string.h>

//结体体与类一样， 只是结构默认方法或继承是public, 而类默认是prive
//定义
struct my_struct {
	char name[10];
	int age;
	~my_struct(){
		std::cout << "init struct" << std::endl;
	}
public:
	void struct_test() {
		std::cout << "结构体函数， 跟类相似" << std::endl;
	}
};
int main() {
	my_struct first{"hello", 12};
	my_struct two = first;
	std::cout << first.name  << " - " << first.age << std::endl;
	std::cout << two.name << " - " << two.age << std::endl;
	first.age = 22;
	strncpy_s(first.name,9, "test又cccccccccccccc", _TRUNCATE);
    //只复制9个，
    //剩下的截断， 这里第四个参数
	//如果大于第二个参数， 程序会报错。
	std::cout << first.name << " - " << first.age << std::endl;
	std::cout << two.name << " - " << two.age << std::endl;
	two.struct_test();
}
```

##### 枚举
```cpp
#include <iostream>

int main() {

	enum MyEnum
	{
		red,green, blue,a
	};
	enum class MyEnum2 //这样默认就不能转为int型了
	{
		a,b,c,d
	};

	enum MyEnum3 : char //指定为char类型
	{
		//注意， 这里默认aa, bb还是0与1, 与底层没有关， 虽然这里定义为char类型
		aa,bb,cc='c',dd
	};

	MyEnum test = MyEnum::a;
	MyEnum test2 = MyEnum::green;
	std::cout << test << std::endl;

	std::cout << test2 << std::endl;
	MyEnum3 test3 = MyEnum3::cc;
	MyEnum3 test4 = MyEnum3::aa;
	std::cout << "test3:" << char(test3) << std::endl;	
}
```


##### 数组替代品
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {

	//自增
	std::vector<int> my_v = {};
	std::cout << "length is:" << my_v.size() << std::endl;

	my_v.push_back(123);
	my_v.push_back(456);
	std::cout << "length is:" << my_v.size() << std::endl;
	
	for (int swap : my_v) {
		std::cout << swap << std::endl;
	}

	//数组
	std::vector<float> my_v_2(10);
	std::cout << my_v_2.size() << std::endl;
}
```


##### 函数与array对象
```cpp
#include <iostream>
#include <array>
using namespace std;

void test(array<int, 3> p, int);
void test2(array<int, 3>* p, int swap_);//指针形式
int main() {	
	const int size = 3;
	array<int, size> array_int{1,2,3};
	test(array_int, 3);
	test2(&array_int, 3);//要传地址， 跟数组不一样了
}
void test(array<int, 3> p, int swap_) {

	for (int i = 0; i < 3; i++) {
		std::cout << p[i] << std::endl;
	}
}
void test2(array<int, 3> *p, int swap_) {

	for (int i = 0; i < 3; i++) {
		std::cout << (*p)[i] << std::endl;
		
	}
}
```

##### 用ifstream向字符串写数据
```cpp
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	ifstream infile("test.txt");
	if (!infile.good()) {
		cout << "文件打开失败" << endl;
		return EXIT_FAILURE;
	}

	string swap;
	while (infile >> swap) {
		cout << swap << endl;
	}
	cout << "文件输出完毕" << endl;

}
```

##### 函数重载问题
```cpp
#include <iostream>

void test(int *);
void test(const int*);
int main() {

	//只有指针或引用才能用const来重载， 比如test(int)与 test(const int), 被视为两个相同的函数，并不是重载
	int a = 1;
	const int* p = &a;
	test(&a);
	test(p);
}
void test(int* a) {
	std::cout << "test(int)" << std::endl;
}
void test(const int* a) {
	std::cout << "test(const int)" << std::endl;
}
```

##### 函数模板
```cpp
#include <iostream>

template <class T>
void test(T a, T b) {
	std::cout << a + b << std::endl;
}

int main() {
	test(1,2 );
	test(1.1, 2.2);
}
```

##### 运算符重载
```cpp
//注意， 重载<<符号时， 为了能够链式调用， 返回值要求要是std::ostream &os
/*
std::ostream& operator<<(std::ostream& os, const 自定义类型& obj) {
    // 输出 obj 的内容到 os
    return os;  // 返回 os 以支持链式调用
}
*/
#include <iostream>
class Time {

public:
    int a = 12;
    int sum = 0;
    Time operator+(Time& t) {
        this->sum = t.a + t.a;//两个相加
        std::cout << this->sum << std::endl;
        return t;
    }
    
};

int main()
{
    Time t, t1;
    Time t3 = t + t1;
    std::cout << "t sum:" << t.sum << std::endl;
    std::cout << "t3 sum:" << t3.sum << std::endl;

}
```
