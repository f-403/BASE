---
layout: post
tags:[linux, ssh, others]
---


```bash
#man ssh
ssh -L localhost:8080:192.168.20.130:80 kali@localhost
#把远程主机192.168.20.130:80转换到本机8080上来
#访问本机8080相当于访问远程主机80

ssh -R 8888:localhost:80 kali@localhost
#ssh -R 远程主机:远程端口:本地主机:本地端口 ssh登录认证信息
#把本地80l转换到远程主机8888上去， 远程主机可省略
#访问远程机的8888相当于防问本机80
```