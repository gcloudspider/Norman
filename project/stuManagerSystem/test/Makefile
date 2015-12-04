CXX=gcc
BIN=filemanage
OBJS= filemanage.o ../src/DataManage/FileManage.o
.PHONY:all clean

all:filemanage.o $(BIN)
	echo "---filemanage----"

$(BIN):$(OBJS)
	$(CXX) $(OBJS) -o $@

filemanage.o:filemanage.c ../src/DataManage/FileManage.h ../src/utils/DataStruct.h ../src/DataManage/FileManage.c
	$(CXX) -c $<

clean:
	rm -rf *.o
	rm -rf $(BIN)
