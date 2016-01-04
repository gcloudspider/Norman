SUBDIRS=client\
		driver

CXX:=gcc
#CFLAGS:= -g -o
CLIBS:= -pthread -lm -I. -lzlog -lmysqlclient

SRC:=$(wildcard *.c)
OBJ:=${SRC:%.c=%.o}
BIN:=didiserver

.PHONY:all clean $(SUBDIRS)

all:$(BIN) $(SUBDIRS)
	@echo "Output:\"" $(BIN)"\""

$(BIN):$(OBJ)
	$(CXX) -g -o $@ $(OBJ) $(CLIBS)

clean: $(SUBDIRS)
	rm -rf $(BIN)
	rm -rf *.o

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)
