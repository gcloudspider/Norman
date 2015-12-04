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
#include "StudentMenu.h"
#include "TeacherMenu.h"
#include "AdminMenu.h"
#include "../utils/DataConst.h"
#include "../utils/DataEnum.h"
#include "../Controller/AppController.h"
#include "../Controller/LoginController.h"


void ShowLoginMenu(int logintype) {
    int userid;
    char passwd[32] = {0};
    size_t ret,result;

    system("clear");
    switch(logintype) {
        case STUDENT: {
            printf("%s",PLEASE_INPUT_STUDENT_ID);
            scanf("%d",&userid);
            ret = onLoginAuthUserId(STUDENT,userid);
            if(ret == 0) {
                printf("%s",PLEASE_INPUT_STUDENT_PASSWD);
                scanf("%s",passwd);
                result = onLoginAuthPasswd(STUDENT,userid,passwd);
                if(result == 0) {
                    printf("%s\n",LOGIN_SUCCESS_INFO);
                    sleep(1);
                    ShowStudentMenu(userid);
                } else {
                    printf("%s\n",AUTH_PASSWD_FAILED_INFO);
                    sleep(3);
                }
            } else {
                printf("%s\n",AUTH_USERID_FAILED_INFO);
                sleep(3);
            }
            break;
        }
        case TEACHER: {
            printf("%s",PLEASE_INPUT_TEACHER_ID);
            scanf("%d",&userid);
            ret = onLoginAuthUserId(TEACHER,userid);
            if(ret == 0) {
                printf("%s",PLEASE_INPUT_TEACHER_PASSWD);
                scanf("%s",passwd);
                result = onLoginAuthPasswd(TEACHER,userid,passwd);
                if(result == 0) {
                    printf("%s\n",LOGIN_SUCCESS_INFO);
                    sleep(1);
                    ShowTeacherMenu(userid);
                } else {
                    printf("%s\n",AUTH_PASSWD_FAILED_INFO);
                    sleep(3);  
                }
            } else {
                printf("%s\n",AUTH_USERID_FAILED_INFO);   
                sleep(3);
            }
            break;
        }
        case ADMINISTRATOR: {
            printf("%s",PLEASE_INPUT_ADMIN_ID);
            scanf("%d",&userid);
            ret = onLoginAuthUserId(ADMINISTRATOR,userid);
            if(ret == 0) {
                printf("%s",PLEASE_INPUT_ADMIN_PASSWD);
                scanf("%s",passwd);
                result = onLoginAuthPasswd(ADMINISTRATOR,userid,passwd);
                if(result == 0) {
                    printf("%s\n",LOGIN_SUCCESS_INFO);
                    sleep(1);
                    ShowAdminMenu(userid);
                } else {
                    printf("%s\n",AUTH_PASSWD_FAILED_INFO);
                    sleep(3);
                }   
            } else {
                printf("%s\n",AUTH_USERID_FAILED_INFO);   
                sleep(3);
            }
            break;
        }
        default:
            break;   
    }
    return;
}

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

        printf("\n");
        printf("%s",SELECT_LOGIN_USER);
        
        while((ch=getchar())!= '\n');
        ch=getchar();

        switch(ch) {
            case '1':
                ShowLoginMenu(STUDENT);
                break;
            case '2':
                ShowLoginMenu(TEACHER);
                break;
            case '3':
                ShowLoginMenu(ADMINISTRATOR);
                break;
            case '4':
                ReleaseAppController();
                exit(0);
                break;
            default:
                break;
        }
    }
}
