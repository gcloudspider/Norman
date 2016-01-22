SUBDIRS=lib

ARM_CC=arm-linux-gcc
ARM_LD=arm-linux-ld
ARM_OBJCOPY=arm-linux-objcopy

CLFALGS= -c -o 
#LD_CLFALGS=-Ttext 0x0
LD_CLFALGS=-Ttime.lds
OBJ_CLFALGS=-O binary


ARM_SRCS=$(wildcard *.c)
OBJ_SRCS=$(patsubst %.c,%.o,$(ARM_SRCS))
ARM_SAMS=$(wildcard *.s)
OBJ_SAMS=$(patsubst %.s,%.o,$(ARM_SAMS))

ARM_BIN=$(shell pwd|xargs basename)
ARM_ELF=$(ARM_BIN).elf
BIN=$(ARM_BIN).bin

.PHONY:all clean $(SUBDIRS)

all:$(SUBDIRS) $(BIN)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

$(BIN):$(OBJ_SAMS) $(OBJ_SRCS)
	$(ARM_LD) $(LD_CLFALGS) $(OBJ_SAMS) $(OBJ_SRCS) ./lib/libnv_arm.a -o $(ARM_ELF)
	$(ARM_OBJCOPY) $(OBJ_CLFALGS) -S $(ARM_ELF) $(BIN)
	
%.o:%.s
	$(ARM_CC) $(CLFALGS) $@ $<

%.o:%.c
	$(ARM_CC) $(CLFALGS) $@ $<

clean:$(SUBDIRS)
	rm -rf *.o $(ARM_ELF) $(BIN)
