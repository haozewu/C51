#include<8052.h>
#define D4 P1_3
unsigned int a;
void main()
{
	while(1)
	{
		a = 51000;
		D4 = 0;
		while(a--);		
		a = 51000;
		D4 = 1;
		while(a--);
   }
}
