---
title: 使用hexo
date: 2019-12-15 18:59:47
categories:
- 博客配置
tags: 
- hexo
---
## 1、预备工作
- 官网看一看，即可安装 git, node, ssh, in your pc
- 在GitHub上得有一个账号

## 2、使用npm安装hexo
```bash
$ npm install -g hexo
```
## 3、本地pc环境初始化
### hexo初始化
```bash
$ hexo init project-name #等待片刻
```
### 本地启动测试
```bash
$ hexo s
```
此时，浏览器中打开默认的网址。

## 4、创建github仓库
### 现在官网创建名称为 xxx.github.io的仓库
> 注意：
> - xxx为你的github的昵称，
> - 创建一个readme文件（空仓库无法创建github pages）
> - 仓库是公开的，否则要开会员才行

### 设置github pages
- 选择master分支，就行了

## 5、hexo与github仓库绑定
### 修改_config.yml文件
修改文件最后的`deploy`标签：
```yml
deploy:
    type: git
    repository: https://github.com/xxxxxx/xxx.github.io.git
    branch: master
```
### 创建静态页面
```bash 
$ hexo g
```
### 部署下载github仓库
```bash
$ hexo d
```
> 1）可能找不到git, 使用npm 安装一个插件:  
> `npm install hexo-deployer-git --save`  
> 2）可能要输入github的**正确的**账户名密码

再次执行`hexo d` or `hexo deploy`
此时，浏览器中打开网址https://xxxxx.github.io。
## 6.发布文章
- 终端cd到project-name文件夹下，执行如下命令新建文章：
```bash
$ hexo new artical-name
```
名为artical-name.md的文件会建在目录/project-name/source/_posts下。


- 文章编辑完成后，终端cd到blog文件夹下，执行如下命令来发布: 
```bash
$ hexo generate             # 生成静态页面
$ hexo deploy            # 将文章部署到Github
```