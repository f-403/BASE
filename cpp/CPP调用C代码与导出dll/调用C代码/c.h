#pragma once
//上面的语句保证头文件只导入一次
// 

#ifdef __cplusplus
extern "C" {  // C++ 环境下启用 extern "C"，告诉CPP编译器不要修改函数名
#endif
//这里用两个ifdef包住两头， 目的是使这段代码能用于C和CPP， 
//如果编译器是C， 这里的前面"extern c {"与后面的 "}"被跳过， 从而使C能正确声明函数
	void c_print();  // 对 C 和 C++ 均可见
	int add(int, int);

#ifdef __cplusplus
}  // 结束 extern "C" 块
#endif

//在另一个文件中实现这两个函数

