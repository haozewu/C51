# C51

### 目录

[为什么选择SDCC而不是Keil](#为什么选择sdcc而不是keil)

[下载与配置](#下载与配置)

[关于本项目说明](#关于本项目说明)

[贡献指南](#贡献指南)

[SDCC和Keil语法差异](#sdcc和keil语法差异)

[其他资料](#其他资料)

## 为什么选择SDCC而不是Keil

#### Keil缺点：

1. 功能较弱，只适合个人和小团队开发，不适合中型、大型开发
2. 是收费软件，需要付费，大多数人用 Keil C 都是盗版
3. Keil内部中文注释是乱码，配套编辑器缩进不方便
4. Keil支持较为局限

#### SDCC缺点：

1. SDCC不配套的调试器，不能够调试硬件

## 下载与配置

1. 编辑器我们推荐使用VSCode，并针对VSCode配置了一套设置文件
2. [下载VSCode](https://code.visualstudio.com/download)
3. 然后根据计算机版本完成VSCode的安装
4. [下载SDCC](https://sourceforge.net/projects/sdcc/files/)
5. 同样根据自己的系统安装对应版本的SDCC，例如我安装的是[SDCCWin64的V3.8](https://sourceforge.net/projects/sdcc/files/sdcc-win64/3.8.0/sdcc-3.8.0-x64-setup.exe/download)
6. 安装好SDCC需要配置Path系统变量

## 关于本项目说明

1. VSCode的语法错误提示已经被屏蔽，需要的自行删除.vscode的setting（如果删除语法错误屏蔽，正确的书写方法会报一些错误）
2. 代码文件默认放在usr文件夹中，临时文件放在tmp文件夹中
3. 目前的Makefile仅支持C51单文件编译
4. Publish的批处理文件是用来一键删除所有的临时文件和生成过的hex文件，如果想要删除tmp文件夹下的临时文件和生成过的hex文件，可以运行publish.bat
5. 使用时，打开VSCode，点击File-Open Folder，然后选择本repo的文件夹，如果你按照默认目录安装sdcc，你打开一个usr文件夹下的C文件，然后点击Terminal-RunBuildTask，即可成功编译并生成可烧录的hex文件。

## 贡献指南

- Pull Request前，请将你的编译生成和临时文件全部删除

## SDCC和Keil语法差异

```c
#include<8052.h>//#include<reg52.h>
#define pin P0_0//sbit pin=P0^0;
//declare nvic function before use 在使用中断函数之前要声明
```

## 其他资料

- [8051例程网址](https://www.pjrc.com/tech/8051/)

