CXX=g++

CLFAGS=-g -o 

SRC=$(wildcard *.cpp)
OBJ=${SRC:%.cpp=%.o}

BIN=nokia

.PHONY:all clean

all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CLFAGS) $@ $(OBJ)

clean:
	rm -rf *.o $(BIN)
