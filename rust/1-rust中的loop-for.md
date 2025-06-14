---
layout: post
tags: [rust]

---

if - while - loop - for

```rust
use std::io;
use rand::Rng;
use std::cmp::Ordering;
fn main() {
    loop {
        println!("请输入一个数字：");
        let mut name = String::new();
        std::io::stdin().read_line(&  mut name).expect("输入出错。");
        let rng = rand::thread_rng().gen_range(1..=10);
        let mut err= 0;
        let name :u32 = match name.trim().parse(){
            Ok(value) => value,
            Err(_) => {continue},
        };
        println!("你输入的数字是:{}, 其实数字是: {}", name, rng);
        match name.cmp(&rng){
            Ordering::Greater => {println!("猜得太大了。")},
            Ordering::Less => {println!("太小了。")},
            Ordering::Equal => {println!("你猜对啦.");return;}
        }
    }

}

```

![test](../../images/rust.svg) 