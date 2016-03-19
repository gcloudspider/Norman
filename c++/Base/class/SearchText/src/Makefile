DIR_INC = ../include
DIR_SRC = ./
DIR_OBJ = ../obj
DIR_BIN = ../bin

SRC = $(wildcard $(DIR_SRC)*.cpp)
OBJ = $(patsubst %.cpp,$(DIR_OBJ)/%.o,$(notdir ${SRC}))

TARGET= searchText

BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = g++
CINCS=-std=c++1y

CFLAGS = -g -Wall -I${DIR_INC}

${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ) -o $@
${DIR_OBJ}/%.o::${DIR_SRC}/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@  $(CINCS)

.PHONY:clean

clean:
	rm -rf ${DIR_OBJ}/*.o
	rm -rf ${BIN_TARGET}

