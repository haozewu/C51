#include "delay_ms.h"
#include "paulmon2.h"

/* these are the memory-mapped locations used to access */
/* the two 82C55 chips */
xdata at 0xF800 unsigned char p82c55_port_a;
xdata at 0xF801 unsigned char p82c55_port_b;
xdata at 0xF802 unsigned char p82c55_port_c;
xdata at 0xF803 unsigned char p82c55_abc_config;
xdata at 0xF900 unsigned char p82c55_port_d;
xdata at 0xF901 unsigned char p82c55_port_e;
xdata at 0xF902 unsigned char p82c55_port_f;
xdata at 0xF903 unsigned char p82c55_def_config;

#define VERBOSE

code unsigned char pattern_table[] = {
0x7F, /* 01111111 */
0x3F, /* 00111111 */
0x1F, /* 00011111 */
0x8F, /* 10001111 */
0xC7, /* 11000111 */
0xE3, /* 11100011 */
0xF1, /* 11110001 */
0xF8, /* 11111000 */
0xFC, /* 11111100 */
0xFE, /* 11111110 */
0xFC, /* 11111100 */
0xF8, /* 11111000 */
0xF1, /* 11110001 */
0xE3, /* 11100011 */
0xC7, /* 11000111 */
0x8F, /* 10001111 */
0x1F, /* 00011111 */
0x3F, /* 00111111 */
255};

code unsigned char delay_table[] = {
90,
70,
50,
40,
40,
40,
40,
50,
70,
90,
70,
50,
40,
40,
40,
40,
50,
70,
0};	/* zero marks end of table */

void main()
{
	unsigned char i=0;

	p82c55_abc_config = 128;	/* all ports outputs */
	p82c55_def_config = 128;

	while (1) {
		if (delay_table[i] > 0) {
			p82c55_port_e = pattern_table[i];
			delay_ms(delay_table[i]);
#ifdef VERBOSE
			pm2_pstr("Pattern=0x");
			pm2_phex(pattern_table[i]);
			pm2_pstr(" for delay=");
			pm2_pint8u(delay_table[i]);
			pm2_newline();
#endif
			i++;
		} else {
			i = 0;
		}
		if (pm2_esc()) pm2_restart();
	}
}


