CXX:=gcc
#CFLAGS:= -g -o
CLIBS:= -pthread -lm -I.

SRC:=$(wildcard *.c)
OBJ:=${SRC:%.c=%.o}
BIN:=client

all:$(BIN)
	@echo "Output:\"" $(BIN)"\""

$(BIN):$(OBJ)
	$(CXX) -g -o $@ $(SRC) $(CLIBS)

$(%.c=%.o):
	$(CXX) -g -c $@

clean:
	rm -rf $(BIN)
	rm -rf *.o
