CXX=g++

CLFAGS=-g -o 
CLFAGSS=-g -c -o
SRC=$(wildcard *.cpp)
OBJ=${SRC:%.cpp=%.o}

BIN=CacheDemo

.PHONY:all clean

all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CLFAGS) $@ $(OBJ)

%.o:%.cpp
	$(CXX) $(CLFAGSS) $@ $<

clean:
	rm -rf *.o $(BIN)
