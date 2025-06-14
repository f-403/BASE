---
layout: post
tags: [rust]
---


```rust

#[derive(Debug)]
struct Web {
    title: String,
    size: u32,
}
impl Web{
    fn get_title(&self) -> &String{ //相当于fn get_title(myweb: &Web) {}借用所有权， 不要传递所有权过来。
        &self.title
    }
    fn get_size(&self) -> u32 {
        self.size
    }
    //第一个参数不是self时， 是关联函数， 调用时要这样调用: Web::XXXX()
    fn web_new(size: u32) -> Web{
        Web{
            title: String::from("这是web_new新添加的"),
            size:size,
        }
    }
}
//有名字但没字段的结构钵叫单元结构体
struct test;

//在枚举中定义的结构体还可以没名字
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}
fn main() {
    let myweb = Web {
        title: String::from("百度一下"),
        size: 10086,
    };
    println!("myweb is {:#?}", myweb);
    println!("title = {}, size = {}", myweb.get_title(), myweb.get_size());
    println!("{}", myweb.title);
    println!("新变量为: {:?}",Web::web_new(100));
    
    //元组
    let tup = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of y is: {}", y);
}

```