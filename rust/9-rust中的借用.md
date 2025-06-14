---
layout: post
tags: [rust]
---


```rust
fn main() {
    let mut name = "abcde";
    show(name);
    println!("{}",name);//硬字符串， 直接复制值
    let end = show2(&mut name);//同上
    println!("{}",&name);
    println!("{}", end);

    let new = String::from("这是堆分配的内存");
    show(&new);//借用传递
    show(new.as_str());
    println!("{}", new);
}
fn show(name:&str) {
    println!("{}", name);
    //name = "123";
}
fn show2(num: & mut &str) -> String {
    num.to_ascii_uppercase()
}
```