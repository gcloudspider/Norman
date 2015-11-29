/*########################################################
##File Name: MainMenu.c
##Created Time:2015年11月29日 星期日 19时15分31秒
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
#include "../utils/DataConst.h"

void ShowMainMenu() {
    char ch;
    while(1) {
        system("clear");
        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 %s                 ##\n",LOGIN_SELECT_USER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s                   ##\n",LOGIN_SELECT_STUDENT);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s                   ##\n",LOGIN_SELECT_TEACHER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s                 ##\n",LOGIN_SELECT_ADMIN);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s                       ##\n",LOGOUT);
        printf("\t\t##################################################\n");

        printf("\n\n");
        printf("%s",SELECT_LOGIN_USER);
        
        ch=getchar();
        switch(ch) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                exit(0);
                break;
            default:
                break;
        }
    }
}
