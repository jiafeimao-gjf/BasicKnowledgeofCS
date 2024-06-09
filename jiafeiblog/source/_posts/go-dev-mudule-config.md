---
title: go开发之go module配置
categories:
  - go开发
tags:
  - go
  - go-module
date: 2024-06-09 12:36:48
---
在 macOS 上配置 Go Module 以管理依赖项，你可以遵循以下步骤：

### 1. 确保 Go 版本支持模块

首先，确认你的 Go 版本至少是 1.11 或更高，因为 Go Module 功能是在 1.11 版本引入的。你可以通过在终端运行 `go version` 来查看当前的 Go 版本。

### 2. 开启 Go Module 功能

打开你的 shell 配置文件，这通常是 `~/.zshrc` （如果你使用的是 zsh）或者 `~/.bashrc` / `~/.bash_profile` （如果你使用的是 bash）。然后，在文件末尾添加以下行来开启 Go Module 功能，并可选地设置 GOPROXY（用于代理下载模块）：

```sh
export GO111MODULE=on
export GOPROXY=https://goproxy.io,direct
```

`GOPROXY=https://goproxy.io,direct` 这一行是为了加速在中国地区的模块下载，`direct` 表示如果没有通过代理找到模块则直接从源地址下载。

保存文件后，执行 `source ~/.zshrc` 或 `source ~/.bashrc`（取决于你使用的 shell）使配置生效。

### 3. 初始化 Go Module

在你的项目根目录下，运行以下命令初始化一个新的 Go Module：

```sh
go mod init <module-name>
```

将 `<module-name>` 替换为你的模块名称，通常是包含域名反向的项目路径，如 `github.com/yourusername/yourprojectname`。

### 4. 添加依赖——非常好用

在你的 Go 代码中导入需要的包后，使用 `go mod tidy` 命令来自动添加缺失的依赖并清理不再使用的依赖：

```sh
go mod tidy
```

### 5. 构建和运行项目

现在，你可以使用 `go build` 或 `go run` 命令来构建或运行你的项目，Go 会自动处理依赖：

```sh
go build
# 或者
go run main.go
```

### 6. (可选) 配置代理

如果你的网络环境需要使用代理，除了上面提到的 `GOPROXY` 外，你可能还需要设置 HTTP(S)_PROXY 等环境变量来帮助 Go 获取外部资源：

```sh
export http_proxy=http://your-proxy-server:port
export https_proxy=http://your-proxy-server:port
```

确保替换 `your-proxy-server:port` 为你的代理服务器地址和端口。

完成这些步骤后，你就成功配置了 Go Module 在 macOS 上的开发环境，可以方便地管理项目依赖了。

### 参考资料

- go 社区：https://learnku.com/go/wikis/38122
