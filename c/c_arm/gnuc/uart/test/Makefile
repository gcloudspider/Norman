SRCDIRS=../src
ARM_CC=arm-linux-gcc
ARM_LD=arm-linux-ld
ARM_OBJCOPY=arm-linux-objcopy

CLFALGS= -c -o 
LD_CLFALGS=-T$(SRCDIRS)/libnv.lds
OBJ_CLFALGS=-O binary


ARM_SRCS=$(wildcard *.c)
OBJ_SRCS=$(patsubst %.c,%.o,$(ARM_SRCS))

ARM_BIN=$(patsubst %.c,%,$(ARM_SRCS))
ARM_ELF=$(ARM_BIN).elf
BIN=$(ARM_BIN).bin

.PHONY:all clean $(SRCDIRS)

all:$(BIN)

$(BIN):$(OBJ_SRCS)
	$(ARM_LD) $(LD_CLFALGS) $(OBJ_SAMS) $(OBJ_SRCS) $(SRCDIRS)/libnv_arm.a -o $(ARM_ELF)
	$(ARM_OBJCOPY) $(OBJ_CLFALGS) -S $(ARM_ELF) $(BIN)
	
%.o:%.c
	$(ARM_CC) $(CLFALGS) $@ $<

clean:
	rm -rf *.o $(ARM_ELF) $(BIN)
