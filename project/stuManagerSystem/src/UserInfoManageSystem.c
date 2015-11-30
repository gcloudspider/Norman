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
#include "./utils/DataStruct.h"
#include "./utils/global.h"
#include "./View/MainMenu.h"
#include "./Controller/AppController.h"

int main() {   
    InitAppController();
    //printf("stu=%p\n",g_pstudent);
    //printf("tea=%p\n",g_pteacher);
    //printf("admin=%p\n",g_padmin);
    ShowMainMenu();
    return 0;
}
