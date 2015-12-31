CC = gcc

LDFLAGS1= -lmysqlclient
LDFLAGS2= -lm -I.

BIN1 = test_iniparser
BIN2 = test_log
BIN3 = test_database
BIN4 = $(SRC4:%.c=%) 

INIEXSRC= ../src/dictionary.c ../src/iniparser.c 
LOGEXSRC= ../src/log.c 
JSONEXSRC= ../src/cjson.c

SRC1= test_iniparser.c
SRC2= test_log.c
SRC3= test_database.c
SRC4= $(wildcard *json*.c)

OBJ1 = $(SRC1:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)
OBJ3 = $(SRC3:%.c=%.o)
OBJ4 = $(SRC4:%.c=%.o)

.PHONY:all clean

all:$(BIN1) $(BIN2) $(BIN3) $(BIN4)
	@echo "finished make Output:\""$(BIN1) $(BIN2) $(BIN3) $(BIN4)"\""


$(BIN1):$(OBJ1)
	$(CC) -o $@ $(OBJ1) $(INIEXSRC)

$(BIN2):$(OBJ2)
	$(CC) -o $@ $(OBJ2) $(LOGEXSRC)

$(BIN3):$(OBJ3)
	$(CC) -o $@ $(OBJ3) $(LDFLAGS1)

$(BIN4):$(OBJ4)
	$(CC) -o $@ $@.o $(JSONEXSRC) $(LDFLAGS2)

clean:
	rm -rf $(BIN1) $(BIN2) $(BIN3) $(BIN4)
	rm -rf *.o

