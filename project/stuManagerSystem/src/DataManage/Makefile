CXX = gcc

.PHONY:all clean

all:FileManage.o LinkListManage.o
	echo "----enter DataManage ----"

FileManage.o:FileManage.c FileManage.h ../utils/DataConst.h
	@echo "----enter DataManage FileManage----"
	$(CXX) -c $<
	@echo "----leave DataManage FileManage----"

LinkListManage.o:LinkListManage.c LinkListManage.h ../utils/DataStruct.h 
	@echo "----enter DataManage LinkListManage----"
	$(CXX) -c $<
	@echo "----leave DataManage LinkListManage----"


clean:
	rm -rf *.o
	rm -rf *.gch
