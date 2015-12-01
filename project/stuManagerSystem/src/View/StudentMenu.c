/*########################################################
##File Name: StudentMenu.c
##Created Time:2015年11月30日 星期一 19时52分54秒
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
#include<stdlib.h>
#include "StudentMenu.h"
#include "../utils/DataConst.h"
#include "../utils/DataEnum.h"
#include "../utils/DataStruct.h"
#include "../Controller/LinklistController.h"

void showInfo(int userid) {
    STU* pn = NULL;
    printf("%p\n",pn);
    onSearchUserInfo(STUDENT,userid,pn);
    printf("%p\n",pn);
    sleep(5);
}

void ShowStudentMenu(int userid) {
    char ch;

    while(1) {
        system("clear");
        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",SHOW_STUDENT_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",MODIFY_STUDENT_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",QUERY_STUDENT_SCORE);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 5.%s                       ##\n",LOGOUT);
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();
        switch(ch) {
            case '1':
                showInfo(userid);
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                return;
                break;
            case '5':
                ReleaseAppController();
                exit(0);
                break;
            default:
                break;
        }
    }
}
