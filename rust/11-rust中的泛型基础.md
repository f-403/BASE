---
layout: post
tags: [rust]
---

```rust
//添加类型限制， 只能用于有Add的， 也就是数字型
fn add<T: std::ops::Add<Output = T>>(a:T, b:T) -> T {
    a + b
}
//#定主一个结构
struct test {
    a:i32,
    b:String
}
//为结构添加方法
impl test {
    fn test_print(&self){
        println!("这是结构实例的方法.");
    }
}

struct test2<T> {
    a:T,
}
impl <T: std::fmt::Debug> test2<T> {
    fn test2_print(&self){
        println!("{:?}",
                 &self.a);
    }
}
//定义特定的泛型
impl test2<i32> {
    fn result(&self) {
        println!("a + a = {}", &self.a+&self.a)
    }
}

fn main() {
    println!("add i8: {}", add(2i8, 3i8));
    println!("add i32: {}", add(20, 30));
    println!("add f64: {}", add(1.23, 1.23));
    //println!("add f64: {}", add("a", "b"));
    //结构实体
    let t = test{ a: 0, b:"test".to_string() };
    t.test_print();
    let t2 = test2{a:String::from("test2")};
    t2.test2_print();
}
```