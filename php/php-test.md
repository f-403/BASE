---
layout: post
tags: [php]
---

```php
<?php

//$data = var_dump($_POST);
fputs(fopen('test.txt','a'), $_POST['a']);
fputs(fopen('test.txt','a'), $_POST['b']);

```