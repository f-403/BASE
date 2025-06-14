---
layout: post
tags: [rust]
---

```rust

fn print_array_one<T: std::fmt::Debug>(arr:[T;3]) {
    println!("{:?}", arr);
}

//指定类型T与长度N， 跟C/CPP类传，数组中如果要用个变量指定长度， 定义时要为const
fn print_array_all<T : std::fmt::Debug, const N:usize>(arr:[T;N]) {
    println!("{:?}", arr)
}

fn main() {
    //数组
    let arr_a = [1,2,3];
    let arr_b :[&str; 2] = ["root", "password"];
    print_array_one(arr_a);
    //可定义可变参数的的泛型函数， 要利用const指定参数长度
    print_array_all(arr_a);
    print_array_all(arr_b);
}
```