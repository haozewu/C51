/**
 * @author: ciabeta.
 * @date: 2018.10.28
 * @description:　一个最简单的流水灯
 */
#include<8052.h>

#define D1 P1
void delay();
void main()
{
    D1 = ~0x01;
    while(1)
    {
        D1 = ~((~D1)<<1);
        delay();
        if(D1 == 0x7f)
        {
            D1 = ~0x01; 
            delay();
        }
    }
}
void delay()
{
	unsigned int x,y;
	for(x=500;x>0;x--)
		for(y=400;y>0;y--);
}