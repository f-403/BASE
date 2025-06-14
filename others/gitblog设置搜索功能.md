---
layout: post
tags: [others]

---


#### 0x1 下载源码
https://github.com/christian-fei/Simple-Jekyll-Search.git

#### 0x2 设置文件
1. 创建 /search.md
2. 创建与 /search.md 对应的 /_layouts/search.html
3. 创建 /js 目录， 并把下载好的 simple-jekyll-search.js 与 simple-jekyll-search.min.js 放到此目录下
4. 把下载好的 search.json 放到 / 下

#### 0x3 设置根目录下 /search.md内容
```bash
---
layout: search
title: search
---
```
这里的layout: search 就是指定layout名字叫search.html, 下一步就是要创建这个文件

#### 0x4 设置_layouts/search.html内容(此文件与 search.md 对应)
```bash
---
layout: default
---
<!-- HTML elements for search -->
<input type="text" id="search-input" placeholder="Search blog posts..">
<ul id="results-container"></ul>



<script src="/js/simple-jekyll-search.min.js"></script>
<script>
    var sjs = SimpleJekyllSearch({
        searchInput: document.getElementById('search-input'),
        resultsContainer: document.getElementById('results-container'),
        json: '/search.json'
    });

</script>
```

#### 0x5 在/_includes/links.html里添加一个名字叫 search 的链接
```bash
<a href="{{ "/search" | prepend: site.baseurl | replace: '//', '/' }}"><h2 class="header-link">search</h2></a>
```