/**
 * 控制舵机例程
 */
#include<reg52.h>

#define uint8  unsigned char
#define uint16 unsigned int
//�ҿ��˿����ֶ�ʱ����ʼ���Ƕ��е��Ҷ���ûɶ��  ��ע��һ��  ��ʱ��׼��������������  ��������
int b;
int UpStep  =5;     //̧�ŵȷ���
int down = 100;     //̧�Ÿ߶�
int up = 220;
int T = 5000;       // ����pwm���ƶ����ԭ�����аٶ�
int delay = 800;    //����ת���Ŀ���
int  M0=220;//���ת���������ݺ�����ı�
int  M2=220;


//M0>M2 ��ת
//M0<M2 ��ת


uint8 order1;

uint16 PWM_Value[4]={1380,1370,1420,1450};      //���Եõ�����ֵ


void delay_nus(uint16 a )//��ʱ1΢��
{
    while(a--);
}
/*===================================================================================
    ��ʱ��T0���жϷ������
    һ��ѭ��20MS  = 4*5ms
=====================================================================================*/
void Timer0(void) interrupt 1 using 1//pwm��    �������ĸ����
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
 ��ʼ���ж�
=====================================================================================*/
void InitPWM(void)
{
   order1=1;
   TMOD|=0X11;		   //��T1Ϊ��ʽ1��GATE=1��
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
 ������ʹ֮����ת  ������ǰ�з���Ķ��ת����ͬ���ȼ�������ת
*************************************************************************************/
void IR_CM(void)
{
		  if(red0==0&&red1==0)
		  { M0=220;   M2=190;}	 //��������⵽ ��ת
		  else if(red0==0&&red1==1)
		  { M0=195;   M2=220;}	 //��߼�⵽ ���û��⵽ֱ�� ����ת�����Ȳ��ԭ������Ϊ�����˽ṹ����ʹ�������������
		  else if(red0==1&&red1==0)
		  { M0=220;   M2=190;}	 //��߼�⵽ ���û��⵽  ��ת
		  else if(red0==1&&red1==1)
		  { M0=175;   M2=200;}	 //������û��⵽  ��ת
}

/*-------------------------------------------
�������ȵĵ�һ����������Ĳ��Ӳ�ͬ���Էֿ����
---------------------------------------------*/
//��ǰ���
void   Movement_right_first(void)
{
			uint16 m,m0,m2;
		for(m=0;m<down;m+=UpStep)
		   {
		    	  PWM_Value[1]=p1-m; // ���̧��	1 - ��
                          PWM_Value[3]=p3-m; //�ҽų�ƽ
                          delay_nus(delay);
		   }
		   M0=190;M2=220;
		for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                          PWM_Value[2]=p2+m2; //
                          PWM_Value[0]=p0+m0; //	����������������  ǰ��һ��
                          delay_nus(delay);
		   }
		for(m=down;m>0;m-=UpStep)
		   {
                          PWM_Value[1]=p1-m; // ���ҽŻ���
                          PWM_Value[3]=p3-m;
                          delay_nus(delay);
		   }
}

//���ԭ��ǰ����ǰ��ԭ�Һ�ͬ��
void   Movement_right_back(void)
{
		   uint16 m,m0,m2;
			for(m=0;m<down;m+=UpStep)
		   {
		    	PWM_Value[3]=p3+m; //	 �ҽ�̧��
                        PWM_Value[1]=p1+m;  //��ų�ƽ
                        delay_nus(delay);
		   }
		   for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                          PWM_Value[2]=p2+M2-m2; //
                          PWM_Value[0]=p0+M0-m0; //	�ظ�
                          delay_nus(delay);
                   }
		   IR_CM(); //������λ�ÿɱ䣬�Լ��о�  ����ı���M0 M2���ı���ת�����ȼ�����
			for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                          PWM_Value[2]=p2-m2; //
                          PWM_Value[0]=p0-m0; //	��ǰ�Һ�  ǰ��һ��
			  delay_nus(delay);
		   }
			for(m=down;m>0;m-=UpStep)
		   {
		    	  PWM_Value[1]=p1+m; // �ҽŻ���
                          PWM_Value[3]=p3+m;
                          delay_nus(delay);
		   }
}
//��ǰ��ԭ������Һ�ԭ��ǰͬ��
void   Movement_left_back(void)
{
		  	uint16 m,m0,m2;
			for(m=0;m<down;m+=UpStep)
		   {
		    	PWM_Value[1]=p1-m; // ���̧��	1 - ��
                        PWM_Value[3]=p3-m;
                        delay_nus(delay);
		   }
		   for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
		   {
		      	  if(m0>M0)      m0-=UpStep;
                          else if(m2>M2) m2-=UpStep;
                           PWM_Value[2]=p2-M2+m2; //
                           PWM_Value[0]=p0-M0+m0; //	��ǰ��ԭ�Һ�ԭ
                           delay_nus(delay);
		    }
			  //IR_CM();//������λ�ÿɱ䣬�Լ��о�
			IR_CM();
			for(m0=0,m2=0;m0<M0||m2<M2;m0+=UpStep,m2+=UpStep)
                    {
                            if(m0>M0)      m0-=UpStep;
                            else if(m2>M2) m2-=UpStep;
                            PWM_Value[2]=p2+m2; //
                            PWM_Value[0]=p0+m0; //	��ǰ���  ǰ��һ�� m2��m0�ɸĶ�
                            DELAY_US(us)(delay);
                     }
		   for(m=down;m>0;m-=UpStep)
		    {
                            PWM_Value[1]=p1-m; // ��Ż���
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