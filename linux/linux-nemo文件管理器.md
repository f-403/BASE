---
layout: post
tags: [linux]
---

先安装:

```bash
sudo apt install nemo
```

再设置:

```bash
xdg-mime default nemo.desktop inode/directory application/x-gnome-saved-search
gsettings set org.gnome.desktop.background show-desktop-icons false
gsettings set org.nemo.desktop show-desktop-icons true
```

查看当前文 件管理器:

```bash
xdg-mime query default inode/directory
```

如果要修改回gnome默认的, 用如下命令:

```bash
xdg-mime default nautilus*.desktop inode/directory application/x-gnome-saved-search
gsettings set org.nemo.desktop show-desktop-icons false
gsettings set org.gnome.desktop.background show-desktop-icons true
```
