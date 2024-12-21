# commands/Makefile

#ENTRYPOINT	= 0x1000
HD		= ../80m.img

ASM		= nasm
DASM		= objdump
CC		= gcc
LD		= ld
ASMFLAGS	= -I ../include/ -f elf
CFLAGS		= -I ../include/ -c -fno-builtin -fno-stack-protector -Wall -m32
LDFLAGS		= -Ttext 0x1000 -m elf_i386

DASMFLAGS	= -D
LIB		= ../lib/orangescrt.a
BIN		= touch rm ls cat vim process kill  test cat2

# All Phony Targets
.PHONY : everything final clean realclean disasm all install

# Default starting position
everything : $(BIN)

install : all clean
	cp ../boot/hd*.bin ./ -v
	cp ../kernel.bin ./ -v
	tar vcf inst.tar kernel.bin $(BIN) hd*.bin
	dd if=inst.tar of=$(HD) seek=`echo "obase=10;ibase=16;(\`egrep -e '^ROOT_BASE' ../boot/include/load.inc | sed -e 's/.*0x//g'\`+\`egrep -e '#define[[:space:]]*INSTALL_START_SECT' ../include/sys/config.h | sed -e 's/.*0x//g'\`)*200" | bc` bs=1 count=`ls -l inst.tar | awk -F " " '{print $$5}'` conv=notrunc

all : realclean everything

final : all clean

clean :
	rm -f *.o

realclean :
	rm -f $(BIN) *.o

kernel.bin :
	cp ../kernel.bin ./

start.o : start.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

echo.o: echo.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

echo : echo.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

touch.o: touch.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

touch : touch.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

rm.o: rm.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

rm : rm.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

ls.o: ls.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

ls : ls.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

cat.o: cat.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

cat : cat.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

cat2.o: cat2.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

cat2 : cat2.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

vim.o: vim.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

vim : vim.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

test.o: test.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

test: test.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

process.o: process.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

process : process.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

kill.o: kill.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

kill : kill.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?




