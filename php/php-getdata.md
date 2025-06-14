---
layout: post
tags: [php]
---

```php
<?php 
    function jmw58($url, $para){
        // 创建一个cURL资源
        $ch = curl_init();

        // 设置URL和相应的选项
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_HEADER, 0);
        curl_setopt ($ch, CURLOPT_POST, true ); 			// post传输数据
        curl_setopt ($ch, CURLOPT_RETURNTRANSFER, 1 ); 	// 显示输出结果
        var_dump($para);
        curl_setopt ( $ch, CURLOPT_POSTFIELDS, $para ); 	// post数据
        // 抓取URL并把它传递给浏览器
        curl_exec($ch);

        // 关闭cURL资源，并且释放系统资源
        curl_close($ch);
    }
    $para = Array('a' =>1, 'b'=>2);
    $r = jmw58("http://127.0.0.1/test.php", $para);
    echo $r;
?>
```