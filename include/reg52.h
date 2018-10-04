/*--------------------------------------------------------------------------

REG52.H



Header file for generic 80C52 and 80C32 microcontroller.

Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.

All rights reserved.

--------------------------------------------------------------------------*/

#ifndef __REG52_H__

#define __REG52_H__

/*  BYTE Registers  */

sfr P0    = 0x80;	//P0口特殊功能寄存器   

sfr P1    = 0x90;	//P1口特殊功能寄存器

sfr P2    = 0xA0;	//P2口特殊功能寄存器

sfr P3    = 0xB0;	//P3口特殊功能寄存器

sfr PSW   = 0xD0;	//程序状态字寄存器

sfr ACC   = 0xE0;	//累加器A (使用最频繁,C中不怎么强调)

sfr B     = 0xF0;	//B寄存器

sfr SP    = 0x81;	//堆栈指针字寄存器

sfr DPL   = 0x82;	//数据指针高8位

sfr DPH   = 0x83;	//数据指针低8位

sfr PCON  = 0x87;	//电源控制字寄存器

sfr TCON  = 0x88;	//定时/计数控制字寄存器

sfr TMOD  = 0x89;	//定时/计数方式字寄存器	(不能进行位操作)

sfr TL0   = 0x8A;	//定时器0低8位

sfr TL1   = 0x8B;	//定时器1低8位

sfr TH0   = 0x8C;	//定时器0高8位

sfr TH1   = 0x8D;	//定时器1高8位

sfr IE    = 0xA8;	//中断允许字寄存器

sfr IP    = 0xB8;	//中断优先级寄存器

sfr SCON  = 0x98;	//串行控制字寄存器

sfr SBUF  = 0x99;	//串行数据缓冲器



/*  8052 Extensions  */

sfr T2CON  = 0xC8;	//定时器2控制寄存器

sfr RCAP2L = 0xCA;	//定时器/计数器2捕获寄存器低8位字节

sfr RCAP2H = 0xCB;	//定时器/计数器2捕获寄存器高8位字节

sfr TL2    = 0xCC;	//定时器/计数器2低8字节

sfr TH2    = 0xCD;	//定时器/计数器2高8字节


/*  BIT Registers  */

/*  PSW  */

sbit CY    = PSW^7;	//进位标志,运算时操作结果最高位(第7位)是否有进位或者错位

sbit AC    = PSW^6;	//半进位标志 表示低字节向高字节是否有进位或者错位,=1时有;=0时无

sbit F0    = PSW^5;	//用户标志,由用户置位或复位

sbit RS1   = PSW^4;	//工作寄存器选择位 (4组工作寄存器RAM 每组8个字节)

sbit RS0   = PSW^3;	//工作寄存器选择位

sbit OV    = PSW^2;	//溢出标志位,表示算术运算时,是否有溢出.=1是有溢出;=0时无溢出

sbit P     = PSW^0; //8052 only	累加器A奇偶标志位,为1时 有奇数个1;为0时 有偶数个1



/*  TCON  */

sbit TF1   = TCON^7; //定时器1溢出标志位,溢出时,由硬件置1,并申请中断,进入中断函数中,自动清0(使用定时器操作时,不用认为操作)

sbit TR1   = TCON^6; //定时器1运行控制位 由软件控制清0 ,GATE=1时 且INT1为高电平时,TR1=1时启动定时器1,GATE=0时,只要TR1=1时就可以启动定时器1

sbit TF0   = TCON^5; //定时器1溢出标志位,溢出时,由硬件置1,并申请中断,进入中断函数中,自动清0(使用定时器操作时,不用认为操作)

sbit TR0   = TCON^4; //定时器0运行控制位 由软件控制清0 ,GATE=1时 且INT0为高电平时,TR0=1时启动定时器0,GATE=0时,只要TR0=1时就可以启动定时器0

sbit IE1   = TCON^3; //外部中断1请求标志  

sbit IT1   = TCON^2; //外部中断触发方式选择位 0时 电平触发方式 INT1上低电平有效 ;1时下降沿触发有效,INT1由高变低时有效

sbit IE0   = TCON^1; //外部中断0请求标志

sbit IT0   = TCON^0; //外部中断触发方式选择位 0时 电平触发方式 INT0上低电平有效 ;1时下降沿触发有效,INT0由高变低时有效



/*  IE  */

sbit EA    = IE^7; //全局总中断允许位(每种中断都必须)

sbit ET2   = IE^5; //8052 only 定时/计数器2中断允许位

sbit ES    = IE^4; //串口中断允许位

sbit ET1   = IE^3; //定时/计数器1中断允许位

sbit EX1   = IE^2; //外部中断1(INT1)允许位

sbit ET0   = IE^1; //定时/计数器0中断允许位

sbit EX0   = IE^0; //外部中断0(INT0)允许位



/*  IP  */

sbit PT2   = IP^5; //定时/计数器2中断优先级控制位

sbit PS    = IP^4; //串口中断优先级控制位

sbit PT1   = IP^3; //定时/计数器1中断优先级控制位

sbit PX1   = IP^2; //外部中断1中断优先级控制位

sbit PT0   = IP^1; //定时/计数器0中断优先级控制位

sbit PX0   = IP^0; //外部中断0中断优先级控制位



/*  P3  */

sbit RD    = P3^7; // RD(外部数据存储器读选通控制输出)

sbit WR    = P3^6; // WR(外部数据存储器写选通控制输出)

sbit T1    = P3^5; // T1(T1定时/计数器1外部输入)

sbit T0    = P3^4; // T0(T0定时/计数器1外部输入)

sbit INT1  = P3^3; // 外部中断1输入

sbit INT0  = P3^2; // 外部中断0输入

sbit TXD   = P3^1; // 串行口输入

sbit RXD   = P3^0; // 串行口输出



/*  SCON  */

sbit SM0   = SCON^7;

sbit SM1   = SCON^6;

sbit SM2   = SCON^5;

sbit REN   = SCON^4;

sbit TB8   = SCON^3;

sbit RB8   = SCON^2;

sbit TI    = SCON^1;

sbit RI    = SCON^0;



/*  P1  */

sbit T2EX  = P1^1; // 8052 only

sbit T2    = P1^0; // 8052 only

             

/*  T2CON  */

sbit TF2    = T2CON^7;

sbit EXF2   = T2CON^6;

sbit RCLK   = T2CON^5;

sbit TCLK   = T2CON^4;

sbit EXEN2  = T2CON^3;

sbit TR2    = T2CON^2;

sbit C_T2   = T2CON^1;

sbit CP_RL2 = T2CON^0;



#endif
