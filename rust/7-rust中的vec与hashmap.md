---
layout: post
tags: [rust]
---



```rust
use std::collections::HashMap;

fn main() {
let mut v = Vec::new(); //注意这里类型为 &str 硬编码型形
let mut swap_v = vec!["this", "类型要相同"];
v.push("你");
v.push("好");
if v.contains(&"你") {
println!("打到了字符串 ");
}
println!("{:?}", v);
v[0] = "改";
println!("{:?}", v);
let swap = v[0];//因为是 &str 类型， 这里所有权不会变动
println!("{}", swap );

    let mut myhash = HashMap::new();//use std::collections::HashMap;
    myhash.insert(1, "root");
    myhash.insert(2, "password");
    for i in myhash.keys(){
        println!("{} = {}", i, myhash[i]);
    }

    //hashmap查找

    match myhash.get(&1) {
        Some(values) => {
            println!("获取到的数据为:{:?}", values);
        }//上面获取到的值会来到这里， 所以这里的参数要对应为 &str
        None =>  {println!("没有找到数据。");}//这里直接返回None出错
        _ => ()
    }
    //还有一个叫  HashSet 用法差不多
}
```