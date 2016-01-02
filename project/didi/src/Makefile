CXX:=gcc
#CFLAGS:= -g -o
CLIBS:= -pthread -lm -I. -lzlog -lmysqlclient

SRC:=$(wildcard *.c)
OBJ:=${SRC:%.c=%.o}
BIN:=didiserver

.PHONY:all clean

all:$(BIN)
	@echo "Output:\"" $(BIN)"\""

$(BIN):$(OBJ)
	$(CXX) -g -o $@ $(SRC) $(CLIBS)

clean:
	rm -rf $(BIN)
	rm -rf *.o
