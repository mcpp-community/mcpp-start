# 项目配置和新内容添加

本章节主要是介绍模板项目的基础结构, 以及如何基于模板进行配置和添加自己的内容

## 一、认识项目结构

d2x类项目是一种强调交互的教程类项目, 他通常由 `[Book + Video + Code + X]` 四个部分组成

- `Book`: 教程的文档或电子书
- `Video`: 对应是项目的教程视频
- `Code`: 对应是项目的交互式练习代码集合
- `X`: 对应的是项目作者的自定义支持和服务, 例如论坛、交流群等

其中, `Book`和`Code`是基础项, 而`Video`和`X`可根据创作需求进行调整

从项目目录结构的角度, 他们的对应关系如下

```cpp
.
├── book                   ////// Book: 文档/书籍目录
│   ├── book.toml            // 书籍的配置文件
│   └── src                  // 书籍/文档的Markdown源码目录
│       ├── chapter_0.md
│       ├── chapter_1.md     // 书籍/文档的Markdown源码
│       ├── chapter_2.md
│       ├── chapter_3.md
│       └── SUMMARY.md       // 书籍目录
├── config.xlings
├── d2x
├── dslings                ////// Code: 项目练习代码目录
│   ├── hellomcpp.cpp        // 具体的练习代码
│   ├── hellocpp.cpp       
│   └── xmake.lua            // 练习代码编排和配置文件
├── LICENSE
├── README.md
├── videos                 ////// Video: 项目的教程视频(材料)目录
└── xmake.lua
```


## 二、Book: 编写教程/书籍 - 添加新章节

### 开启文档/书籍预览

在项目目录运行下面命令, 进行书籍实时预览模式

```
d2x book
```

### 修改书籍的基础配置

**书籍标题**

编辑`book/book.toml`文件里的`title`, 给项目的书籍起个名字

修改前

```
[book]
authors = ["sunrisepeak"]
language = "en"
multilingual = false
src = "src"
title = "D2X Project Template | D2X项目模板" <-- 修改位置
```

修改后

```
[book]
authors = ["sunrisepeak"]
language = "en"
multilingual = false
src = "src"
title = "从零实现xxx"
```

通过浏览器即可看到书籍标题变成了`从零实现xxx`

**添加Github仓库链接 (可选)**

在下面的属性上添加, Github仓库链接

```
[output.html]
git-repository-url = "xxxx"
```

### 修改书籍目录

编辑`book/src/SUMMARY.md`文件, 调整目录的显示

修改前

```
# Summary

- [简介](./chapter_0.md)
- [工具安装与环境配置](./chapter_1.md)
- [配置并添加内容](./chapter_2.md)
- [等待你的扩展](./chapter_3.md) <-- 修改位置
```

修改后

```
# Summary

- [简介](./chapter_0.md)
- [工具安装与环境配置](./chapter_1.md)
- [配置并添加内容](./chapter_2.md)
- [我的新章节](./chapter_3.md)
```

把目录4命名为了`我的新章节`

### 修改章节内容 以及 添加新章节

编辑标题对应的文件, 如`- [我的新章节](./chapter_3.md)`对应的文件为`book/src/chapter_3.md` 修改后即可在预览中观察到变化

添加新章节

- 第一步: 在`book/src`目录添加章节文件, 并填充内容
- 第二步: 在`book/src/SUMMARY.md`添加这个文件的目录索引

> 注: 更多配置细节参考 - [mdbook文档](https://rust-lang.github.io/mdBook)

## 三、Code: 添加新的练习代码

项目的练习代码集中放在了`dslings`目录中, 每当用户运行`d2x checker`命令时, 就会自动加载这些练习代码到一个检测队列中, 并跳转到当前第一个检测不同的练习代码, 等待用户去修改和完整.

d2x工具会实时检测练习代码的文件变动, 用户一修改代码就会自动触发检测程序, 如果检测通过会自动跳到下一个练习, 检测没有通过就会在控制台输出错误提示信息

检测的类型分为两种

- `编译期检查`: 检查练习代码是否可以正常编译通过
- `运行期检查`: 当代码编译检测通过后, 会再次验证运行是否符合要求

### 体验代码练习自动检测程序

项目默认提供了代码练习的示例, 可以通过运行下面命令进行体验

```
d2x checker
```

根据控制台报错, 修复代码并观察控制台的变化. 下面是控制台的信息解释

```
 🌏 ▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 0/2  -->> 显示当前的练习进度
                                                                                                                               
 ✗ hellocpp                 -->> 当前显示检测状态和练习名
 + → dslings/hellocpp.cpp   -->> 当前练习的文件路径
                                                                                                                               
 [ 23%]: cache compiling.release dslings/hellocpp.cpp -->> 显示编译状态
 error: dslings/hellocpp.cpp:29:39: error: found ':' in nested-name-specifier, expected '::'
    29 |     std::cout << "hello, mcpp!" << std:endl; // 0.修复这个编译错误
       |                                       ^
       |                                       ::
   ▼ 5 more lines below...

🤖:   AI Disabled / 未启用 - https://github.com/d2learn/d2x  -->> 显示AI状态/信息(需要配置大模型的key, 可不使用)
```

> 注: 退出检测程序使用`ctrl + c`

### 添加新的练习代码 & 验证

- 第一步: 添加练习代码文件
- 第二步: 添加练习代码文件到练习的配置文件

**练习代码文件 - 0-test.cpp**

在`dslings`目录创建`0-test.cpp`文件, 并添加如下内容

```cpp
#include <d2x/cpp/d2x.hpp> // 辅助工具

#include <iosteam> // 故意写错测试 编译期检查

int main() {
    std::cout << "Hello World ..." << std::endl;

    int a = 1;
    int b = 2;

    d2x::assert_eq(a, b); // 测试运行时检查
}
```

**添加0-test.cpp到练习配置文件中**

在`dslings/xmake.lua`文件添加`0-test.cpp`的基础信息

```lua
target("0-test")
    add_files("0-test.cpp")
```

**重新运行检测程序进行验证**

在项目根目录重新运行`d2x checker`观察控制台, 是否加载了新的练习代码

并修改练习代码中的错误, 观察控制台的变化

### 练习代码设计

由d2x工具支持的自动化代码练习项目, 通过在项目根目录下
执行 d2x checker 进入"编译器驱动开发模式"的练习代码自动检测.
需要用户根据控制台的报错和提示信息, 修改代码中的错误. 当修复所有编译错误和
运行时检查点后, 你可以删除或注释掉代码中的 d2x::wait(), 会自动进入下一个练习.
  - d2x::wait(): 用于隔离不同练习, 你可以删除或注释掉, 进入下一个练习.
  - d2x::assert_eq: 用于运行时检查点, 你需要修复代码中的错误, 使得所有
  - D2X_YOUR_ANSWER: 用于提示你需要修改的代码, 一般用于代码填空(即用正确的代码替换他)

## 其他功能 (可选)

### 配置AI智能辅助提示

d2x工具在练习代码检测过程中, 提供了一个AI智能助手的功能. 这个助手会根据当前练习代码的要求以及用户做练习代码的意图, 用幽默的方式给出一些提示.

编辑项目下的`.d2x.json`文件, 配置llm即可自动开启该功能

```
{
    "buildtools": "xmake d2x-buildtools",
    "lang": "zh",
    "llm": {
        "api_key": "",
        "api_url": "https://api.deepseek.com/v1",
        "model": "deepseek-chat",
        "system_prompt": ""
    },
    "ui_backend": "tui"
}
```

其中主要是配置`api_key`、`api_url`、`model` 这三个属性. 该上方默认提供的是deepseek的配置, 如果你有deepseek的key, 填入`api_key`即可使用

### 配置在线电子书

模板项目默认提供了Github Pages的自动部署功能, 只需要打开开启一下即可

具体步骤: `仓库的Setting -> Pages -> Build and deployment -> Source -> Github Actions`