

CXX=g++

CFALGS=-g -o

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

BIN=factorymode

.PHONY:all clean


all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CFALGS) $@ $(OBJ)

clean:
	rm -rf *.o $(BIN)
