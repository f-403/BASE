---
layout: post
tags: [linux]
---

一般在运行`apt upgrade`时会自动更新Linux内核，但是有些时候更新内核后会出现驱动程序不兼容的情况。
 我们可以使用以下命令降级内核：



```bash
sudo dpkg --get-selections | grep linux #查看已安装的内核
sudo apt remove linux-image-x.xx.x-xx-generic #删除新内核
sudo apt install linux-image-x.xx.x-xx-generic #安装原内核
```



也可以使用以下命令阻止apt更新内核：

```bash
sudo apt-mark hold linux-image-generic linux-headers-generic
sudo apt update
sudo apt upgrade
```



使用以下命令解除阻止：

```bash
sudo apt-mark unhold linux-image-generic linux-headers-generic
#sudo apt-mark showhold#显示hold的包
sudo apt update

```
