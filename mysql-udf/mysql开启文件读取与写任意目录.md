### MySQL 开启LOAD_FILE()函数与配置写文件权限

```
要在 MySQL 中启用LOAD_FILE()函数并允许写入文件到任意目录，需要修改 MySQL 配置文件并调整安全参数
```
#### 1. 检查当前配置状态
```bash
首先查看当前 MySQL 是否允许文件导入导出：
SHOW VARIABLES LIKE 'secure_file_priv';
SHOW VARIABLES LIKE 'local_infile';
secure_file_priv 的值决定了导入导出文件的目录限制
local_infile 控制是否允许加载本地文件
```

#### 2. 修改 my.cnf 配置文件
```bash
找到 MySQL 配置文件（通常是/etc/mysql/my.cnf或/etc/my.cnf），添加或修改以下参数：
[mysqld]
# 允许LOAD_FILE()函数读取任意文件
secure_file_priv = ""  # 空值表示不限制目录

# 允许导入本地文件（如果需要）
local_infile = 1
```