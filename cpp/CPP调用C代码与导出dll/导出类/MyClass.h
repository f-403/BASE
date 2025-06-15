#pragma once

#ifdef MYCLASSDLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

// 导出的类
class DLL_API MyClass {
public:
    MyClass();
    ~MyClass();
    void sayHello();
};

// 工厂函数导出
extern "C" {
    DLL_API MyClass* __cdecl CreateMyClass();
    DLL_API void __cdecl DeleteMyClass(MyClass* ptr);
}

/*
extern "C" {
    DLL_API MyClass* CreateMyClass();
    DLL_API void DeleteMyClass(MyClass* ptr);

   你在哪个平台             能否省略 `          
| Windows 64 位（x64）      ✅ 可以             建议保留            
| Windows 32 位（x86）      ❌ 不建议           最好明确写 `__cdecl` 
| 跨平台 / 外部调用         ❌ 不建议           明确调用约定更安全       

}

*/
