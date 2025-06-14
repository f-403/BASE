---
layout: post
tags: [rust]
---



```rust
use std::any::{Any, type_name};

fn main() {


    //格式 let name = &切片[..]
    let mut data:Vec<&str> = Vec::new();
    data.push("this");
    data.push("is");
    data.push("test");

    println!("{:?}", &data[0..1]); //注意格式， 要加  & 符号
    //show(data);//所有权一起传送
    show(&mut data);//可变借用
    //show(&data);//不可变借用
    println!("{:?}", data);
}
fn show(param: &mut Vec<&str>) {//
    println!("show收到的参数为:{:?}", param);
    param[0] = "this is a test";
}


```