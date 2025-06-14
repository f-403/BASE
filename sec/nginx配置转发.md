---
layout: post
tags: [others, 渗透测试, cs]
---

配置文件
```bash
 #/etc/nginx/sites-available
 #forword
  location ~*/jquery* {

      #start with jquery

      proxy_pass  https://127.0.0.1; #转到到本机的443
      #forword to the cs IP:address
    }
	##
```
>> 可设置cs转发

参考:<br>
https://nginx.org/en/docs/<br>
https://nginx.org/en/docs/

