CXX:=gcc
#CFLAGS:= -g -o
CLIBS:= -pthread

SRC:=$(wildcard *.c)
OBJ:=${SRC:%.c=%.o}
BIN:=ChatServer

all:$(BIN)
	@echo "Output:\"" $(BIN)"\""

$(BIN):$(OBJ)
	$(CXX) -g -o $@ $(SRC) $(CLIBS)

clean:
	rm -rf $(BIN)
	rm -rf *.o
