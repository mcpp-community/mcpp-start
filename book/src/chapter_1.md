# 工具安装与环境配置

本章节介绍如果安装d2x工具并创建模板项目, 以及基础的环境配置

## 一、安装d2x工具

### 方法1: 通过xlings包管理器安装 (推荐)

[xlings](https://xlings.d2learn.org)开源包管理器, 可以解决不同环境依赖不一致的问题

<details>
  <summary>点击查看xlings安装命令</summary>

---

#### Linux/MacOS

```bash
curl -fsSL https://d2learn.org/xlings-install.sh | bash
```

#### Windows - PowerShell

```bash
irm https://d2learn.org/xlings-install.ps1.txt | iex
```

> tips: xlings -> [details](https://xlings.d2learn.org)

---

</details>

```
xlings install d2x
```

### 方法2: 从源码进行构建

TODO...

## 二、创建项目 & 测试

### 创建项目

**通过模块创建(推荐)**

点击 [新建教程模板](https://github.com/new?template_name=d2x-project-template&template_owner=d2learn) 按钮, 通过模板仓库创建新教程项目. 然后, 再把生成的仓库clone到本地

```bash
git clone git@github.com:your_name/your_repo_name.git
```

**本地创建**

通过`d2x new xxx`命令创建一个新项目

```
d2x new d2hello
```

命令运行后会生成一个叫`d2hello`的目录, 进入/打开这个目录就能看到项目的基础结构

### 测试

进入新创建项目的根目录, 运行命令进行测试完整性

**查看文档命令测试**

运行下面命令后会在浏览器打开新项目的文档/书籍

```
d2x book
```

**代码自动检测功能测试**

运行下面的checker命令, 可以看到控制台进入实时代码检测模式, 修改文件代码, 控制台会自动更新

```
d2x checker
```