ARM_CC=arm-linux-gcc
ARM_LD=arm-linux-ld
ARM_OBJCOPY=arm-linux-objcopy
ARM_AR=ar

CLFAGS=-c -o

ARM_SRCS=$(wildcard *.c)
OBJ_SRCS=$(patsubst %.c,%.o,$(ARM_SRCS))
ARM_SAMS=$(wildcard *.s)
OBJ_SAMS=$(patsubst %.s,%.o,$(ARM_SAMS))

LIB_OBJ=libnv_arm.a

.PHONY:all clean

all:$(OBJ_SRCS) $(OBJ_SAMS)
	$(ARM_AR) cr $(LIB_OBJ) $(OBJ_SRCS)

%.o:%.c
	$(ARM_CC) $(CLFAGS) $@ $<

%.o:%.s
	$(ARM_CC) $(CLFAGS) $@ $<

clean:
	rm -rf *.o $(LIB_OBJ)
