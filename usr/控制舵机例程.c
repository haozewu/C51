#include<reg52.h>

#define uint8  unsigned char
#define uint16 unsigned int
//我看了看发现定时器初始化那儿有点乱而且没啥用  你注意一下  当时是准备拿来调超声波  但想歪了
int b;
int UpStep  =5;     //抬脚等幅度
int down = 100;     //抬脚高度
int up = 220;
int T = 5000;       // 关于pwm控制舵机的原理自行百度
int delay = 800;    //控制转动的快慢
int  M0=220;//舵机转动量，根据红外检测改变
int  M2=220;


//M0>M2 左转
//M0<M2 右转


uint8 order1;

uint16 PWM_Value[4]={1380,1370,1420,1450};      //调试得到的中值


void delay_nus(uint16 a )//延时1微秒
{
    while(a--);
}
/*===================================================================================
    定时器T0的中断服务程序
    一个循环20MS  = 4*5ms
=====================================================================================*/
void Timer0(void) interrupt 1 using 1//pwm波    适用于四个舵机
{
 switch(order1)
 {
 case 1:  PWM_OUT0=1;
          TH0=-PWM_Value[0]/256;
          TL0=-PWM_Value[0]%256;
          break;
 case 2:  PWM_OUT0=0;
          TH0=-(T-PWM_Value[0])/256;
          TL0=-(T-PWM_Value[0])%256;
          break;
 case 3:  PWM_OUT1=1;
          TH0=-PWM_Value[1]/256;
          TL0=-PWM_Value[1]%256;
          break;
 case 4:  PWM_OUT1=0;
          TH0=-(T-PWM_Value[1])/256;
          TL0=-(T-PWM_Value[1])%256;
          break;
 case 5:  PWM_OUT2=1;
          TH0=-PWM_Value[2]/256;
          TL0=-PWM_Value[2]%256;
          break;
 case 6:  PWM_OUT2=0 ;
          TH0=-(T-PWM_Value[2])/256;
          TL0=-(T-PWM_Value[2])%256;
          break;
 case 7:  PWM_OUT3=1;
          TH0=-PWM_Value[3]/256;
          TL0=-PWM_Value[3]%256;
          break;
 case 8:  PWM_OUT3=0;
          TH0=-(T-PWM_Value[3])/256;
          TL0=-(T-PWM_Value[3])%256;
          break;
 default : order1=0;
    }
    order1++;
}
/*===================================================================================
 初始化中断
=====================================================================================*/
void InitPWM(void)
{
   order1=1;
   TMOD|=0X11;		   //设T1为方式1，GATE=1；
   TH1=0;
   TL1=0;
   ET1=1;
   EA=1;
   IE=0x82;
   TH0=-1500/256;
   TL0=-1500%256;
   EA=1;
   ET0=1;
   TR0=1;
}
/*************************************************************************************
 红外检测使之左右转  及控制前行方向的舵机转动不同幅度即可左右转
*************************************************************************************/
void IR_CM(void)
{
		  if(red0==0&&red1==0)
		  { M0=220;   M2=190;}	 //两个都检测到 左转
		  else if(red0==0&&red1==1)
		  { M0=195;   M2=220;}	 //外边检测到 里边没检测到直走 这里转动幅度差的原因是因为机器人结构本身使他有左倾或右倾
		  else if(red0==1&&red1==0)
		  { M0=220;   M2=190;}	 //里边监测到 外边没检测到  左转
		  else if(red0==1&&red1==1)
		  { M0=175;   M2=200;}	 //两个都没检测到  右转
}

/*-------------------------------------------
这是迈腿的第一步与接下来的步子不同所以分开编程
---------------------------------------------*/
//右前左后
void   Movement_right_first(void)
{
			uint16 m,m0,m2;
		for(m=0;m<down;m+=UpStep)
		   {
		    	  PWM_Value[1]=p1-m; // 左脚抬起	1 - 下
                          PWM_Value[3]=p3-m; //右脚持平
                          delay_nus(delay);
		   }
		   M0=190;M2=220;
		for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                          PWM_Value[2]=p2+m2; //
                          PWM_Value[0]=p0+m0; //	左上往外右上往外  前进一步
                          delay_nus(delay);
		   }
		for(m=down;m>0;m-=UpStep)
		   {
                          PWM_Value[1]=p1-m; // 左右脚回来
                          PWM_Value[3]=p3-m;
                          delay_nus(delay);
		   }
}

//左后复原左前与右前复原右后同步
void   Movement_right_back(void)
{
		   uint16 m,m0,m2;
			for(m=0;m<down;m+=UpStep)
		   {
		    	PWM_Value[3]=p3+m; //	 右脚抬起
                        PWM_Value[1]=p1+m;  //左脚持平
                        delay_nus(delay);
		   }
		   for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                          PWM_Value[2]=p2+M2-m2; //
                          PWM_Value[0]=p0+M0-m0; //	回复
                          delay_nus(delay);
                   }
		   IR_CM(); //检测程序位置可变，自己研究  这里改变了M0 M2即改变了转动幅度及方向
			for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                          PWM_Value[2]=p2-m2; //
                          PWM_Value[0]=p0-m0; //	左前右后  前进一步
			  delay_nus(delay);
		   }
			for(m=down;m>0;m-=UpStep)
		   {
		    	  PWM_Value[1]=p1+m; // 右脚回来
                          PWM_Value[3]=p3+m;
                          delay_nus(delay);
		   }
}
//左前复原左后与右后复原右前同步
void   Movement_left_back(void)
{
		  	uint16 m,m0,m2;
			for(m=0;m<down;m+=UpStep)
		   {
		    	PWM_Value[1]=p1-m; // 左脚抬起	1 - 下
                        PWM_Value[3]=p3-m;
                        delay_nus(delay);
		   }
		   for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                           PWM_Value[2]=p2-M2+m2; //
                           PWM_Value[0]=p0-M0+m0; //	左前复原右后复原
                           delay_nus(delay);
		    }
			  //IR_CM();//检测程序位置可变，自己研究
			IR_CM();
			for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
                    {
                            if(m0>M0)      m0-=UpStep;
                            else if(m2>M2) m2-=UpStep;
                            PWM_Value[2]=p2+m2; //
                            PWM_Value[0]=p0+m0; //	右前左后  前进一步 m2和m0可改动
                            DELAY_US(us)(delay);
                     }
		   for(m=down;m>0;m-=UpStep)
		    {
                            PWM_Value[1]=p1-m; // 左脚回来
                            PWM_Value[3]=p3-m;
                            delay_nus(delay);
		     }

}

void main(void)
{
      InitPWM();
      delay_nus(5000);
      Movement_right_first();
      while(1)
      {
        Movement_right_back();
        Movement_left_back();
      }
}