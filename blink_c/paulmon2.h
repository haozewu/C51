#ifndef PAULMON2_H_INCLUDED
#define PAULMON2_H_INCLUDED

#pragma CALLEE-SAVES pm2_cout,pm2_cin,pm2_phex,pm2_phex16,pm2_pstr,pm2_upper
#pragma CALLEE-SAVES pm2_pint8u,pm2_pint8,pm2_newline,pm2_restart

extern void pm2_cout(char c);
extern char pm2_cin(void);
extern void pm2_phex(unsigned char c);
extern void pm2_phex16(unsigned int i);
extern void pm2_pstr(code char *str);
extern char pm2_esc(void);
extern char pm2_upper(char c);
extern void pm2_pint8u(unsigned char c);
extern void pm2_pint8(char c);
extern void pm2_pint16u(unsigned int i);
extern void pm2_newline(void);
extern void pm2_restart(void);
extern void pm2_interrupt_remap(void);

#define PM2_PROGRAM_TYPE 0x0000FF23


typedef struct paulmon2_header_struct {
	unsigned long signature;
	unsigned long program_type;
	unsigned long reserved1;
	unsigned long reserved2;
	unsigned long reserved3;
	unsigned long user;
	unsigned int length;
	unsigned int cksum;
	char name[32];
} paulmon2_header_t;

/* In theory, this struct ought to allow you to define a PM2 
 * program header like this:
 *
 *	code at 0x2100 paulmon2_header_t header={
 *	     	0xA5E0E5A5,
 *        	PM2_PROGRAM_TYPE,
 *        	0, 0, 0, 0,
 *        	0xFFFF, 0xFFFF,
 *        	"Blink Example #1 (SDCC)"
 *	};
 *
 * In practice, it doesn't work because SDCC doesn't have a
 * way to pass non-relocatable code to the linker.
 *
 */

#endif
