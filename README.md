# C51


## environment

编译器官方网站http://sdcc.sourceforge.net/
下载地址https://sourceforge.net/projects/sdcc/files/
选合适的版本就可以了，比如我https://sourceforge.net/projects/sdcc/files/sdcc-win64/3.8.0/sdcc-3.8.0-x64-setup.exe/download
Firstly, install sdcc</br>
例程网址https://www.pjrc.com/tech/8051/
</br>
Then configure the path file
```
为什么不使用MDK:
1、功能较弱
2、只适合个人和小团队开发，不适合中型、大型开发
3、是收费软件，需要付费
```
## difference
```
exp

sdcc			keil

#include<8052.h>	#include<reg52.h>
#define pin P0_0	sbit pin=P0^0;
	
declare nvic function before use
reg 8052.h is different from reg52.h
```
