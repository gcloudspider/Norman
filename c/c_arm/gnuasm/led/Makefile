ARM_CC=arm-linux-gcc
ARM_LD=arm-linux-ld
ARM_OBJCOPY=arm-linux-objcopy

ARM_SRC=$(wildcard *.s)
ARM_OBJ=${ARM_SRC:%.s=%.o}
CFLAGS=

ARM_BIN=

.PHONY:all clean

all:head

head:head.s
	$(ARM_CC) -c -o head.o head.s
	$(ARM_LD) -Ttext 0x0 head.o -o head.elf
	$(ARM_OBJCOPY) -O binary -S head.elf head.bin

clean:
	rm -rf *.o *.elf *.bin
