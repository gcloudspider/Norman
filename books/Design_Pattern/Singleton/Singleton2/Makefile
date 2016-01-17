CXX=g++

CLFAGS=-g -o 

SRC=$(wildcard *.cpp)
OBJ=${SRC:%.cpp=%.o}

BIN=SingletonDemo

.PHONY:all clean

all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CLFAGS) $@ $(OBJ)

clean:
	rm -rf *.o $(BIN)
