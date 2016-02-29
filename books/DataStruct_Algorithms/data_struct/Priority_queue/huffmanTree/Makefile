CXX=g++

CLFAGS=-g -o 
CINCS=-std=c++1y

SRC=$(wildcard *.cpp)
OBJ=${SRC:%.cpp=%.o}

BIN=$(shell pwd|xargs basename)

.PHONY:all clean

all:$(BIN) 

$(BIN):$(OBJ)
	$(CXX) $(CLFAGS) $@ $(OBJ) $(CINCS)

#%.o:%.cpp
#	$(CXX) $(CLFAGS) $@ $< $(CINCS)

clean:
	rm -rf *.o $(BIN)
