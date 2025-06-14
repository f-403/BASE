---
layout: post
tags: [rust]
---

```bash
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

fn main() {
   let myweb = Web {
       title: String::from("百度一下"),
       size: 10086,
   };
    println!("myweb is {:#?}", myweb);
    println!("title = {}, size = {}", myweb.get_title(), myweb.get_size());
    println!("{}", myweb.title);
    println!("新变量为: {:?}",Web::web_new(100));
}

```