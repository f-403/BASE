#pragma once

#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

extern "C"  {
    MYDLL_API int add(int a, int b);
    MYDLL_API void test();
}

////这种写法， 要在项目属性 → C/C++ → 预处理器 → 预处理器定义 中添加 MYDLL_EXPORTS。