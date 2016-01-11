CXX=g++

CFALGS=-g -o

SRC=factory.cpp io.cpp logic.cpp main.cpp
OBJ=$(SRC:%.cpp=%.o)

BIN=CalDemo

.PHONY:all clean


all:$(BIN)

$(BIN):$(OBJ)
	$(CXX) $(CFALGS) $@ $(OBJ)

clean:
	rm -rf *.o $(BIN)
