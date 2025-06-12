# 关于CPP所有

[toc]

* * *
## 基础

##### 打印16进制
```cpp
#include <iostream>

int main()
{
    //std::cout << std::hex;
    std::cout << int('a') << std::endl;
    std::cout << int('z') << std::endl;
    std::cout << int('A') << std::endl;
    std::cout << int('Z') << std::endl;
    int port = 3389;
    std::cout << std::hex;
    std::cout.setf(std::ios::showbase);
    std::cout << port;

}
```

##### 限制cin输入长度
```cpp
#include <iostream>

int main()
{
    char name[2];
    std::cout << sizeof(name) << std::endl;
    std::cout << name << std::endl;
    std::cin.width(2);//设置只读取1个， 有一个是默认的\0空字符
    std::cin >> name;

    std::cout << name << std::endl;
}
```

##### 头文件中的最大值与最小值
```cpp
#include <iostream>
#include <climits>
int main() {

	int intmax = INT_MAX;
	float float_min = FLT_MIN;
	std::cout << "int_max = " << intmax << std::endl;
	std::cout << "float_min = " << float_min << std::endl;
	
}
```
##### 字符串
```cpp
#include <iostream>

int main() {
	char name1[] = { 't','i','a','t' };
	for (char swap_char : name1)
	{
		std::cout << swap_char << std::endl;
	}
	char name2[] = { 't','i','a','t','\0'};//带结束符号的是字符串
	std::cout << name2;
	char not_zero[3] = "ab";
	//可以不写个数， 让系统自动计算并且在后面加上\0
	char auto_zero[] = "this is a test";
}
```
##### getline与get
```cpp
#include <iostream>
int main() {
//#getline会吃掉换行符(前提是不超出设置的长度， 如超出长度， 换行符也会存放缓冲区， 并设置cin.fail为真)
	//get 不会吃掉（无论是不是超出设置的长度）,如超出长度， 也会存放缓冲区， 并设置cin.fail为真

	const int size = 3;
	char name[size]{};
	char address[size]{};
	std::cout << "you name:";
	std::cin.get(name, size);
	std::cout << "name:" << name << std::endl;
	//清除缓冲
	while (std::cin.get() != '\n') {
		continue;
	}
	std::cout << "address:";
	std::cin.get(address, size);
	std::cout << "address:" << address << std::endl;
}
```

##### 当getline或cin错误时
```cpp
#include <iostream>
#include <limits>

int main() {
    const int size = 10;
    char name[size] = {};
    char address[size] = {};

    std::cout << "you name:";
    std::cin.getline(name, size);
    std::cout << "hello, " << name << std::endl;

    // 如果上面的getline没有正确读取到换行符， cin.fail()变为真了， 之后下面的getline如果你不调协cin.clear的
    //话， 会直接跳过， 设置原则是这样的
    //getline(name,size)中的10个字符中， 要有一个是换行符才行
   if(std::cin.fail() == true) {
       std::cout << "上面的getline没有读取到换行符" << std::endl;
       std::cin.clear();
       //如果想清除缓冲区， 用如下方法,如果不清除， 下面的getline(address,size)会接收到剩下的字符
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   }


    std::cout << "address:" << std::endl;
    std::cin.getline(address, size);
    std::cout << "address is: [" << address << "]" << std::endl;
}

```

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
##### new与delete
```cpp
#include <iostream>

int main() {

	int* p = new int;//开辟int变量空间
	*p = 100;
	std::cout << "*p = " << *p << std::endl;
	delete p;

	int count = 3;//不用const也行
	int* pb = new int[count];//开辟数组空间
	pb[0] = 1;
	pb[1] = 2;
	pb[2] = 3;
	std::cout << "pb[2] = " << pb[2] << std::endl;
	std::cout << "pb[3] = " << *(pb+2) << std::endl;
	delete []pb;
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

##### 数组类
```cpp
#include <iostream>
#include <array>
using namespace std;
int main() {
	array<int, 3> my_a = {};
	my_a.at(0) = 1;
	my_a.at(1) = 2;
	my_a.at(2) = 3;
	std::cout << my_a.back() << std::endl;//最后一个元素
	std::cout << my_a.front() << std::endl;//第一个元素
	auto p = my_a.begin();//获取第一个元素的迭代器
	std::cout << *(p + 1) << std::endl;//打印第二个元素	
}
```

##### 数组
```cpp
#include <iostream>
using namespace std;
int main() {
	int int_array[] = {1,2,3,4};
	std::cout << sizeof(int_array) / sizeof(int) << std::endl;
	float test = { 1.234 };
	std::cout << test << std::endl;
}
```

##### cin读取到特定字符再退出1
```cpp
#include <iostream>
int main() {

	using namespace std;
	cout << "input:";
	char ch{};
	cin >> ch;
	int count = 0;
	while (ch != '#')
	{
		cout << ch;
		count++;
		cin >> ch;
	}
	cout << "count: " << count << std::endl;
}
```

##### 读取到特定字符再退出2
```cpp
#include <iostream>
using namespace std;
int main() {
	//------------用get改写
	cout << "input:";
	char ch2{};
	cin.get(ch2);
	while (ch2 != '#') {
		std::cout << ch2;
		cin.get(ch2);
	}
}
```

##### 打开文件
```cpp
#include <iostream>
#include <fstream>
#include <string>
/*
读取文件用 ifstream file("test.txt");
std::getline(file, swap_line); //getline要include string才能用
std::cout << swap_line << std::endl;
*/
using namespace std;
int main() {
	std::ofstream ofile;

	ofile.open("test.txt", 'a');
	std::cout << "please input text:";
	std::string text{};
	std::getline(std::cin, text);
	std::cout << "text: " << text << std::endl;
	ofile << text;
	ofile.flush();
	ofile.close();

	//------------打开文件
	std::ifstream ifile;
	ifile.open("1test.txt");
	if (!ifile.is_open()) {
		std::cout << "文件打开失败" << std::endl;
		std::cout << EXIT_FAILURE << std::endl;
		//exit(EXIT_FAILURE);
	}
	std::cout << "文件打开成功" << std::endl;

	std::cout << "请输入文件地址:";
	std::string filename_input;
	cin >> filename_input;
	ifile.open(filename_input);
	if (!ifile.is_open()) {
		std::cout << "文件打开失败" << std::endl;
		std::cout << EXIT_FAILURE << std::endl;
		//exit(EXIT_FAILURE);
	}
	std::cout << "文件打开成功" << std::endl;
}
```

##### 指针
```cpp
#include <iostream>
void testc(char*);
int main() {
	const char* test[] = {"this is a test", "two"};
	std::cout << *test << std::endl;
	std::cout << *(test+1) << std::endl;
	char t[2] = {'a','\0'};
	testc(t);
}
void testc(char* t) {
	std::cout << t << std::endl;
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




* * *
## 类

##### 如果一个函数的参数为一个父类的引用， 可以传它的子类的引用进去
```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void print_test(istream &os);
int main() {

	//父类的函数引用参数，可以传子类实参过去， 如istream的子类是ifstream, 函数参数为ostream &os时，
	// os可以传ofstream作为参数
	const char* filename = "test.txt";
	ifstream getfile;
	getfile.open(filename);
	print_test(getfile);
}
void print_test(istream& os) {
	//传送了一个ofstream参数过来
	std::string swap_line;
	while (std::getline(os, swap_line)) {
		std::cout << swap_line << std::endl;
	}

}
```

##### 父类构造函数与析构函数对于子类的作用
```cpp
#include <iostream>

class A {
public:
    A() {
        std::cout << "这是父类的构造函数" << std::endl;
    }
    ~A() {
        std::cout << "这是父类的析构函数" << std::endl;
    }
};
class a :public A {
public:
    a() {
        std::cout << "这是aaaa的构造函数" << std::endl;

    }
    ~a() {
        std::cout << "这是父类aaa的析构函数" << std::endl;
    }
};

int main()
{
    a mya;//除了调用自身的构造与析构， 还用调用父类的构造与析构

}
```

##### 复制构造函数
```cpp 
#固定格式
/*
class 类名 {
public:
    // 复制构造函数
    类名(const 类名& 引用名) {
        // 复制逻辑
    }
};
*/
#include <iostream>

class Test {
public:
    Test(Test& t) {
        std::cout << "复制构造函数被调用了" << std::endl;
    }
    Test() {
    }
};
int main()
{
    Test t;
    Test a = t;
    Test *b = new Test();

}
/*
1. 显式复制初始化
2. 函数对象参数按值传递
3. 函数返回的值为对象
4. 容器插入元素，如vec.push_back(obj)
5. 用另一个对象初始化新对象
6. 异常处理中的对象复制
try {
    throw T();  // 抛出异常对象时可能复制
} catch (T e) {  // 捕获异常时复制
    // ...
}
*/
```

##### 虚函数与纯虚函数
```cpp
#include <iostream>
#include <map>

//父类中使用 virtual void func() = 0; 声明纯虚函数，子类必须实现
//只在父类中写virtual就行， 子类可写可不写， 但建议写上
class Test {

    virtual void test() {
    }
    virtual void test2() = 0;
};
class Dog :public Test {
    virtual void test() {
        //相当于重写
    }
    void test2() {
        //必须要重写实现
    }
};
int main()
{
    //当设置为虚函数时， 引用或指针会查找 所属类型 
    //如果所属是 Dog, 就用Dog的test(), 如果所属是Test就用Test的test()
    ////Test &a = new Dog()   Dog中的test（）， 因为引用的值是Dog类
    //Test &b = new Test()  父类中的test（）， 因为引用的值是Test类
 
    //当没有设置虚函数时， 引用或指针调用的相应函数会是父类中的test() 
    //Test &a = new Dog()   父类中的test（）， 因为a是父类引用
    //Test &b = new Test()  父类中的test（）， 因为b是父类引用

    //也就是设置为虚函数后， 会按实际类型调用相应虚函数， 与父类没有关系
    /*
}

/*
//其他例子：
class Parent {
public:
    // 虚函数声明
    virtual void print() {
        std::cout << "Parent::print()" << std::endl;
    }
    
    // 非虚函数（仅作对比）
    void nonVirtualPrint() {
        std::cout << "Parent::nonVirtualPrint()" << std::endl;
    }
};

class Child : public Parent {
public:
    // 重写父类的虚函数
    void print() override {  // 使用override显式标记重写（C++11起支持）
        std::cout << "Child::print()" << std::endl;
    }
    
    // 重写父类的非虚函数（不推荐这样做）
    void nonVirtualPrint() {
        std::cout << "Child::nonVirtualPrint()" << std::endl;
    }
};

int main() {
    // 创建子类对象
    Child child;
    
    // 1. 通过子类对象直接调用（与虚函数无关）
    child.print();  // 输出：Child::print()
    child.nonVirtualPrint();  // 输出：Child::nonVirtualPrint()
    
    // 2. 通过父类指针调用（关键：虚函数实现多态）
    Parent* parentPtr = &child;
    parentPtr->print();  // 输出：Child::print()（动态绑定）
    parentPtr->nonVirtualPrint();  // 输出：Parent::nonVirtualPrint()（静态绑定）
    
    // 3. 通过父类引用调用（同样实现多态）
    Parent& parentRef = child;
    parentRef.print();  // 输出：Child::print()（动态绑定）
    parentRef.nonVirtualPrint();  // 输出：Parent::nonVirtualPrint()（静态绑定）
    
    return 0;
}   
    */
```

##### 友元函数
```cpp
#include <iostream>

class MyClass {
private:
    int value;
public:
    MyClass(int val) : value(val) {}

    // 声明友元函数
    friend std::ostream& operator<<(std::ostream& os, MyClass& obj);
};

// 定义全局函数
std::ostream& operator<<(std::ostream& os,  MyClass& obj) {
    os << "MyClass(value=" << obj.value << ")"; // 可以访问私有成员
    return os;
    //(cout << a) << b , 这个运算符重载规定第一个参数是ostream, 返回也是ostream
}

int main() {
    MyClass obj(42);
    std::cout << obj << std::endl; // 输出: MyClass(value=42)
    return 0;
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
##### 类中的转换函数， 比如一个类stu, 你想要int a = stu, 相当于把stu转换为int类型
```cpp
#include <iostream>

class Test {
public:
    operator int() {
        std::cout << "我是类对象， 现在转化成了一个int类型" << std::endl;
        return '0';
    }
};

int main()
{
    Test t{};
    int a = t;
}
```


* * *
## 指针

##### 智能指针
```cpp
#include<iostream>
class stu {};
int main(){
    //智能指针
    std::unique_ptr<stu> fortest = std::unique_ptr<stu>();
    fortest = std::make_unique<stu>("fortest", 123);
    std::unique_ptr<stu> fortest2(new stu("fortest2", 123));
    auto fortest3 = std::make_unique<stu>("fortest3", 1);
    std::cout << fortest->name << fortest2->name << fortest3->name << std::endl;

    /*
    // unique_ptr：独占所有权，禁止拷贝
std::unique_ptr<MyClass> uptr1 = std::make_unique<MyClass>();
// std::unique_ptr<MyClass> uptr2 = uptr1; // 错误！禁止拷贝
std::unique_ptr<MyClass> uptr2 = std::move(uptr1); // 正确：转移所有权

// shared_ptr：共享所有权，允许拷贝
std::shared_ptr<MyClass> sptr1 = std::make_shared<MyClass>();
std::shared_ptr<MyClass> sptr2 = sptr1; // 正确：拷贝，引用计数+1
    */
	return 0;
}
```
