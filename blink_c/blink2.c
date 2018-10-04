#include "delay_ms.h"
#include "paulmon2.h"

xdata at 0xF800 unsigned char p82c55_port_a;
xdata at 0xF801 unsigned char p82c55_port_b;
xdata at 0xF802 unsigned char p82c55_port_c;
xdata at 0xF803 unsigned char p82c55_abc_config;
xdata at 0xF900 unsigned char p82c55_port_d;
xdata at 0xF901 unsigned char p82c55_port_e;
xdata at 0xF902 unsigned char p82c55_port_f;
xdata at 0xF903 unsigned char p82c55_def_config;

#define VERBOSE

struct led_pattern_struct {
	unsigned char pattern;
	unsigned char delay;
};

code struct led_pattern_struct led_table[] = {
{0x7F, /* 01111111 */ 90},
{0x3F, /* 00111111 */ 70},
{0x1F, /* 00011111 */ 50},
{0x8F, /* 10001111 */ 40},
{0xC7, /* 11000111 */ 40},
{0xE3, /* 11100011 */ 40},
{0xF1, /* 11110001 */ 40},
{0xF8, /* 11111000 */ 50},
{0xFC, /* 11111100 */ 70},
{0xFE, /* 11111110 */ 90},
{0xFC, /* 11111100 */ 70},
{0xF8, /* 11111000 */ 50},
{0xF1, /* 11110001 */ 40},
{0xE3, /* 11100011 */ 40},
{0xC7, /* 11000111 */ 40},
{0x8F, /* 10001111 */ 40},
{0x1F, /* 00011111 */ 50},
{0x3F, /* 00111111 */ 70},
{255,0}};


void main()
{
	code struct led_pattern_struct *p=led_table;

	p82c55_abc_config = 128;	/* all ports outputs */
	p82c55_def_config = 128;

	while (1) {
		if (p->delay > 0) {
			p82c55_port_e = p->pattern;
			delay_ms(p->delay);
#ifdef VERBOSE
                        pm2_pstr("Pattern=0x");
                        pm2_phex(p->pattern);
                        pm2_pstr(" for delay=");
                        pm2_pint8u(p->delay);
                        pm2_newline();
#endif
			p++;
		} else {
			p = led_table;
		}
		if (pm2_esc()) pm2_restart();
	}
}


