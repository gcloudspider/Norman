CC = gcc

LDFLAGS1= -lmysqlclient
LDFLAGS2= -lm -I.
LDFLAGS3= -lzlog
LDFLAGS4= -luuid

BIN1 = test_iniparser
BIN2 = test_zlog
BIN3 = $(SRC3:%.c=%)
BIN4 = $(SRC4:%.c=%) 
BIN5 = test_daemon
BIN6 = test_uuid_generate
BIN7 = test_genreqId
BIN8 = test_uuid_custom


INIEXSRC= ../src/dictionary.c ../src/iniparser.c 
LOGEXSRC=  
JSONEXSRC= ../src/cjson.c

SRC1= test_iniparser.c
SRC2= test_zlog.c
SRC3= $(wildcard *database*.c)
SRC4= $(wildcard *json*.c)
SRC5= test_daemon.c
SRC6= test_uuid_generate.c
SRC7= test_genreqId.c
SRC8= test_uuid_custom.c

OBJ1 = $(SRC1:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)
OBJ3 = $(SRC3:%.c=%.o)
OBJ4 = $(SRC4:%.c=%.o)
OBJ5 = $(SRC5:%.c=%.o)
OBJ6 = $(SRC6:%.c=%.o)
OBJ7 = $(SRC7:%.c=%.o)
OBJ8 = $(SRC8:%.c=%.o)

.PHONY:all clean

all:$(BIN1) $(BIN2) $(BIN3) $(BIN4) $(BIN5) $(BIN6) $(BIN7) $(BIN8)
	@echo "finished make Output:\""$(BIN1) $(BIN2) $(BIN3) $(BIN4) $(BIN5) $(BIN6) $(BIN7) $(BIN8)"\""


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

$(BIN6):$(OBJ6)
	$(CC) -o $@ $(OBJ6) $(LDFLAGS4)

$(BIN7):$(OBJ7)
	$(CC) -o $@ $(OBJ7)

$(BIN8):$(OBJ8)
	$(CC) -o $@ $(OBJ8)

clean:
	rm -rf $(BIN1) $(BIN2) $(BIN3) $(BIN4) $(BIN5) $(BIN6) $(BIN7) $(BIN8)
	rm -rf *.o

