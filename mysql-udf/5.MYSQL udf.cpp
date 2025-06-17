#include <iostream>
#include <mysql.h> //配置好include/lib

char* test_udf(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* result,
    unsigned long* length,
    char* is_null,
    char* error
);

my_bool test_udf_init(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* message
);

int main() {
    
    std::cout << (char*)1 << std::endl;

    //为了好测试， 我这里定义了一些变量用来测试
    UDF_INIT initid{ 0 };
    UDF_ARGS args{  };
    char* test[] = { (char*)"abcdccc", (char*)"b" };//模拟参数传递
    args.args = test;
    char* result{ 0 };
    unsigned long* length{ 0 };
    char* is_null{ 0 };
    char* error{ 0 };


    std::cout << "size:" << strlen(args.args[0]) << std::endl;
    //设置一下参数个数
    args.arg_count = sizeof(test) / sizeof(test[0]);
    test_udf(&initid, &args, result, length, is_null, error); //用户自定义函数

    char message[MYSQL_ERRMSG_SIZE]{};
    test_udf_init(&initid, &args, message); //调用初始函数

    
    std::cout << MYSQL_ERRMSG_SIZE << std::endl;
    


    return 0;
}

/*
my_test_udf_init()//在我PHPSTUDY mysql 5.7.26没写这个不行，高用my_test_udf之前会调用这个
my_test_udf()
my_test_udf_deinit()//前面一段要名字对应， 调用my_test_udf之后会调用这个

args 存有你的函数test_udf()的参数信息
result 你要返回的数据存入这里
length 你返回的数据长度， 要与result配合一起用

is_null 如果你返回null, 这里要设置为: *is_null=1并return NULL

message init函数出错后返回的信息存在这里， 大小有一个自带的大小

这些函数的参数是固定形式的，规定是这样
*/



char* test_udf(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* result,
    unsigned long* length,
    char* is_null,
    char* error
) {

    std::cout << "test_udf" << std::endl;
    return NULL;

}

my_bool test_udf_init(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* message //你要把信息存入message, mysql会自动显示
) {
    //如果参数大于1， 就返回message信息
    //为了测试
    memcpy(message, "MY-ERROR", MYSQL_ERRMSG_SIZE);
    std::cout << "arg_count = "  << args->arg_count << std::endl;
    message[MYSQL_ERRMSG_SIZE-1] = '\0';

    
    if (args->arg_count != 1) {
        //std::cout << "arg_count == 0" << std::endl;
        std::cout << message << std::endl;
        return 1;  //这里要返回1， MYSQL才会显示你的message信息
        // xxx : MY-ERROR
    }

    return 0;//没有错就返回0， 有错返回1， 并把出错信息存入message, message大小为MYSQL_ERRMSG_SIZE
}
