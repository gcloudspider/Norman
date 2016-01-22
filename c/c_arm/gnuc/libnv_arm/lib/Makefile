ARM_CC=arm-linux-gcc
ARM_AR=ar

CLFAGS=-c -o

ARM_SRCS=$(wildcard *.c)
OBJ_SRCS=$(patsubst %.c,%.o,$(ARM_SRCS))
LIB_OBJ=libnv_arm.a

.PHONY:all clean

all:$(OBJ_SRCS)
	$(ARM_AR) cr $(LIB_OBJ) $(OBJ_SRCS)

%.o:%.c
	$(ARM_CC) $(CLFAGS) $@ $<

clean:
	rm -rf *.o $(LIB_OBJ)
