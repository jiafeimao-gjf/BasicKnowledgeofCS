---
title: 使用 oh-my-zsh
categories:
  - linux
tags:
  - oh-my-zsh
date: 2024-06-29 11:52:26
---
> 参考博客 https://blog.csdn.net/a143730/article/details/135573409

## zsh 介绍
zsh 是一个兼容 bash 的 shell，相较系统原本的 bash 具有以下优点：

- Tab 补全功能强大。命令、命令参数、文件路径均可以补全。
- 插件丰富。快速输入以前使用过的命令、快速跳转文件夹、显示系统负载这些都可以通过插件实现。
- 主题丰富，可定制性高。

## Oh My Zsh 是什么
Oh My Zsh 是一款社区驱动的命令行工具，正如它的主页上说的，Oh My Zsh 是一种生活方式。它基于 zsh 命令行，提供了主题配置，插件机制，已经内置的便捷操作。给我们一种全新的方式使用命令行。

- Oh My Zsh 是基于 zsh 命令行的一个扩展工具集，提供了丰富的扩展功能。
- 安装 Oh My Zsh 前提条件：必须已安装 zsh
- 笔者是 Mac 系统，以下操作都是基于 Mac 系统或者 Ubuntu。（其他Linux发行版安装方式大同小异）
- oh-my-zsh官网：https://ohmyz.sh/

## 安装流程

mac自带zsh，通过homebrew安装即可
```shell
brew install zsh
```


### 安装 oh-my-zsh
安装 oh-my-zsh 之前，需要确保本地已经安装了 git。

（如果没装git，Mac用户请 ：brew install git，Linux使用sudo apt install git）

使用 curl 下载脚本并安装：
```shell
sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
#没有梯子的使用国内镜像源
sh -c "$(curl -fsSL https://gitee.com/shmhlsy/oh-my-zsh-install.sh/raw/master/install.sh)"
```
或者使用 wget 下载脚本并安装：
```shell
sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"
```
然后同意使用 Oh-my-zsh 的配置模板覆盖已有的 .zshrc：


## 主题自定义

> 官网 https://github.com/ohmyzsh/ohmyzsh/wiki/Themes

### 查看主题：
这些内置主题已经放在 ~/.oh-my-zsh/themes 目录下，不需要再下载。
```bash
cd ~/.oh-my-zsh/themes
```
### 修改主题：
cd到用户目录之下
```shell
cd ~
```
使用 vim 编辑 .zshrc，修改以下内容并保存：
>（不会用vim的，i键插入，编辑完esc键，然后输入:wq保存并退出）

```shell
# 打开zsh配置文件
vim ~/.zshrc 

#找到这一行修改
ZSH_THEME="要修改的主题名称"
```
最后，执行 `source ~/.zshrc` 配置生效
```shell
source ~/.zshrc
```

### 体验随机主题
设置以下内容：
```shell
ZSH_THEME="random"
```

