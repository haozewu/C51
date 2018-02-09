# C51


#environment
Firstly, install sdcc on
http://sourceforge.net/projects/sdcc/files/snapshot_builds/i586-mingw32msvc-setup/sdcc-20180208-10228-setup.exe
Then configure the path file

#difference

exp:
	sdcc			keil
	#include<8052.h>	#include<reg52.h>
	#define pin P0_0	sbit pin=P0^0;
	
	declare nvic function before use
	reg 8052.h is different from reg52.h
	
