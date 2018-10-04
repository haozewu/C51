
/* This is a simple delay based on a busy loop */
/* with a 22.1184 MHz crystal, the delay lasts */
/* for approximately 1 ms times the number passed */
/* Of course, it will take longer if there are */
/* interrupts occuring... */

void delay_ms(unsigned char ms)
{
	ms;
	_asm
        mov     r0, dpl
00001$: mov     r1, #230
00002$: nop
        nop
        nop
        nop
        nop
        nop
        djnz    r1, 00002$
        djnz    r0, 00001$
        ret
	_endasm;
}

