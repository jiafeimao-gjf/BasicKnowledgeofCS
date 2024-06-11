---
title: go开发之web模版
categories:
  - backend
tags:
  - backend
  - go
  - 模版
date: 2024-06-10 17:36:47
---

[toc]

在Go语言（Golang）中，创建一个Web工程的脚手架（Scaffold）涉及几个关键步骤，包括设置项目结构、选择Web框架、配置依赖管理等。下面是一个基本的指南来帮助你搭建一个简单的Go Web应用脚手架。

## 1. 初始化项目和工作区

首先，确保你的系统上安装了Go，并且设置了`GOPATH`环境变量。然后，创建一个新的工作目录，并初始化一个新的Go模块：

```bash
mkdir mywebapp
cd mywebapp
go mod init mywebapp
```

这里，`example.com/mywebapp`是你的模块路径，应替换为实际的域名和项目名。

## 2. 选择Web框架

Go有很多轻量级的Web框架可选，如Gin、Echo、Beego等。这里以Gin为例，因为它简洁高效：

```bash
go get -u github.com/gin-gonic/gin
```

## 3. 设计项目结构

一个典型的Go Web应用项目结构可能如下：

```
mywebapp/
├── main.go
├── go.mod
├── go.sum
├── routers/
│   └── router.go
└── models/
    └── user.go  # 示例：用户模型
```

- `main.go`：应用程序入口。
- `routers/`：包含路由定义。
- `models/`：存放数据模型或业务逻辑相关的代码。

## 4. 编写基本代码

**main.go**

```go
package main

import (
  "github.com/gin-gonic/gin"
  router "mywebapp/routers"
)

func main() {
    r := gin.Default()
    InitializeRoutes(r) // 引入路由初始化函数
    r.Run()            // 监听并在 0.0.0.0:8080 上启动服务
}

```

**routers/router.go**

```go
package routers

import (
    "github.com/gin-gonic/gin"
)

// 开头大写，访问权限放开，可以被import
func InitializeRoutes(router *gin.Engine) {
    router.GET("/hello", HelloHandler)
}

func HelloHandler(c *gin.Context) {
    c.JSON(200, gin.H{
        "message": "Hello, World!",
    })
}
```

## 5. 运行应用

回到项目根目录，执行以下命令启动Web服务器：

```bash
go run main.go
```

访问 `http://localhost:8080/hello`，你应该能看到 "Hello, World!" 的响应。

## 6. 扩展开发

### 6.1 配置自动构建和热重载

为了提升开发效率，可以使用像`air`这样的工具实现自动编译和热重载。


> https://darjun.github.io/2020/09/27/godailylib/air/

> 最新：https://github.com/air-verse/air readme.md

```bash
go get -u github.com/cosmtrek/air
air
```

这样，每当你的源代码发生变化时，应用会自动重新编译并重启，无需手动停止和重启服务。

### 6.2 引入gorm，进行数据库增删改查

在Go语言中引入数据库通常涉及到以下几个步骤，这里以使用GORM作为ORM（对象关系映射）库，连接MySQL数据库为例进行说明：

#### 6.2.1 安装GORM

首先，你需要通过`go get`命令安装GORM及其对应的数据库驱动。对于MySQL，你需要安装`gorm`和`mysql`驱动：

```bash
go get -u gorm.io/gorm
go get -u gorm.io/driver/mysql
```

#### 6.2.2 导入GORM和其他必要的包

在你的Go文件顶部，导入GORM和MySQL驱动：

```go
import (
    "gorm.io/driver/mysql"
    "gorm.io/gorm"
)
```

#### 6.2.3 配置数据库连接

设置数据库连接参数，并使用GORM的`Open`函数连接数据库：

```go
dsn := "user:password@tcp(127.0.0.1:3306)/dbname?charset=utf8mb4&parseTime=True&loc=Local"
db, err := gorm.Open(mysql.Open(dsn), &gorm.Config{})
if err != nil {
    panic("failed to connect database")
}
```

这里，`dsn`是数据源名称，包含了数据库地址、用户名、密码、数据库名等信息。请根据实际情况替换`user`、`password`、`dbname`等占位符。

#### 6.2.4 定义模型（Models）

在Go中，你可以通过定义结构体来表示数据库表的结构。例如，定义一个用户模型：

```go
type User struct {
    gorm.Model
    Name  string
    Email string
}
```

`gorm.Model`是一个内置的结构体，提供了ID（主键）、CreatedAt、UpdatedAt、DeletedAt等字段。

#### 6.2.5 数据库迁移

GORM支持自动迁移来根据定义的模型创建数据库表：

```go
db.AutoMigrate(&User{})
```

这行代码会检查`User`结构体，并自动创建或更新对应的数据库表结构。

#### 6.2.6 数据操作

现在，你可以使用GORM提供的API来进行数据库的CRUD操作了，比如创建一个用户：

```go
user := User{Name: "John Doe", Email: "john.doe@example.com"}
db.Create(&user)
```

#### 6.2.7 示例完整代码

```go
package main

import (
    "gorm.io/driver/mysql"
    "gorm.io/gorm"
)

type User struct {
    gorm.Model
    Name  string
    Email string
}

func main() {
    dsn := "user:password@tcp(127.0.0.1:3306)/dbname?charset=utf8mb4&parseTime=True&loc=Local"
    db, err := gorm.Open(mysql.Open(dsn), &gorm.Config{})
    if err != nil {
        panic("failed to connect database")
    }

    // 自动迁移
    db.AutoMigrate(&User{})

    // 创建用户
    user := User{Name: "John Doe", Email: "john.doe@example.com"}
    db.Create(&user)
}
```

请确保替换DSN中的占位符为正确的数据库连接信息。这样，你就成功地在Go工程中引入了数据库并进行了基本的数据操作。

### 6.3 配置中间件

在Go语言中引入中间件通常涉及到定义和使用`http.Handler`接口。下面是一个简单的示例，展示如何在Go Web应用中引入和使用中间件。

#### 6.3.1 定义中间件

首先，定义一个中间件函数。中间件是一个接受并返回`http.Handler`的函数，它可以在请求处理前后添加额外的操作，比如记录日志、验证权限等。

```go
package middleware

import (
    "net/http"
)

// LoggingMiddleware 是一个日志记录中间件的示例
func LoggingMiddleware(next http.Handler) http.Handler {
    return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
        // 在请求处理前记录日志
        println("Before request handling")

        // 调用下一个处理器（可能是其他中间件或者最终的路由处理函数）
        next.ServeHTTP(w, r)

        // 请求处理后记录日志
        println("After request handling")
    })
}
```

#### 6.3.2 应用中间件

在你的主路由处理器中，使用中间件包裹具体的路由处理逻辑。以下是一个使用`http.ListenAndServe`简单示例：

```go
package main

import (
    "fmt"
    "log"
    "net/http"

    "your-module-name/middleware" // 引入自定义中间件
)

func helloHandler(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintln(w, "Hello, World!")
}

func main() {
    // 创建路由
    mux := http.NewServeMux()

    // 注册路由处理器，并使用中间件
    mux.Handle("/", middleware.LoggingMiddleware(http.HandlerFunc(helloHandler)))

    // 启动服务器
    log.Fatal(http.ListenAndServe(":8080", mux))
}
```

在这个例子中，`LoggingMiddleware`中间件被用来包裹`helloHandler`处理器，这样每次请求`/`路径时，都会先打印"Before request handling"，处理完请求后再打印"After request handling"。

#### 6.3.3 使用第三方框架

如果你使用的是Gin、Echo等流行的Web框架，它们通常提供了更便捷的方式来注册和使用中间件。以Gin为例，你只需定义一个中间件函数并使用`Use`方法添加到路由或全局：

```go
package main

import (
    "github.com/gin-gonic/gin"
    "your-module-name/middleware"
)

func main() {
    r := gin.Default()

    // 添加中间件到所有路由
    r.Use(middleware.LoggingMiddleware)

    r.GET("/", func(c *gin.Context) {
        c.JSON(200, gin.H{"message": "Hello, World!"})
    })

    r.Run(":8080")
}
```

这样，中间件就会自动应用于Gin框架的所有路由上，无需手动在每个路由上单独添加。

### 6.4 go web配置redis

要在Go工程中引入Redis，一个常见的做法是使用`go-redis`库，它是Go语言的一个高性能Redis客户端。以下是引入`go-redis`并进行基本操作的步骤：

#### 6.4.1 安装`go-redis`

首先，你需要通过`go get`命令安装`go-redis/v8`。注意指定版本号以避免潜在的不兼容问题：

```bash
go get github.com/go-redis/redis/v8
```

#### 6.4.2 导入库

在你的Go文件中，导入`go-redis/v8`包：

```go
import (
	"context"
	"github.com/go-redis/redis/v8"
)
```

#### 6.4.3 配置Redis客户端

接下来，配置Redis客户端。这通常包括设置地址、密码、数据库索引等：

```go
opt, err := redis.ParseURL("redis://:password@localhost:6379/0")
if err != nil {
	log.Fatalf("Failed to parse Redis URL: %v", err)
}
client := redis.NewClient(opt)
defer client.Close()
```

或者，手动配置客户端：

```go
client := redis.NewClient(&redis.Options{
	Addr:     "localhost:6379",
	Password: "", // no password set
	DB:       0,  // use default DB
})
defer client.Close()
```

#### 6.4.4 使用Redis

现在你可以使用`client`变量执行Redis命令了，例如设置和获取键值对：

```go
ctx := context.Background()

err = client.Set(ctx, "key", "value", 0).Err()
if err != nil {
	log.Fatalf("Set failed: %v", err)
}

val, err := client.Get(ctx, "key").Result()
if err == redis.Nil {
	fmt.Println("Key not found")
} else if err != nil {
	log.Fatalf("Get failed: %v", err)
} else {
	fmt.Println("Value:", val)
}
```

#### 6.4.5 示例完整代码

```go
package main

import (
	"context"
	"fmt"
	"log"

	"github.com/go-redis/redis/v8"
)

func main() {
	opt, err := redis.ParseURL("redis://:password@localhost:6379/0")
	if err != nil {
		log.Fatalf("Failed to parse Redis URL: %v", err)
	}
	client := redis.NewClient(opt)
	defer client.Close()

	ctx := context.Background()

	err = client.Set(ctx, "example", "Hello, Redis!", 0).Err()
	if err != nil {
		log.Fatalf("Set failed: %v", err)
	}

	val, err := client.Get(ctx, "example").Result()
	if err == redis.Nil {
		fmt.Println("Key not found")
	} else if err != nil {
		log.Fatalf("Get failed: %v", err)
	} else {
		fmt.Println("Value:", val)
	}
}
```

请确保替换上述代码中的Redis连接信息（如地址、密码）以匹配你的实际配置。通过这些步骤，你就可以在Go工程中顺利引入并使用Redis了。