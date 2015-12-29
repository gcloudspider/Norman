#编译所有文件
#make

#编译指定文件
#make xxx （不要写.c）

#清除所有生成的文件
#make clean
CC:=gcc
CXX:=g++

CFLAGS:=-g -o

CLIBS:=-pthread
#CINCS:=-I/home/zm/include

C_SRC:=$(wildcard *.c) 			#搜索所有的.c文件
CPP_SRC:=$(wildcard *.cpp)

C_OBJ:=${C_SRC:%.c=%.o}
CPP_OBJ:=$(CPP_SRC:%.cpp=%.o)

C_BIN:=${C_SRC:%.c=%} 			#把所有.c文件转换成文件名目标文件
CPP_BIN:=$(CPP_SRC:%.cpp=%)

all:$(C_BIN) $(CPP_BIN)

%:%.c
	$(CC) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

%:%.cpp
	$(CXX) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

.PHONY:clean
clean:
	rm -rf *.o $(C_BIN) $(CPP_BIN)
