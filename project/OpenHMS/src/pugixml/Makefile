
#展开成一列所有符合由其参数描述的文件名,文件空格间隔
SRCS=$(wildcard *.cpp)	
PROTOCS=$(wildcard *.proto)
PROTO_SRCS=$(PROTOCS:.proto=.pb.cc)
BIN_SRCS=$(shell grep "int main" -l *.cpp)
LIB_SRCS=$(patsubst $(BIN_SRCS),,$(SRCS))     #匹配替换

DEPS=$(SRCS:.cpp=.d) 
OBJS=$(SRCS:.cpp=.o) $(PROTO_SRCS:.cc=.o)

LIB_OBJS=$(patsubst %.cpp,%.o,$(LIB_SRCS))  $(PROTO_SRCS:.cc=.o)
BINS=$(patsubst %.cpp,%,$(BIN_SRCS))

LIB_NAME=pugixml
SO_LIB=$(patsubst %,lib%.so,$(LIB_NAME))   #生成动态链接库
STATIC_LIB=$(patsubst %,lib%.a,$(LIB_NAME)) #生成静态库


CC=g++
CFLAGS= -Wall -D_REENTRANT -D_GNU_SOURCE -fPIC
BOOST_DIR = /usr/local/include/boost/
THRIFT_DIR = /usr/local/include/thrift
#INC= -I${THRIFT_DIR} -I${BOOST_DIR}  -I. -I../public 
INC= -I. -I../framework 

#判断是Release版本还是Debug版本
ifeq ($(release), 1)
CFLAGS += -O2 -DNDEBUG 
else
CFLAGS += -g -DDEBUG 
endif

all: $(BINS) $(SO_LIB) $(STATIC_LIB) 

$(BINS): % : %.o $(LIB_OBJS) 
	$(CC) $(CFLAGS) -o $@ $^  
$(SO_LIB): $(LIB_OBJS) 
	$(CC) $(CFLAGS) -shared -o $@ $^ 
$(STATIC_LIB): $(LIB_OBJS) 
	ar -rcs -o $@ $^ 
dist :
	rm -f $(DEPS) *.o
clean:
	rm -f $(BINS) $(OBJS) $(DEPS) $(SO_LIB) $(STATIC_LIB)
release: clean
	@make release=1

%.d : %.cpp
	$(CC) $(CFLAGS) -MT $(subst .cpp,.o,$<) -MM $(INC)  $< >$@
%.o : %.cpp
	$(CC) $(CFLAGS) $(INC) -c  $< 

-include  $(DEPS)

