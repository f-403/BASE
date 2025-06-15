
#include <iostream>
#include "myclass.h"

int main()
{
    myclass* m = new myclass();
    m->my_class_test();
    delete m;
    std::cout << "------------" << std::endl;
    myclass *t = create_myclass();
    t->my_class_test();
    delete_myclass(t);

    std::cout << "Hello World!\n";
}

