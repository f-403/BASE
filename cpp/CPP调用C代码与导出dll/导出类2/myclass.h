#pragma once

#ifdef MYCLASSDLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API myclass {
public:
	myclass();
	~myclass();
	void my_class_test();
};

extern "C" {
	DLL_API myclass* create_myclass();
	DLL_API void delete_myclass(myclass* my_class);
	DLL_API void myclass_function(myclass* my_class);
}