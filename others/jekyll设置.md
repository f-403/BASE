---
layout: post
tags: [others,jekyll]

---



```shell
{%raw%}
layout: 布局， 要在_layouts下创建一个相应的.html文件, 如 layout: get_tag, 你就要创建 _layouts/get_tags.html

tags: 标签， 后面可以直接写字符串形式 tags: abcd, 或者用数组形式  tags: [ruby, c, cpp]

eg:
如果post.tags包含有page.tags,   {%if post.tags contains page.tags %}会返回true

eg:
如果测试tags是否包含 ruby 字符， 可以这样用  {% if post.tags contains 'ruby' %}

由于转义字符 { 及 }, 为了正常显示此页内容，可以用如下方法解决:

1. render_with_liquid: false #jekyll版本要4.0或以上
   #关闭render渲染1
{%endraw%}
2.  {% raw %}{%{% endraw %} raw {% raw %}%}{% endraw %} 代码块...{% raw %}{%{% endraw %} enddraw {% raw %}%}{% endraw %}
 {%raw%}


添加网页上的标签， 如cpp, ruby等， 在_includes/links.html里修改

将标签添加进文章里: {{post.tags}}

_layouts/get_tag.html代码:
---
layout: default
---

<div>
  <h1>Articles tagged with "{{ page.tags}}"</h1><!--eg: tag: [cpp, c]-->
  <ul style='padding-top: 16px;'>

    {% for post in site.posts %}
    <!--{{page.tags}}<br />-->
    {% if post.tags contains page.tags %} 
    #post.title 是否包含当前页面的title, 如果当前页面的title为cpp, 那就查询cpp是否包含在传过来的页面的tags中

    <li><a href="{{ post.url }}">{{ post.title }}</a>  [{{post.tags|join}}] {{ post.date | date: "%Y-%m-%d" }}</li>
    {% endif %}
    {% endfor %}
  </ul>
</div>
{%endraw%}

```





