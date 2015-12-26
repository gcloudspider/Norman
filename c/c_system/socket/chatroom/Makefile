CXX=gcc

BIN=chatroom

SRC=$(shell ls *.c)
OBJ=$(SRC:.c=.o)

all:$(BIN)
	@echo "Output:\"" $(BIN)"\""

$(BIN):$(OBJ)
	$(CXX) -o $@ $(OBJ)

clean:
	rm -rf $(BIN)
	rm -rf *.o
