CC:=g++
CFLAGS:=-g -o
CLIBS:=-lboost_regex -lboost_system -lboost_thread

C_SRC:=$(wildcard *.cpp) 			#搜索所有的.c文件

C_OBJ:=${C_SRC:%.cpp=%.o}

C_BIN:=${C_SRC:%.cpp=%} 			#把所有.c文件转换成文件名目标文件

all:$(C_BIN)

%:%.cpp
	$(CC) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

.PHONY:clean
clean:
	rm -rf *.o $(C_BIN)
