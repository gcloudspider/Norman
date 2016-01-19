ARM_CC=arm-linux-gcc
ARM_LD=arm-linux-ld
ARM_OBJCOPY=arm-linux-objcopy

CLFALGS= -c -o 
LD_CLFALGS=-Ttext 0x0
OBJ_CLFALGS=-O binary


ARM_SRCS=$(wildcard *.c)
OBJ_SRCS=$(patsubst %.c,%.o,$(ARM_SRCS))
ARM_SAMS=$(wildcard *.s)
OBJ_SAMS=$(patsubst %.s,%.o,$(ARM_SAMS))

ARM_BIN=key
ARM_ELF=$(ARM_BIN).elf
BIN=$(ARM_BIN).bin

.PHONY:all clean

all:$(BIN)

$(BIN):$(OBJ_SAMS) $(OBJ_SRCS)
	$(ARM_LD) $(LD_CLFALGS) $(OBJ_SAMS) $(OBJ_SRCS) -o $(ARM_ELF)
	$(ARM_OBJCOPY) $(OBJ_CLFALGS) -S $(ARM_ELF) $(BIN)
	
%.o:%.s
	$(ARM_CC) $(CLFALGS) $@ $<

%.o:%.c
	$(ARM_CC) $(CLFALGS) $@ $<

clean:
	rm -rf *.o $(ARM_ELF) $(BIN)
