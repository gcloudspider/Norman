SUBDIRS= utils View Controller DataManage Model

CXX = gcc
BIN = UserInfoManageSystem
OBJS = UserInfoManageSystem.o ./View/MainMenu.o ./View/AdminMenu.o ./View/StudentMenu.o ./View/TeacherMenu.o ./Controller/AppController.o ./Controller/LinklistController.o ./Controller/LoginController.o ./Model/InitAppModel.o ./Model/LinkListModel.o ./Model/LoginModel.o ./DataManage/FileManage.o ./DataManage/LinkListManage.o ./utils/global.o ./Model/ReleaseAppModel.o 

.PHONY: all clean $(SUBDIRS)

all clean: UserInfoManageSystem.o $(BIN)
	@echo "---enter src---"
	cd utils && $(MAKE) $@
	cd View && $(MAKE) $@
	cd Controller && $(MAKE) $@
	cd Model && $(MAKE) $@
	cd DataManage && $(MAKE) $@
	@echo "---level src---"
	
$(BIN):$(OBJS)
	$(CXX) $(OBJS) -o $@

UserInfoManageSystem.o:UserInfoManageSystem.c ./utils/DataStruct.h ./utils/global.h ./View/MainMenu.h ./Controller/AppController.h
	@echo "----enter src UserInfoManageSystem----"
	$(CXX) -c $<
	@echo "----leave src UserInfoManageSystem----"

