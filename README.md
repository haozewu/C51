# C51


#environment
Firstly, install sdcc on</br>
http://sourceforge.net/projects/sdcc/files/snapshot_builds/i586-mingw32msvc-setup/sdcc-20180208-10228-setup.exe</br>
Then configure the path file

为什么不使用MDK:
1、功能较弱
2、只适合个人和小团队开发，不适合中型、大型开发
3、是收费软件，需要付费

#difference
```
exp

sdcc			keil

#include<8052.h>	#include<reg52.h>
#define pin P0_0	sbit pin=P0^0;
	
declare nvic function before use
reg 8052.h is different from reg52.h
```
