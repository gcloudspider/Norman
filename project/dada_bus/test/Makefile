CC = gcc

LDFLAGS1= -lmysqlclient
LDFLAGS2= -lm -I.
LDFLAGS3= -lzlog

BIN1 = test_iniparser
BIN2 = test_zlog
BIN3 = $(SRC3:%.c=%)
BIN4 = $(SRC4:%.c=%) 
BIN5 = test_daemon


INIEXSRC= ../src/dictionary.c ../src/iniparser.c 
LOGEXSRC=  
JSONEXSRC= ../src/cjson.c

SRC1= test_iniparser.c
SRC2= test_zlog.c
SRC3= $(wildcard *database*.c)
SRC4= $(wildcard *json*.c)
SRC5= test_daemon.c

OBJ1 = $(SRC1:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)
OBJ3 = $(SRC3:%.c=%.o)
OBJ4 = $(SRC4:%.c=%.o)
OBJ5 = $(SRC5:%.c=%.o)

.PHONY:all clean

all:$(BIN1) $(BIN2) $(BIN3) $(BIN4)
	@echo "finished make Output:\""$(BIN1) $(BIN2) $(BIN3) $(BIN4) $(BIN5)"\""


$(BIN1):$(OBJ1)
	$(CC) -o $@ $(OBJ1) $(INIEXSRC)

$(BIN2):$(OBJ2)
	$(CC) -o $@ $(OBJ2) $(LDFLAGS3)

$(BIN3):$(OBJ3)
	$(CC) -o $@ $@.o $(LDFLAGS1)

$(BIN4):$(OBJ4)
	$(CC) -o $@ $@.o $(JSONEXSRC) $(LDFLAGS2)

$(BIN5):$(OBJ5)
	$(CC) -o $@ $@.o 

clean:
	rm -rf $(BIN1) $(BIN2) $(BIN3) $(BIN4) $(BIN5)
	rm -rf *.o

