CC:=gcc

CFLAGS:=-g -o
CINCS:=-I /usr/include/lua5.1/
CLIBS:=-llua
SRC:=$(wildcard *.c)

OBJ:=${SRC:%.c=%.o}

BIN:=${SRC:%.c=%}

.PHONY:all clean
all:$(BIN)

%:%.c
	$(CC) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

clean:
	rm -rf *.o $(BIN)
