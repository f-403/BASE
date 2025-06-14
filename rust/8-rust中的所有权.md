---
layout: post
tags: [rust]
---


```rust

use std::io;
#[derive(Debug)]
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

fn main() {

    let num = String::from("abcd");

    let num2 = num;//这里所有权会变更， 也就是说， 赋值 后num会消失了。
    //println!("num = {}", num);
    println!("num2 = {}", num2);
    //字面具体的值不会发生所有权变动， 如int, 硬编码的字符串如"abcd", 元组，布尔
    let a = 1;
    let b = a;//这里a还存在栈上
    //也就是是， 在 栈 上的， 会发生自动copy, 在堆上分配的， 不会自大动copy, 并且会发生所有权变动
    //函数传参也一样， 当参数是可copy的类型， 除非离开作用域 ， 要不都会copy过去
    //如果参数是非copy的， 如String::from堆上分配的东西， 所有权会变动， 传过去后原变量不可用
     //而用传过去给那个函数后， 函数调用完也会删除它
    check(&num2);
    //println!("字符串num2是:{}", num2); 这里会出错， 因为字符串传过去后已发生所有权变动， num2在这作用域内不存在了
    let string_check = String::from("test");
    //check(string_check);
    let new_check = &string_check[0..2];




        let user1 = User {
            email: String::from("someone@example.com"),
            username: String::from("someusername123"),
            active: true,
            sign_in_count: 1,
        };

    println!("user1 is: {:#?}", user1);
    let user2 = &user1;
}
fn check(get_str :&String) {
    println!("我获得了字符串:{}", get_str);
    for i in get_str.as_bytes() {
        println!("i = {}", i);
    }
    println!("as_bytes返加回值为:{:?}", get_str.as_bytes());
    println!("\x41\x42\x43\x44");
    println!("字符串已被删除。");
}

```