---
layout: post
tags: [rust]
---


rust中的option：

```rust
fn main() {

    let mut a = Option::Some(123);
    let b = plus_(a);
    let c = None;//设置一个None值， 解开时用unwrap_or设置一个default值， 当是None时会返回default值
    println!("c = {:}, and b is: {:}", c.unwrap_or("no string"), b.unwrap());//用unwrap解出来


}
fn plus_(swap:Option<i32>) -> Option<i32> {
    match swap {
        Some(swap)=> Some(swap+1),//Some(swap) => swap+1
        None => None
    }
}
```