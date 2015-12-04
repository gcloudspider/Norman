
CXX = gcc
OBJS = global.o
.PHONY:all clean


all: global.c global.h DataStruct.h
	@echo "---enter utils---"
	$(CXX) -c $<
	@echo "---leave utils---"

clean:
	rm -rf *.o
