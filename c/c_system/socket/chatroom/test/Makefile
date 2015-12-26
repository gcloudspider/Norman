
CC:=gcc
CFLAGS:= -g -o 
CLIBS:=-pthread

SRC:=$(wildcard *.c)
OBJ:=${SRC:%.c=%.o}
BIN:=${SRC:%.c=%}

all:$(BIN)
%:%.c
	$(CC) $(CFLAGS) $@ $< $(CLIBS) $(CINCS)

.PHONY:clean

clean:
	@echo "deleting...."
	rm -rf *.o $(BIN)
