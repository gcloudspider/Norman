CXX=g++

CFALGS=-g -o

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

BIN=SimplefactorypatternDemo

.PHONY:all clean


all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CFALGS) $@ $(OBJ)

clean:
	rm -rf *.o $(BIN)
