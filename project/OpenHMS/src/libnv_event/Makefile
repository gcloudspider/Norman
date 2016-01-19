
CC=g++
CFLAGS = -g -DDEBUG

SRCS=$(wildcard *cpp)
BIN_SRCS=$(shell grep "int main" -l *.cpp)
LIB_SRCS=$(patsubst $(BIN_SRCS),,$(SRCS))

LIBNAME=nv_event
SO_LIB=$(patsubst %,lib%.so,$(LIBNAME))

LIB_OBJS=$(patsubst %.cpp,%.o,$(LIB_SRCS))

all:$(SO_LIB)

$(SO_LIB):$(LIB_OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^

clean:
	rm -rf *.o $(SO_LIB) 
