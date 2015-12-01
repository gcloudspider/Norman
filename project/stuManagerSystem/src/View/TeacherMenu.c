/*########################################################
##File Name: TeacherMenu.c
##Created Time:2015年11月30日 星期一 19时58分07秒
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
#include "TeacherMenu.h"
#include "../utils/DataConst.h"

void ShowTeacherMenu() {
    char ch;

    while(1) {
        system("clear");
        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",SHOW_TEACHER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",MODIFY_STUDENT_SCORE);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s                 ##\n",SEARCH_STUDENT_NUM);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s                 ##\n",SEARCH_STUDENT_NAME);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 5.%s                 ##\n",SEARCH_STUDENT_CLASSID);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 6.%s                 ##\n",SEARCH_STUDENT_SCORE);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 7.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 8.%s                       ##\n",LOGOUT);
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();
        switch(ch) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                return;
                break;
            case '8':
                ReleaseAppController();
                exit(0);
                break;
            default:
                break;
        }
    }   
}
