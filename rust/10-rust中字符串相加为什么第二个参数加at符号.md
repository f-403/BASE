---
layout: post
tags: [rust]
---

```rust
use std::ops::Add;

fn main() {
   let name = String::from("admin");//相当于把&str切片类型转为string类型
  //string类型转为&str切片类型，直接加 &在变量前即可
  let pass = String::from("password");
  let done = name+&pass;
  //这里第二个参数为什么加&是因为， 内部会调用 add函数, 原型为 fn add(self, &str) -> String,
  //let done2 = done.add(&name);//这里不能这样用呢， 因为第7行， 相加后， name会发生所有权转移后消失掉了， 不存在了
  let done2 = done.add("hello").add("world");
  //相当于 done2 = done + "hello" + "world", 运行后done已发生所有权转移， 之后done在内存消失掉了
  //println!("namd + pass = {}", done);
  println!("done2 = {}", done2);
}
```