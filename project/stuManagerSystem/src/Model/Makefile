
CXX=gcc

.PHONY:all clean

all:InitAppModel.o LinkListModel.o LoginModel.o ReleaseAppModel.o
	@echo "----enter Model ----"

InitAppModel.o:InitAppModel.c InitAppModel.h ../DataManage/FileManage.h ../utils/DataStruct.h ../utils/global.h 
	@echo "----enter Model InitAppModel ----"
	$(CXX) -c $<
	@echo "----leave Model InitAppModel ----"

LinkListModel.o:LinkListModel.c LinkListModel.h ../DataManage/LinkListManage.h ../DataManage/FileManage.h ../utils/DataConst.h ../utils/global.h 
	@echo "----enter Model LinkListModel ----"
	$(CXX) -c $<
	@echo "----enter Model LinkListModel ----"
	

LoginModel.o:LoginModel.c LoginModel.h ../utils/global.h ../utils/DataStruct.h ../utils/DataConst.h ../DataManage/LinkListManage.h 
	@echo "----enter Model LoginModel ----"
	$(CXX) -c $<
	@echo "----enter Model LoginModel ----"

ReleaseAppModel.o:ReleaseAppModel.c ReleaseAppModel.h  ../DataManage/LinkListManage.h ../DataManage/FileManage.h ../utils/DataStruct.h ../utils/global.h 
	@echo "----enter Model ReleaseModel ----"
	$(CXX) -c $<
	@echo "----enter Model ReleaseModel ----"

clean:
	rm -rf *.o
	rm -rf *.gch
