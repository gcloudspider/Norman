
CXX= gcc

.PHONY:all clean

all:AppController.o LinkListController.o LoginController.o
	@echo "----enter Controller----"

AppController.o:AppController.c AppController.h ../Model/InitAppModel.h ../Model/ReleaseAppModel.h 
	@echo "----enter Controller AppController----"
	$(CXX) -c $<
	@echo "----leave Controller AppController----"

LinkListController.o:LinklistController.c LinklistController.h ../utils/DataEnum.h ../Model/LinkListModel.h ../utils/global.h  
	@echo "----enter Controller LinkListController----"
	$(CXX) -c $<
	@echo "----leave Controller LinkListController----"

LoginController.o:LoginController.c LoginController.h ../utils/DataEnum.h ../Model/LoginModel.h 
	@echo "----enter Controller LoginModel----"
	$(CXX) -c $<
	@echo "----leave Controller LoginModel----"

clean:
	rm -rf *.o
	rm -rf *.gch
