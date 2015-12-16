#编译所有文件
#make

#编译指定文件
#make xxx （不要写.c）

#清除所有生成的文件
#make clean
CC:=gcc
CFLAGS:=-g -o
CLIBS:=-pthread
#CINCS:=-I/home/zm/include

C_SRC:=$(wildcard *.c)
C_OBJ:=${C_SRC:%.c=%.o}
C_BIN:=${C_SRC:%.c=%}

all:$(C_BIN)
%:%.c
	$(CC) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

.PHONY:clean
clean:
	rm -rf *.o $(C_BIN)
