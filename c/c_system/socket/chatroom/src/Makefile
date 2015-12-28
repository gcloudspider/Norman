CXX:=gcc
#CFLAGS:= -g -o
CLIBS:= -pthread

SRC:=$(wildcard *.c)
OBJ:=${SRC:%.c=%.o}
BIN:=ChatServer

.PHONY:all clean

all:$(BIN)
	@echo "Output:\"" $(BIN)"\""

$(BIN):$(OBJ)
	$(CXX) -g -o $@ $(OBJ) $(CLIBS)

%:%.c
	$(CC) -g -c $<

clean:
	rm -rf $(BIN)
	rm -rf *.o
