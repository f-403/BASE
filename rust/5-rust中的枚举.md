---
layout: post
tags: [rust]
---



```rust

#
#[derive(Debug)]
enum ipaddr {
    v4, //就是字面值 'v4， 也是这枚举成员的实例
    v6,
    address(String),
    bits(u32,u32,u32,u64),
}
impl ipaddr {
    fn ipaddr_say(&self) {
        println!("这是ipaddr结构体中的ipaddr_say函数.");
    }
    fn _ipaddr_say(){
        println!("这是用枚举单独调用的函数");
    }
}
fn main() {
    let ip4 = ipaddr::v4;//这样就创建了一个ipaddr枚举类型的实例
    println!("ipv4 is: {:?}", ip4);
    let ip: ipaddr = ipaddr::address(String::from("127.0.0.1")); //实例IP
    println!("ip address is: {:?}", ip);
    let b = ipaddr::bits(1,2,3,4); //实例IPADDR
    println!("ipaddress::bits: {:?}", b);
    b.ipaddr_say(); //实例调用函数
    ipaddr::ipaddr_say(&b);//定义时参数为自身的引用， 所以传自身引用
    ipaddr::_ipaddr_say();

}

```