---
layout: post
tags: [ngrok,渗透测试, others]
---


```bash

ngrok start --all --region  ap
#指定地区
#配置文件:

authtoken: XXXXXXXXXX

tunnels:
  httpbin:
    proto: http
    addr: 8080
  demo:
    proto: http
    addr: 443
```
> https://ngrok.com/docs/agent/config/


