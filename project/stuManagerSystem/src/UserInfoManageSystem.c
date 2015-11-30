/*########################################################
##File Name: UserInfoManageSystem.c
##Created Time:2015年11月29日 星期日 11时15分57秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include "./Model/InitAppModel.h"
#include "./View/MainMenu.h"
#include "./utils/DataStruct.h"
#include "./utils/global.h"

int main() {   
    InitAppModel();
    //printf("stu=%p\n",head_student);
    //printf("tea=%p\n",head_teacher);
    //printf("admin=%p\n",head_admin);
    ShowMainMenu();
    return 0;
}
