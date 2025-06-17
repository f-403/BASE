// 1.固定格式函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <mysql.h>
#include <iostream>
#include <windows.h>

extern "C" {
    __declspec(dllexport) char* udf_name(
        UDF_INIT* initid,
        UDF_ARGS* args,
        char* result,
        unsigned long* length,
        char* is_null,
        char* error//参数固定
    );
    __declspec(dllexport) my_bool  udf_name_init(
        UDF_INIT* initid,
        UDF_ARGS* args,
        char* message//参数固定形式
    );
}

void mycmd(wchar_t *cmd) {
    
}
int main()
{
   
}


/*
初始化函数：abc_init
主函数：abc (与CREATE FUNCTION指定的名称一致)
清理函数：abc_deinit
 

 参数格式固定



*/

char* udf_name(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* result,
    unsigned long* length,
    char* is_null,
    char* error//参数固定
) {//参数格式固定

    //实现一个功能:只能输入一个参数，字符串类型， 输入什么参数就打印什么
    //udf_name('123') -> 123/   udf_name('abc') --> abc
    

    //实用参数
    /*
    args->args数组保存有参数列表;
    args->args[0] 第一个参数;
    args->arg_count 参数个数;
    args->arg_type; 参数类型; 字符串，int等;
    if(args->arg_type == STRING_RESULT) {
        std::cout << "string" << std::endl;
    }
    args->lengths[0]; 参数长度; 自带的
        // strlen(args->args[0]) --> 不要这样用， 你不知道参数是什么类型，有自带的， 用自带的；

    result 你要返回的数据就存在这里;
    length 你返回的数据长度;//length与result配对使用
    error=1后， 也要返回NULL， 但错误信息不会终端打印给你看，你要SHOW WARNINGS;

    */
    //如果没有数据返回， 你就返回null, 并设置is_null = 1, 也是配对使用
    if (args->arg_count == 0) {
        *is_null = 1;
        return NULL;//如果你返回了null, result与length设置不设置没关系
    }

    if (args->arg_type[0] != STRING_RESULT) {
        *is_null = 1;
        return NULL;//如果你返回了null, result与length设置不设置没关系
    }


    //如果是字符类型，就直接打印参数
    const char* show_cmd = "cmd: ";
    int show_cmd_leng = strlen(show_cmd);
    memcpy(result, show_cmd, show_cmd_leng);
    memcpy(result+show_cmd_leng, args->args[0], args->lengths[0]);

    *length = args->lengths[0]+show_cmd_leng;  //如果有数据返回， 就一定要设置 length大小
    return result; //默认总大小是多少？是否是动态分配？
}

//规定函数对应关系: test/ test_init /test_deinit
//初始函数， 在我的mysql5.7.26下提示一定要创建
my_bool  udf_name_init(
    UDF_INIT* initid,
    UDF_ARGS* args,
    char* message//参数固定形式
) {

    initid->max_length = 4096;//这个是设置result的默认大小, 相当于result[1024]
    //result在用户自定义函数中设置

    //mysql> select test_udf();
    //ERROR 1123 (HY000) : Can't initialize function 'test_udf'; ARG_COUNT != 1
    //这里的ARG_COUNT != 1就是message的值
    //message为你要设置的信息， 当你想返回信息给用户看时， 要设置message, 并返回1
    //在我的MYSQL5.7.26下message设置中文的话打印不了（默认情况下）
    //if (args->arg_count != 1 ) {
    if (0) {
        //message;设置message, meaasge[MYSQL_ERRMSG_SIZE]，有默认值512
        const char* my_message = "THIS IS A TEST for my function:udf_name";
        int my_message_leng = strlen(my_message);
        memcpy(message,my_message,MYSQL_ERRMSG_SIZE);
        //message[MYSQL_ERRMSG_SIZE - 1] = '\0';
        message[my_message_leng] = '\0';
        return 1;
    }

    

    return 0; //如果返回0， 函数正常

}

/*
//清理函数, 可以不创建
void udf_name_deinit(
    UDF_INIT* initid//参数固定形式
) {

}
*/
