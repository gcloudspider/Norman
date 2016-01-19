CXX=g++

CFLAGS=-g -o
SRCS=$(wildcard *.cpp)

LIB_SRCS=$(shell grep "IMPLEMENT_MAIN" -l *.cpp)
LIB_OBJS=$(patsubst %.cpp,%.o,$(LIB_SRCS))
BINS=OpenHms

#1.first setp
DEPS=$(SRC:.cpp=.d)
INC= -I. -I../libnv_event -I..

.PHONY:all clean

all:$(BINS) $(STATIC_LIB)


$(BINS):$(LIB_OBJS) $(DEP_LIBS)
	$(CXX) $(CFLAGS) $@ $^

%.d : %.cpp
	$(CC) $(CFLAGS) -MT $(subst .cpp,.o,$<) -MM $(INC) $< >$@


clean:
	rm -rf *.o $(BINS)

-include $(DEPS)
