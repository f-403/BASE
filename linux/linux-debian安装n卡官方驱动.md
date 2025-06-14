---
layout: post
tags: [linux]
---

先升级系统:

```bash
sudo apt update

sudo apt upgrade 
```

安装必要的工具：

```bash
sudo apt install gcc make pkg-config
```



禁用nouveau：

在 /etc/modprobe.d 下添加一个配置文 件:

```bash
(nvidia-blacklist.conf)
```

写入如下内容:

```bash
blacklist nouveau

options nouveau modeset=0
```

更新grub:

```bash
sudo update-initramfs -u
```

重启后安装驱动:

```bash
sudo ./Nvdiaxxxxxxxxxxb
```

