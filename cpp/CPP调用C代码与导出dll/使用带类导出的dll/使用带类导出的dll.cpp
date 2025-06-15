#include <iostream>
#include <windows.h>

class MyClass; // 前向声明即可


int main() {
    HMODULE hDLL = LoadLibraryA(R"(C:\Users\who\Desktop\allthethings\c#\导出类\x64\Debug\导出类.dll)");
    if (!hDLL) {
        std::cerr << "加载 DLL 失败！" << std::endl;
        return 1;
    }

    using CreateFunc = MyClass * (*)();
    using DeleteFunc = void (*)(MyClass*);
    using SayHelloFunc = void (*)(MyClass*); // 👈 新增，对象的方法

    CreateFunc create = (CreateFunc)GetProcAddress(hDLL, "CreateMyClass");
    DeleteFunc destroy = (DeleteFunc)GetProcAddress(hDLL, "DeleteMyClass");
    SayHelloFunc sayHello = (SayHelloFunc)GetProcAddress(hDLL, "MyClass_sayHello");

    if (!create || !destroy) {
        std::cerr << "获取函数指针失败！" << std::endl;
        return 1;
    }

    MyClass* obj = create();   // 创建对象
    sayHello(obj);

    destroy(obj);              // 销毁对象
    FreeLibrary(hDLL);         // 卸载 DLL

    return 0;
}
