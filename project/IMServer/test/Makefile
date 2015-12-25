CC = gcc

LDFLAGS= 

BIN = test_iniparser

EXSRC= ../src/dictionary.c ../src/iniparser.c
SRC = $(shell ls *.c )
OBJ = $(SRC:.c=.o)

all:$(BIN)
	@echo "finished make Output:\""$(BIN)"\""


test_iniparser:$(OBJ)
	$(CC) -o $@ $(OBJ) $(EXSRC)

clean:$(BIN)
	rm -rf $(BIN)
	rm -rf *.o

