CXX= gcc

.PHONY:all clean

all:MainMenu.o StudentMenu.o TeacherMenu.o AdminMenu.o
	@echo "----leave View----"

MainMenu.o:MainMenu.c MainMenu.h StudentMenu.h TeacherMenu.h AdminMenu.h ../utils/DataConst.h ../utils/DataEnum.h ../Controller/AppController.h ../Controller/LoginController.h 
	@echo "----enter View MainMenu----"
	$(CXX) -c $<
	@echo "----leave View MainMenu----"

StudentMenu.o:StudentMenu.h ../utils/DataConst.h ../utils/DataEnum.h ../utils/DataStruct.h ../Controller/LinklistController.h
	@echo "----enter View StudentMenu----"
	$(CXX) -c $<
	@echo "----leave View StudentMenu----"

TeacherMenu.o:TeacherMenu.h ../utils/DataConst.h ../utils/DataEnum.h ../utils/DataStruct.h ../utils/global.h ../Controller/LinklistController.h 
	@echo "----enter View TeacherMenu----"
	$(CXX) -c $<
	@echo "----leave View TeacherMenu----"

AdminMenu.o:AdminMenu.h ../utils/DataConst.h ../utils/DataEnum.h ../utils/global.h ../Controller/LinklistController.h
	@echo "----enter View AdminMenu----"
	$(CXX) -c $<
	@echo "----leave View AdminMenu----"


clean:
	rm -rf *.o
	rm -rf *.gch

