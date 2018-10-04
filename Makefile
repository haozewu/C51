CC = sdcc
cname = lession
proj = output
tmpdir = tmp
usrdir = usr
all : $(cname).hex

$(cname).hex : $(cname).ihx
	packihx $(tmpdir)\$(cname).ihx > $(cname).hex

$(cname).ihx : $(usrdir)\$(cname).c
	$(CC) $(usrdir)\$(cname).c -o $(tmpdir)\$(cname).ihx

.PHONY : clean
clean :
	del /f /q $(tmpdir)\$(cname).asm $(tmpdir)\$(cname).ihx \
		$(tmpdir)\$(cname).lk $(tmpdir)\$(cname).lst \
		$(tmpdir)\$(cname).map $(tmpdir)\$(cname).mem \
		$(tmpdir)\$(cname).rel $(tmpdir)\$(cname).rst \
		$(tmpdir)\$(cname).sym $(cname).hex