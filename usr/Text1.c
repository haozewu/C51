#include<reg52.h>
#define uint unsigned int 		//宏定义(不加分号)
#define uchar unsigned char 	//宏定义（不加分号）
sbit D1=P1^0;
void delay();	//函数的声明

void main()
{
	while(1)
	{
		D1=0;
		delay();		//调用延时函数
		D1=1;
		delay();		//调用延时函数
	}

}

void delay()		//延时子程序
{
	uint x,y;		//局部变量（在一个子函数中调用的变量）
	for(x=200;x>0;x--)
		for(y=400;y>0;y--);
		

}
