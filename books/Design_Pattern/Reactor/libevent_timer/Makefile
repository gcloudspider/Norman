CXX=gcc

CLFAGS=-g -o 
LIB=-levent

SRC=$(wildcard *.c)
OBJ=${SRC:%.cpp=%.o}

BIN=$(shell pwd|xargs basename)

.PHONY:all clean

all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CLFAGS) $@ $(OBJ) $(LIB)

clean:
	rm -rf *.o $(BIN)
