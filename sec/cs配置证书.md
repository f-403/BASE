---
layout: post
tags: [渗透测试]
---



#### 1. 查看证书:
```bashtool -list -v-keystorecobaltstrike.store```


#### 2.生成证书:
```bash
0X1 自签名证书:
keytool -keystore cobaltstrike.store -storepass 密码密 -keypass 密码 -genkey -keyalg RSA-alias -alias 自定义别名 google.com-dname “CN=(名字与姓氏 名 ), OU=(组织单位名称 组 ), O=(组织名称 组 ), L=
(城市或区域名称 城 ), ST=(州或省份名称 州 ), C=(单位的两字母国家代码 单 )”

例子:
keytool -keystore 生成的store名 -storepass 密码 -keypass 密码 -genkey -keyalg RSA  -dname "CN=Microsoft Windows, OU=MOPR, O=Microsoft Corporation, L=Redmond, ST=Washington, C=US"

keytool -keystore new.store -storepass bypass -keypass bypass -genkey -keyalg RSA -alias apex.tk -dname "CN=Microsoft Windows, OU=MOPR, O=Microsoft Corporation, L=Redmond, ST=Washington, C=US"

360
keytool -keystore cobaltstrike.store -storepass 123456 -keypass 123456 -genkey -keyalg RSA -alias 360.com -dname "CN=US, OU=360.com,
O=Sofaware, L=Somewhere, ST=Cyberspace, C=CN"
baidu
keytool -keystore cobaltStrike.store -storepass 123456 -keypass 123456 -genkey -keyalg RSA -alias baidu.com -dname "CN=ZhongGuo, OU=CC,
O=CCSEC, L=BeiJing, ST=ChaoYang, C=CN"
```
>> 备注：默认值直接按回车就好

0x2 正规的ssl证书设置:
```bash
用法:
openssl pkcs12 -export -in PEM文件.pem -inkey KEY文件.key -out  创建的P12文件.p12 -name 你的网址名 -passout pass:密码
生成:
keytool -importkeystore -deststorepass 密码 -destkeypass 密码 -destkeystore 要导入到cobalstrike的文件.store -srckeystore 上面自定义的p12文件.p12 -srcstoretype PKCS12 -srcstorepass 密码 -alias 设置别名

例如：
openssl pkcs12 -export -in 1.pem -inkey 1.key -out 1.p12 -name xxx.com -passout pass:123.com

keytool -importkeystore -deststorepass 123.com -destkeypass 123.com -destkeystore cobalstrike.store -srckeystore 1.p12 -srcstoretype PKCS12 -srcstorepass 123.com -alias xxx.com

```

#### 3. 为teamservers配置证书路径
```bash
./TeamServerImage -Dcobaltstrike.server_port=50050 -Dcobaltstrike.server_bindto=0.0.0.0 -Djavax.net.ssl.keyStore=证书路径 -Djavax.net.ssl.keyStorePassword=证书密码 teamserver $* 
```
>> 上面是cs4.9.1中的teamserver文件

#### 4.设置混淆配置文件
```bash
https://github.com/threatexpress/malleable-c2

为配置文件设置证书路径与密码
    set keystore "证书路径";
    set password "证书密码";
```
>> 这文件能用于修改User-Agent并用于ngrok内网转发

#### 5. 配置文件测试有没有错误
```bash./c2lint c2/jquery-c2.4.3.profile```

#### 6.最后启动

```basho ./teamserver 192.168.1.10 123456 js-4.9.profile ```


