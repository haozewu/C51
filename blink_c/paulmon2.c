/*
 * PAULMON2 Built-In Functions, "Glue" to SDCC C Programs
 *
 * This "glue" allows SDCC-based applications to call the
 * built-in functions within PAULMON2.  For more information
 * about the PAULMON2 monitor, see the PAULMON2 web page:
 *
 *   http://www.pjrc.com/tech/8051/paulmon2.html
 *
 * This code is intended to be built with SDCC.  Your C code that
 * calls these functions must include "paulmon2.h" for the function
 * prototypes, and then when you link your application, you'll need
 * to include "paulmon2.rel" on the command like, like this:
 *
 * sdcc --code-loc 0x2000 --stack-after-data  yourcode.c  paulmon2.rel
 *
 * This code is an original work of authorship by Paul Stoffregen
 * and has been placed in the PUBLIC DOMAIN.  There is no copyright
 * and no license agreement.  You may use this code in any manner
 * you wish without a royalty or other conditions, even embedded in
 * your own for-profit product.
 *
 * This code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of merchantability or fitness for a particular purpose. 
 */


/* well-known entry points to access PAULMON2's built-in functions */
#define pm2_entry_cout    0x0030
#define pm2_entry_cin     0x0032
#define pm2_entry_phex    0x0034
#define pm2_entry_phex16  0x0036
#define pm2_entry_pstr    0x0038
#define pm2_entry_esc     0x003E
#define pm2_entry_upper   0x0040
#define pm2_entry_pint8u  0x004D
#define pm2_entry_pint8   0x0050
#define pm2_entry_pint16u 0x0053
#define pm2_entry_newline 0x0048
#define pm2_entry_prgm    0x0059
#define pm2_entry_erblock 0x0067


/* print a character using PAULMON2's polled serial I/O */
void pm2_cout(char c) _naked
{
	c;
	_asm
	mov	a, dpl
	ljmp	pm2_entry_cout
	_endasm;
}

/* call PM2's cin routine to receive the next character */
/* from the serial port.  This function will wait until */
/* a character is recieved */
char pm2_cin(void)
{
	_asm
	lcall	pm2_entry_cin
	mov	dpl, a
	_endasm;
}

void pm2_phex(unsigned char c) _naked
{
	c;
	_asm
	mov	a, dpl
	ljmp	pm2_entry_phex
	_endasm;
}

void pm2_phex16(unsigned int i) _naked
{
	i;
	_asm
	ljmp	pm2_entry_phex16
	_endasm;
}

void pm2_pstr(code char *str) _naked
{
	str;
	_asm
	ljmp	pm2_entry_pstr
	_endasm;
}

char pm2_esc(void)
{
	_asm
	lcall	pm2_entry_esc
	clr	a
	rlc	a
	mov	dpl, a
	_endasm;
}

char pm2_upper(char c)
{
	c;
	_asm
	mov	a, dpl
	lcall	pm2_entry_upper
	mov	dpl, a
	_endasm;
}

void pm2_pint8u(unsigned char c) _naked
{
	c;
	_asm
	mov	a, dpl
	ljmp	pm2_entry_pint8u
	_endasm;
}

void pm2_pint8(char c) _naked
{
	c;
	_asm
	mov	a, dpl
	ljmp	pm2_entry_pint8
	_endasm;
}

void pm2_pint16u(unsigned int i) _naked
{
	i;
	_asm
	ljmp	pm2_entry_pint16u
	_endasm;
}

void pm2_newline(void) _naked
{
	_asm
	ljmp	pm2_entry_newline
	_endasm;
}

void pm2_restart(void) _naked
{
	_asm
	ljmp	0
	_endasm;
}


/* this function will write LJMP instructions into SRAM
 * wherever PM2's LJMPs point to, which in turn jump to
 * the application's interrupt vectors.  This is useful
 * for an application located in flash at 0x8000, when
 * PM2's interrupt vectors point to 0x2000.  If any
 * variables are stored at the 0x2000 - 0x2030 range
 * (or whereever PM2's LJMPs point), this will overwrite
 * them without any warning.  You do not need to pass any
 * parameters to this function... it reads PM2's code to
 * find out where its LJMPs point, and it uses a special
 * linker symbol to resolve where the C application
 * interrupt routines will be in memory.
 */

void pm2_interrupt_remap(void)
{
	_asm
	mov	r4, #3		;first interrupt vector offset=3
00001$: mov	dpl, r4
	mov	dph, #0
	mov	a, #1
	movc	a, @a+dptr	;read interrupt LJMP (MSB) within PM2
	mov	r2, a
	mov	a, #2
	movc	a, @a+dptr	;read interrupt LJMP (LSB) within PM2
	mov	dpl, a
	mov	dph, r2		;now DPTR points to SRAM interrupt vector
	mov	a, #2
	movx	@dptr, a	;write the LJMP opcode
	inc	dptr
	mov	a, #s_CSEG
	add	a, r4		;compute C application interrupt address
	mov	r2, a
	clr	a
	addc	a, #(s_CSEG >> 8)
	movx	@dptr, a	;write LJMP destination, MSB
	inc	dptr
	mov	a, r2
	movx	@dptr, a	;write LJMP destination, LSB
	mov	a, r4
	add	a, #8
	mov	r4, a
	add	a, #0xD0
	jnc	00001$		;loop until we have remapped them all
	_endasm;
}




