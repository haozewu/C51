#使用的编译器

CC = sdcc

#传入的c文件名
TARGET_ARCH = $(target)

cname = $(TARGET_ARCH)
proj = output
tmpdir = tmp
usrdir = usr
all : $(cname).hex
	mkdir tmp

$(cname).hex : $(cname).ihx
	packihx $(tmpdir)/$(cname).ihx > $(cname).hex

$(cname).ihx : $(usrdir)/$(cname).c
	$(CC) $(usrdir)/$(cname).c -o $(tmpdir)/$(cname).ihx

.PHONY : clean
clean :
	rm *.hex
	rm tmp/*.rel
	rm tmp/*.rst
	rm tmp/*.sym
	rm tmp/*.mem
	rm tmp/*.map
	rm tmp/*.lst
	rm tmp/*.lk
	rm tmp/*.ihx
	rm tmp/*.asm
	
