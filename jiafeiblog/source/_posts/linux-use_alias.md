---
title: linux之alias使用
date: 2024-06-08 18:59:47
categories:
- linux
tags: 
- alias
---

### alias是什么

`alias` 是一个在Unix/Linux shell（包括MacOS的Terminal中使用的bash或zsh等shell）中用来为命令定义别名的命令。它允许用户为复杂的、常用的或难以记忆的命令创建一个简短且易于记忆的名称，从而提高工作效率。

### 如何使用alias：

#### 创建临时alias（仅限当前终端会话）:
在终端中直接输入以下格式的命令来创建一个临时的alias：

```bash
alias shortname='command_to_be_replaced'
```

例如，如果你经常需要使用 `ls -la` 命令查看包含隐藏文件的详细列表，可以创建一个alias：

```bash
alias ll='ls -la'
```

这样，每次只需输入 `ll` 就能执行 `ls -la`。

#### 永久alias（跨终端会话）:
要使得alias在每次打开终端时都可用，你需要将它们添加到你的shell配置文件中，通常是 `.bashrc`, `.bash_profile`, 或 `.zshrc`，具体取决于你所使用的shell。

1. 打开你的shell配置文件。比如，对于bash，可以使用文本编辑器打开 `.bashrc` 或 `.bash_profile`：

```bash
nano ~/.bashrc
```

或

```bash
nano ~/.bash_profile
```

对于zsh，编辑 `.zshrc` 文件：

```bash
nano ~/.zshrc
```

2. 在文件的末尾添加你的alias定义，例如上面提到的 `ll` alias。

3. 保存并关闭文件。

4. 使更改生效，可以关闭并重新打开终端，或者运行以下命令：

```bash
source ~/.bashrc   # 对于bash
source ~/.zshrc    # 对于zsh
```

#### 查看已设置的alias:
你可以使用 `alias` 命令不带参数来查看当前所有的alias定义。

```bash
alias
```

#### 删除alias:
要删除一个alias，你可以使用 `unalias` 命令，后面跟上alias的名字。如果是永久alias，还需要从配置文件中手动删除相应的行。

```bash
unalias shortname
```

通过合理利用alias，你可以让日常的命令行操作变得更加高效和便捷。

### hexo 博客应用alias

- 快速更新并部署到本地命令

```bash
alias hexogs="hexo generate && hexo server"
```

- 快速更新并部署到服务器命令

```bash
alias hexogd="hexo generate && hexo deploy"
```


