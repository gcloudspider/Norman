CXX=g++

CFALGS=-g -o

SRC=SimpleFactory.cpp
SRC1=factory.cpp io.cpp logic.cpp main.cpp
OBJ=$(SRC:%.cpp=%.o)
OBJ1=$(SRC1:%.cpp=%.o)

BIN=SimplefactorypatternDemo 
BIN1=CalDemo

.PHONY:all clean


all:$(BIN) $(BIN1)

$(BIN):$(OBJ)
	$(CXX) $(CFALGS) $@ $(OBJ)

$(BIN1):$(OBJ1)
	$(CXX) $(CFALGS) $@ $(OBJ1)

clean:
	rm -rf *.o $(BIN) $(BIN1)
