---
title: 后端入门必备 mysql 安装初始化
categories:
  - 后端
  - 数据库
tags:
  - mysql
date: 2024-06-08 22:33:41
---

## macOS 安装完之后，如何初始化mysql账号密码?

在 macOS 上安装 MySQL 后，可以通过以下步骤初始化账号密码：
- 打开终端。
- 进入 MySQL 安装目录下的 bin 文件夹，例如：
```bash
cd /usr/local/mysql/bin。
```
- 执行初始化命令：
```bash
./mysqld --initialize --user=mysql
```

这会生成一个随机的初始密码。
- 启动 MySQL 服务，例如：
```bash
./mysql.server start # 注意保存好生成的密码
```
- 使用生成的初始密码登录 MySQL，执行：
```bash
./mysql -u root -p
```
然后输入刚才生成的随机密码。登录成功后，就可以修改密码等操作了，例如：
```bash
ALTER USER 'root'@'localhost' IDENTIFIED BY '新密码';。
```

需要注意的是，不同版本的 MySQL 可能在具体操作上会有一些细微差别。