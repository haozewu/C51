#include <8052.h>

#define SWLED P2_0
#define LED0 P0_0
#define LED1 P0_1

void Int0() __interrupt 0; // SDCC的中断函数要预先声明，区别于KEIL C51
void Int1() __interrupt 2;
void Timer0() __interrupt 1;

unsigned char flag;
char sw1=0;
char sw2=0;
void main()
{
	flag=0;
	TMOD=0x01;
	SWLED=0;
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	EA=1;
	PT0=1;
	ET0=1;
	IT0=0;
	PX0=0;
	EX0=1;
	IT1=1;
	PX1=1;
	EX1=1;
	TR0=1;
	while(1)
	{
		sw1=0;
	}
}
void Int0() __interrupt 0
{
	sw1=1;
}
void Int1() __interrupt 2
{
	sw2=~sw2;
}
void Timer0() __interrupt 1
{
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	if(flag<100)
		flag++;
	else
	{
		flag=0;
		if(sw1)
			LED0=!LED0;// warning 180: using ~ on bit/bool/unsigned char variables can give unexpected results due to promotion to int
		if(sw2)
			LED1=!LED1;
	}

}