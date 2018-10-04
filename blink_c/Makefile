# PJRC 8051 Development Board (Rev 4), Blink Example Makefile

# This Makefile controls the how GNU Make will build "blink1.hex"
# and "blink2.hex" when you type "make".  This Makefile is filled
# with verbose comments to help you understand what each part of
# this Makefile does and how you can reuse this example to start
# your own projects.



# This first section is declaring some variables which will be
# used in the rules below.  That way, you can specify some
# important options to be used everywhere and only need to
# edit one place to make the change apply everywhere (that
# makes use of a particular variable).

# Usually SDCC's small memory model is the best choice.  If
# you run out of internal RAM, you will need to declare
# variables as "xdata", or switch to large model

SDCCCFLAGS = --model-small


# These settings control where the compiler will place the code
# and variables in memory.  The executable code will begin at
# 4000.  Internal ram usage for variables will begin at 30 (which
# is just after the 8051's 4 register banks and bit variables).
# Variables in external RAM ("xdata" type) will begin at 1000.

ASLINKFLAGS = --code-loc 0x2000 --data-loc 0x30 --stack-after-data --xram-loc 0x6000





# Now that the variables are defined, it's time for the "rules"
# that tell GNU Make how to build each file, what other files
# are required as input, and when command(s) to execute.



# This "implicit" rule tells make that any file ending in .rel is
# build from two files with the same base name ending in .c and .h,
# and that the command "sdcc $(SDCCCFLAGS) -c" followed by the two
# .c and .h files is the way to obtain the .rel file.  Whenever any
# of the rules below specifies that a .rel file is required, make
# will use this rule (in the absence of an explicit rule for that
# file) to build the .rel file.

%.rel : %.c %.h
	sdcc $(SDCCCFLAGS) -c $<

# All rules in a makefile begin with a line that specifies what
# gets built (output), a colon (:), and what files are needed
# (input).  After the first line, lines beginning with a TAB
# list the commands that must be executed to turn the input
# file(s) into the output file(s).  It is critical that the
# command lines begin with a TAB (not 8 spaces).



# This first explicit rule in the file, which is the rule that make
# will attempt to build when you type "make" (with no additional
# parameters on the command line).  In this case, "all" is a dummy
# rule with no actions to perform, but before make can do "nothing",
# it must build "blink1.hex" and "blink2.hex".

all: blink1.hex blink2.hex




# An explicit rule tells make how to build "blink1.hex"  Three
# files are required, and two of them are .rel files (so if they
# are not up-to-date, make will use the implicit rul to build
# them before attempting to build blink1.hex).  Two commands are
# needed... one to run sdcc, and another to run the "packihx"
# utility that cleans up the intel hex output.  The $^ is a
# shorthand syntax for "blink1.c delay_ms.rel paulmon2.rel"
# (or whatever the list of dependant files happens to be).  If
# you add more .c files to this project, usually you can just
# add their .rel name to the end of the dependancy list.

blink1.hex: blink1.c delay_ms.rel paulmon2.rel
	sdcc $(SDCCCFLAGS) $(ASLINKFLAGS) $^
	packihx blink1.ihx > blink1.hex




# This explicit rule works just like the one for blink1.hex.

blink2.hex: blink2.c delay_ms.rel paulmon2.rel
	sdcc $(SDCCCFLAGS) $(ASLINKFLAGS) $^
	packihx blink2.ihx > blink2.hex





# This final rule is what's called a "phony rule" or "phony target",
# because it isn't used in ary part of the normal build process.
# By typing "make clean", make will attempt to build this rule and
# these commands will delete all of the compiler generated files.
# If you are using Microsoft DOS/Windows, you may need to change
# these to a long list "DEL" commands.
clean:
	rm -f blink1.asm blink2.asm delay_ms.asm paulmon2.asm
	rm -f *.hex *.ihx *.lnk *.lst *.map *.rel *.rst *.sym


