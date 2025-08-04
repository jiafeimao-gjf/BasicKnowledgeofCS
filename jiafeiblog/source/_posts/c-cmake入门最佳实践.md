---
title: c++_cmake入门最佳实践
categories:
  - leetcode
tags:
  - c++
  - cmake
date: 2025-07-13 08:46:03
---
### CMake 入门教程

CMake 是一个跨平台的构建系统工具，用于控制软件的编译过程。它使用简单的文本文件（CMakeLists.txt）来描述项目的构建过程，然后生成适合特定平台的 Makefile 或 Visual Studio 项目文件。

#### 1. 安装 CMake

首先需要安装 CMake，可以从 [CMake 官网](https://cmake.org/download/) 下载安装包，也可以使用包管理器安装：

```bash
# Ubuntu/Debian
sudo apt-get install cmake

# macOS (使用 Homebrew)
brew install cmake

# Windows (使用 Chocolatey)
choco install cmake
```

#### 2. 基本 CMake 项目结构

一个最简单的 CMake 项目通常包含以下文件：

```
myproject/
├── CMakeLists.txt
└── main.cpp
```

#### 3. 编写第一个 CMakeLists.txt

以下是一个最基本的 CMakeLists.txt 文件示例：

```cmake
# 声明要求的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(myapp main.cpp)
```

> 注意保存文件，否则编译会没有内容
#### 4. 编写源代码文件

下面是一个简单的 main.cpp 文件示例：

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, CMake!" << std::endl;
    return 0;
}
```
> 注意保存文件，否则编译会没有内容

#### 5. 构建项目

使用以下步骤构建项目：

```bash
# 创建构建目录
mkdir build
cd build

# 运行 CMake 生成 Makefile
cmake ..

# 编译项目
cmake --build .

# 运行程序
./myapp
```

#### 6. 添加库文件

如果项目中使用了库文件，可以通过以下方式添加：

```cmake
# 声明要求的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加库
add_library(mylib STATIC
    src/mylib.cpp
    src/mylib.h
)

# 添加可执行文件并链接库
add_executable(myapp main.cpp)
target_link_libraries(myapp mylib)
```

#### 7. 添加头文件目录

如果头文件不在默认搜索路径中，可以使用 `target_include_directories` 命令添加：

```cmake
# 添加头文件目录
target_include_directories(mylib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
```

#### 8. 高级用法：添加子目录

对于大型项目，可以将项目分成多个子目录，每个子目录有自己的 CMakeLists.txt：

```
myproject/
├── CMakeLists.txt
├── src/
│   ├── CMakeLists.txt
│   └── main.cpp
└── lib/
    ├── CMakeLists.txt
    ├── mylib.cpp
    └── mylib.h
```

顶层 CMakeLists.txt：

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 添加子目录
add_subdirectory(lib)
add_subdirectory(src)
```

src/CMakeLists.txt：

```cmake
add_executable(myapp main.cpp)
target_link_libraries(myapp mylib)
```

lib/CMakeLists.txt：

```cmake
add_library(mylib STATIC
    mylib.cpp
    mylib.h
)

target_include_directories(mylib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
```

#### 9. 常用 CMake 变量

- `CMAKE_SOURCE_DIR`：项目根目录
- `CMAKE_BINARY_DIR`：构建目录
- `CMAKE_CURRENT_SOURCE_DIR`：当前 CMakeLists.txt 所在目录
- `CMAKE_CURRENT_BINARY_DIR`：当前构建目录
- `PROJECT_NAME`：项目名称

#### 10. CMake 常用命令

- `add_executable()`：添加可执行文件
- `add_library()`：添加库文件
- `target_link_libraries()`：链接库文件
- `target_include_directories()`：添加头文件目录
- `set()`：设置变量
- `find_package()`：查找外部包
- `include_directories()`：添加全局头文件目录
- `link_directories()`：添加库文件搜索路径

#### 11. 使用外部库

如果需要使用外部库，可以使用 `find_package` 命令：

```cmake
# 查找并使用 OpenCV 库
find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIRS})
target_link_libraries(myapp ${OpenCV_LIBS})
```

#### 12. 构建类型

可以通过 `-DCMAKE_BUILD_TYPE` 参数指定构建类型：

```bash
# 构建 Debug 版本
cmake -DCMAKE_BUILD_TYPE=Debug ..

# 构建 Release 版本
cmake -DCMAKE_BUILD_TYPE=Release ..
```

#### 13. 安装目标

可以通过 `install()` 命令指定安装规则：

```cmake
# 安装可执行文件
install(TARGETS myapp
    RUNTIME DESTINATION bin
)

# 安装头文件
install(FILES mylib.h
    DESTINATION include
)
```

使用以下命令进行安装：

```bash
cmake --build . --target install
```

以上就是 CMake 的基本使用方法和最佳实践。CMake 还有很多高级功能，如测试、生成文档、交叉编译等，可以通过查阅 [CMake 官方文档](https://cmake.org/cmake/help/latest/) 来学习更多内容。

### cmake 和 gcc的区别

CMake和GCC是C++开发中不同层面的工具：
- **GCC**：是编译器，负责将C++源代码翻译成可执行文件。通过命令行参数指定编译选项（如`-std=c++11`），需手动管理依赖关系。
- **CMake**：是构建系统工具，通过`CMakeLists.txt`描述项目结构，自动生成Makefile或Visual Studio项目文件。可跨平台，隐藏底层编译细节，适合大型项目。

简言之：GCC是编译工具，CMake是管理编译过程的工具。

> demo 链接 https://github.com/jiafeimao-gjf/cmakedemo