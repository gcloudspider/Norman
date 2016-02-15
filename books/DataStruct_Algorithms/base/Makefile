SUBDIRS:=currency currency_new

CC:=g++

CFLAGS:=-g -o

C_SRC:=$(wildcard *.cpp) 			#搜索所有的.c文件

C_OBJ:=${C_SRC:%.cpp=%.o}

C_BIN:=${C_SRC:%.cpp=%} 			#把所有.c文件转换成文件名目标文件

.PHONY:all clean $(SUBDIRS)

all:$(SUBDIRS) $(C_BIN)

%:%.cpp
	$(CC) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

clean:$(SUBDIRS)
	rm -rf *.o $(C_BIN)
