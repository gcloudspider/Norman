
CXX=g++
CLAFAGS=-g -o

SRC=$(wildcard *.cpp)
BIN=SimpleDemo

OBJ=${SRC:%.cpp=%.o}

.PHONY:all clean

all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CLAFAGS) $@ $(OBJ)

clean:
	rm -rf *.o $(BIN)
