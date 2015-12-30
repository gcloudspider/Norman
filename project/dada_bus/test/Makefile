CC = gcc

LDFLAGS= -lmysqlclient

BIN = test_iniparser test_hello test_database

INIEXSRC= ../src/dictionary.c ../src/iniparser.c 
LOGEXSRC= ../src/log.c 


SRC:= $(shell ls *.c )
OBJ = $(SRC:%.c=%.o)

.PHONY:all clean

all:$(BIN)
	@echo "finished make Output:\""$(BIN)"\""


$(BIN):

test_iniparser:
	$(CC) -o $@ $(OBJ) $(INIEXSRC) $(LDFLAGS)

clean:
	rm -rf $(BIN)
	rm -rf *.o

