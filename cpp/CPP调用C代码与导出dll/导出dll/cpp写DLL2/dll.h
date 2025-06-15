#pragma once


extern "C" __declspec(dllexport) void test();
extern "C" __declspec(dllexport) void add(int,int);
/*
#pragma once

#ifdef __cplusplus
extern "C" {  // 如果是 C++ 代码，用 extern "C" 包裹
#endif

    __declspec(dllexport) void test();
    __declspec(dllexport) void add(int, int);

#ifdef __cplusplus
}
#endif
*/

/*
#pragma once

#ifdef MYDLL_EXPORTS  // 在 DLL 工程中定义 MYDLL_EXPORTS
    #define MYDLL_API __declspec(dllexport)
#else
    #define MYDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {  // 确保 C++ 编译器使用 C 风格的名称修饰
#endif

    MYDLL_API void test();
    MYDLL_API void add(int a, int b);

#ifdef __cplusplus
}
#endif
//这种写法， 要在项目属性 → C/C++ → 预处理器 → 预处理器定义 中添加 MYDLL_EXPORTS。
*/

/*
// 不关心导入，只关心导出
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    #define MYDLL_API __declspec(dllexport)  // 始终导出
    MYDLL_API void test();
    MYDLL_API void add(int a, int b);

#ifdef __cplusplus
}
#endif
*/

