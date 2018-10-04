#ifndef __STC15F2K60S2_H_
#define __STC15F2K60S2_H_

/////////////////////////////////////////////////
//注意: STC15W4K32S4系列的芯片,上电后所有与PWM相关的IO口均为
//      高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
//相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
//        P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
/////////////////////////////////////////////////

/////////////////////////////////////////////////

//包含本头文件后,不用另外再包含"REG51.H"

//内核特殊功能寄存器        // 复位值   描述
__sfr  __at   0xE0  ACC         ;   //0000,0000 累加器Accumulator
__sfr  __at   0xF0  B           ;   //0000,0000 B寄存器
__sfr  __at   0xD0  PSW         ;   //0000,0000 程序状态字
__sbit __at   0xD7  CY         ;
__sbit __at   0xD6  AC         ;
__sbit __at   0xD5  F0         ;
__sbit __at   0xD4  RS1        ;
__sbit __at   0xD3  RS0        ;
__sbit __at   0xD2  OV         ;
__sbit __at   0xD0  P          ;
__sfr  __at   0x81  SP          ;   //0000,0111 堆栈指针
__sfr  __at   0x82  DPL         ;   //0000,0000 数据指针低字节
__sfr  __at   0x83  DPH         ;   //0000,0000 数据指针高字节

//I/O 口特殊功能寄存器
__sfr  __at   0x80  P0          ;   //1111,1111 端口0
__sbit __at   0x80  P0_0        ;
__sbit __at   0x81  P0_1        ;
__sbit __at   0x82  P0_2        ;
__sbit __at   0x83  P0_3        ;
__sbit __at   0x84  P0_4        ;
__sbit __at   0x85  P0_5        ;
__sbit __at   0x86  P0_6        ;
__sbit __at   0x87  P0_7        ;
__sfr  __at   0x90  P1          ;   //1111,1111 端口1
__sbit __at   0x90  P1_0        ;
__sbit __at   0x91  P1_1        ;
__sbit __at   0x92  P1_2        ;
__sbit __at   0x93  P1_3        ;
__sbit __at   0x94  P1_4        ;
__sbit __at   0x95  P1_5        ;
__sbit __at   0x96  P1_6        ;
__sbit __at   0x97  P1_7        ;
__sfr  __at   0xA0  P2          ;   //1111,1111 端口2
__sbit __at   0xA0  P2_0        ;
__sbit __at   0xA1  P2_1        ;
__sbit __at   0xA2  P2_2        ;
__sbit __at   0xA3  P2_3        ;
__sbit __at   0xA4  P2_4        ;
__sbit __at   0xA5  P2_5        ;
__sbit __at   0xA6  P2_6        ;
__sbit __at   0xA7  P2_7        ;
__sfr  __at   0xB0  P3          ;   //1111,1111 端口3
__sbit __at   0xB0  P3_0        ;
__sbit __at   0xB1  P3_1        ;
__sbit __at   0xB2  P3_2        ;
__sbit __at   0xB3  P3_3        ;
__sbit __at   0xB4  P3_4        ;
__sbit __at   0xB5  P3_5        ;
__sbit __at   0xB6  P3_6        ;
__sbit __at   0xB7  P3_7        ;
__sfr  __at   0xC0  P4          ;   //1111,1111 端口4
__sbit __at   0xC0  P4_0        ;
__sbit __at   0xC1  P4_1        ;
__sbit __at   0xC2  P4_2        ;
__sbit __at   0xC3  P4_3        ;
__sbit __at   0xC4  P4_4        ;
__sbit __at   0xC5  P4_5        ;
__sbit __at   0xC6  P4_6        ;
__sbit __at   0xC7  P4_7        ;
__sfr  __at   0xC8  P5          ;   //xxxx,1111 端口5
__sbit __at   0xC8  P5_0        ;
__sbit __at   0xC9  P5_1        ;
__sbit __at   0xCA  P5_2        ;
__sbit __at   0xCB  P5_3        ;
__sbit __at   0xCC  P5_4        ;
__sbit __at   0xCD  P5_5        ;
__sbit __at   0xCE  P5_6        ;
__sbit __at   0xCF  P5_7        ;
__sfr  __at   0xE8  P6          ;   //0000,0000 端口6
__sbit __at   0xE8  P6_0        ;
__sbit __at   0xE9  P6_1        ;
__sbit __at   0xEA  P6_2        ;
__sbit __at   0xEB  P6_3        ;
__sbit __at   0xEC  P6_4        ;
__sbit __at   0xED  P6_5        ;
__sbit __at   0xEE  P6_6        ;
__sbit __at   0xEF  P6_7        ;
__sfr  __at   0xF8  P7          ;   //0000,0000 端口7
__sbit __at   0xF8  P7_0        ;
__sbit __at   0xF9  P7_1        ;
__sbit __at   0xFA  P7_2        ;
__sbit __at   0xFB  P7_3        ;
__sbit __at   0xFC  P7_4        ;
__sbit __at   0xFD  P7_5        ;
__sbit __at   0xFE  P7_6        ;
__sbit __at   0xFF  P7_7        ;
__sfr  __at   0x94  P0M0        ;   //0000,0000 端口0模式寄存器0
__sfr  __at   0x93  P0M1        ;   //0000,0000 端口0模式寄存器1
__sfr  __at   0x92  P1M0        ;   //0000,0000 端口1模式寄存器0
__sfr  __at   0x91  P1M1        ;   //0000,0000 端口1模式寄存器1
__sfr  __at   0x96  P2M0        ;   //0000,0000 端口2模式寄存器0
__sfr  __at   0x95  P2M1        ;   //0000,0000 端口2模式寄存器1
__sfr  __at   0xB2  P3M0        ;   //0000,0000 端口3模式寄存器0
__sfr  __at   0xB1  P3M1        ;   //0000,0000 端口3模式寄存器1
__sfr  __at   0xB4  P4M0        ;   //0000,0000 端口4模式寄存器0
__sfr  __at   0xB3  P4M1        ;   //0000,0000 端口4模式寄存器1
__sfr  __at   0xCA  P5M0        ;   //0000,0000 端口5模式寄存器0
__sfr  __at   0xC9  P5M1        ;   //0000,0000 端口5模式寄存器1
__sfr  __at   0xCC  P6M0        ;   //0000,0000 端口6模式寄存器0
__sfr  __at   0xCB  P6M1        ;   //0000,0000 端口6模式寄存器1
__sfr  __at   0xE2  P7M0        ;   //0000,0000 端口7模式寄存器0
__sfr  __at   0xE1  P7M1        ;   //0000,0000 端口7模式寄存器1

//系统管理特殊功能寄存器
__sfr  __at   0x87  PCON        ;   //0001,0000 电源控制寄存器
__sfr  __at   0x8E  AUXR        ;   //0000,0000 辅助寄存器
__sfr  __at   0xA2  AUXR1       ;   //0000,0000 辅助寄存器1
__sfr  __at   0xA2  P_SW1       ;   //0000,0000 外设端口切换寄存器1
__sfr  __at   0x97  CLK_DIV     ;   //0000,0000 时钟分频控制寄存器
__sfr  __at   0xA1  BUS_SPEED   ;   //xx10,x011 总线速度控制寄存器
__sfr  __at   0x9D  P1ASF       ;   //0000,0000 端口1模拟功能配置寄存器
__sfr  __at   0xBA  P_SW2       ;   //0xxx,x000 外设端口切换寄存器

//中断特殊功能寄存器
__sfr  __at   0xA8  IE          ;   //0000,0000 中断控制寄存器
__sbit __at   0xAF  EA         ;
__sbit __at   0xAE  ELVD       ;
__sbit __at   0xAD  EADC       ;
__sbit __at   0xAC  ES         ;
__sbit __at   0xAB  ET1        ;
__sbit __at   0xAA  EX1        ;
__sbit __at   0xA9  ET0        ;
__sbit __at   0xA8  EX0        ;
__sfr  __at   0xB8  IP          ;   //0000,0000 中断优先级寄存器
__sbit __at   0xBF  PPCA       ;
__sbit __at   0xBE  PLVD       ;
__sbit __at   0xBD  PADC       ;
__sbit __at   0xBC  PS         ;
__sbit __at   0xBB  PT1        ;
__sbit __at   0xBA  PX1        ;
__sbit __at   0xB9  PT0        ;
__sbit __at   0xB8  PX0        ;
__sfr  __at   0xAF  IE2         ;   //0000,0000 中断控制寄存器2
__sfr  __at   0xB5  IP2         ;   //xxxx,xx00 中断优先级寄存器2
__sfr  __at   0x8F  INT_CLKO    ;   //0000,0000 外部中断与时钟输出控制寄存器

//定时器特殊功能寄存器
__sfr  __at   0x88  TCON        ;   //0000,0000 T0/T1控制寄存器
__sbit __at   0x8F  TF1        ;
__sbit __at   0x8E  TR1        ;
__sbit __at   0x8D  TF0        ;
__sbit __at   0x8C  TR0        ;
__sbit __at   0x8B  IE1        ;
__sbit __at   0x8A  IT1        ;
__sbit __at   0x89  IE0        ;
__sbit __at   0x88  IT0        ;
__sfr  __at   0x89  TMOD        ;   //0000,0000 T0/T1模式寄存器
__sfr  __at   0x8A  TL0         ;   //0000,0000 T0低字节
__sfr  __at   0x8B  TL1         ;   //0000,0000 T1低字节
__sfr  __at   0x8C  TH0         ;   //0000,0000 T0高字节
__sfr  __at   0x8D  TH1         ;   //0000,0000 T1高字节
__sfr  __at   0xD1  T4T3M       ;   //0000,0000 T3/T4模式寄存器
__sfr  __at   0xD1  T3T4M       ;   //0000,0000 T3/T4模式寄存器
__sfr  __at   0xD2  T4H         ;   //0000,0000 T4高字节
__sfr  __at   0xD3  T4L         ;   //0000,0000 T4低字节
__sfr  __at   0xD4  T3H         ;   //0000,0000 T3高字节
__sfr  __at   0xD5  T3L         ;   //0000,0000 T3低字节
__sfr  __at   0xD6  T2H         ;   //0000,0000 T2高字节
__sfr  __at   0xD7  T2L         ;   //0000,0000 T2低字节
__sfr  __at   0xAA  WKTCL       ;   //0000,0000 掉电唤醒定时器低字节
__sfr  __at   0xAB  WKTCH       ;   //0000,0000 掉电唤醒定时器高字节
__sfr  __at   0xC1  WDT_CONTR   ;   //0000,0000 看门狗控制寄存器

//串行口特殊功能寄存器
__sfr  __at   0x98  SCON        ;   //0000,0000 串口1控制寄存器
__sbit __at   0x9F  SM0        ;
__sbit __at   0x9E  SM1        ;
__sbit __at   0x9D  SM2        ;
__sbit __at   0x9C  REN        ;
__sbit __at   0x9B  TB8        ;
__sbit __at   0x9A  RB8        ;
__sbit __at   0x99  TI         ;
__sbit __at   0x98  RI         ;
__sfr  __at   0x99  SBUF        ;   //xxxx,xxxx 串口1数据寄存器
__sfr  __at   0x9A  S2CON       ;   //0000,0000 串口2控制寄存器
__sfr  __at   0x9B  S2BUF       ;   //xxxx,xxxx 串口2数据寄存器
__sfr  __at   0xAC  S3CON       ;   //0000,0000 串口3控制寄存器
__sfr  __at   0xAD  S3BUF       ;   //xxxx,xxxx 串口3数据寄存器
__sfr  __at   0x84  S4CON       ;   //0000,0000 串口4控制寄存器
__sfr  __at   0x85  S4BUF       ;   //xxxx,xxxx 串口4数据寄存器
__sfr  __at   0xA9  SADDR       ;   //0000,0000 从机地址寄存器
__sfr  __at   0xB9  SADEN       ;   //0000,0000 从机地址屏蔽寄存器

//ADC 特殊功能寄存器
__sfr  __at   0xBC  ADC_CONTR   ;   //0000,0000 A/D转换控制寄存器
__sfr  __at   0xBD  ADC_RES     ;   //0000,0000 A/D转换结果高8位
__sfr  __at   0xBE  ADC_RESL    ;   //0000,0000 A/D转换结果低2位

//SPI 特殊功能寄存器
__sfr  __at   0xCD  SPSTAT      ;   //00xx,xxxx SPI状态寄存器
__sfr  __at   0xCE  SPCTL       ;   //0000,0100 SPI控制寄存器
__sfr  __at   0xCF  SPDAT       ;   //0000,0000 SPI数据寄存器

//IAP/ISP 特殊功能寄存器
__sfr  __at   0xC2  IAP_DATA    ;   //0000,0000 EEPROM数据寄存器
__sfr  __at   0xC3  IAP_ADDRH   ;   //0000,0000 EEPROM地址高字节
__sfr  __at   0xC4  IAP_ADDRL   ;   //0000,0000 EEPROM地址第字节
__sfr  __at   0xC5  IAP_CMD     ;   //xxxx,xx00 EEPROM命令寄存器
__sfr  __at   0xC6  IAP_TRIG    ;   //0000,0000 EEPRPM命令触发寄存器
__sfr  __at   0xC7  IAP_CONTR   ;   //0000,x000 EEPROM控制寄存器

//PCA/PWM 特殊功能寄存器
__sfr  __at   0xD8  CCON        ;   //00xx,xx00 PCA控制寄存器
__sbit __at   0xDF  CF         ;
__sbit __at   0xDE  CR         ;
__sbit __at   0xDA  CCF2       ;
__sbit __at   0xD9  CCF1       ;
__sbit __at   0xD8  CCF0       ;
__sfr  __at   0xD9  CMOD        ;   //0xxx,x000 PCA 工作模式寄存器
__sfr  __at   0xE9  CL          ;   //0000,0000 PCA计数器低字节
__sfr  __at   0xF9  CH          ;   //0000,0000 PCA计数器高字节
__sfr  __at   0xDA  CCAPM0      ;   //0000,0000 PCA模块0的PWM寄存器
__sfr  __at   0xDB  CCAPM1      ;   //0000,0000 PCA模块1的PWM寄存器
__sfr  __at   0xDC  CCAPM2      ;   //0000,0000 PCA模块2的PWM 寄存器
__sfr  __at   0xEA  CCAP0L      ;   //0000,0000 PCA模块0的捕捉/比较寄存器低字节
__sfr  __at   0xEB  CCAP1L      ;   //0000,0000 PCA模块1的捕捉/比较寄存器低字节
__sfr  __at   0xEC  CCAP2L      ;   //0000,0000 PCA模块2的捕捉/比较寄存器低字节
__sfr  __at   0xF2  PCA_PWM0    ;   //xxxx,xx00 PCA模块0的PWM寄存器
__sfr  __at   0xF3  PCA_PWM1    ;   //xxxx,xx00 PCA模块1的PWM寄存器
__sfr  __at   0xF4  PCA_PWM2    ;   //xxxx,xx00 PCA模块1的PWM寄存器
__sfr  __at   0xFA  CCAP0H      ;   //0000,0000 PCA模块0的捕捉/比较寄存器高字节
__sfr  __at   0xFB  CCAP1H      ;   //0000,0000 PCA模块1的捕捉/比较寄存器高字节
__sfr  __at   0xFC  CCAP2H      ;   //0000,0000 PCA模块2的捕捉/比较寄存器高字节

//比较器特殊功能寄存器
__sfr  __at   0xE6  CMPCR1      ;   //0000,0000 比较器控制寄存器1
__sfr  __at   0xE7  CMPCR2      ;   //0000,0000 比较器控制寄存器2

//增强型PWM波形发生器特殊功能寄存器
__sfr  __at   0xf1  PWMCFG      ;   //x000,0000 PWM配置寄存器
__sfr  __at   0xf5  PWMCR       ;   //0000,0000 PWM控制寄存器
__sfr  __at   0xf6  PWMIF       ;   //x000,0000 PWM中断标志寄存器
__sfr  __at   0xf7  PWMFDCR     ;   //xx00,0000 PWM外部异常检测控制寄存器

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define PWM2T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM2T1H     (*(unsigned char volatile xdata *)0xff00)
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff01)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff02)
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff03)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM3T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM3T1H     (*(unsigned char volatile xdata *)0xff10)
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff11)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff12)
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff13)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM4T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM4T1H     (*(unsigned char volatile xdata *)0xff20)
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff21)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff22)
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff23)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM5T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM5T1H     (*(unsigned char volatile xdata *)0xff30)
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff31)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff32)
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff33)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM6T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM6T1H     (*(unsigned char volatile xdata *)0xff40)
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff41)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff42)
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff43)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM7T1      (*(unsigned int  volatile xdata *)0xff50)        
#define PWM7T1H     (*(unsigned char volatile xdata *)0xff50)        
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff51)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff52)
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff53)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff54)

/////////////////////////////////////////////////

#endif

