#清除所有生成的文件
CC:=gcc

CFLAGS:=-g -o

C_SRC:=$(wildcard *.c) 			#搜索所有的.c文件

C_OBJ:=${C_SRC:%.c=%.o}

C_BIN:=${C_SRC:%.c=%} 			#把所有.c文件转换成文件名目标文件

all:$(C_BIN)

%:%.c
	$(CC) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

.PHONY:clean
clean:
	rm -rf *.o $(C_BIN)
