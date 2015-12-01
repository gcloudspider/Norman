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
    char ch;
    STU* pn = NULL;
    pn = onSearchUserInfo(STUDENT,userid);
    
    if(pn == NULL) {
        printf("%s",QUERY_STUDENT_INFO_ERROR);
        return;
    }

    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
           SHOW_STUDENT_NUM,
           SHOW_STUDENT_NAME,
           SHOW_STUDENT_AGE,
           SHOW_STUDENT_SEX,
           SHOW_STUDENT_TELNUM,
           SHOW_STUDENT_QQ,
           SHOW_STUDENT_CLASSID
          );
    printf("%d\t%s\t%d\t%d\t%s\t%s\t%d\n",
           pn->id,
           pn->name,
           pn->age,
           pn->sex,
           pn->telnum,
           pn->QQ,
           pn->classid);
}

void showScore(userid) {
    char ch;
    STU* pn = NULL;
    pn = onSearchUserInfo(STUDENT,userid);
    
    if(pn == NULL) {
        printf("%s",QUERY_STUDENT_SCORE_ERROR);
        return ;
    }

    printf("%s\t%s\t%s\t%s\t%s\n",
           SHOW_STUDENT_SCORE_MATH,
           SHOW_STUDENT_SCORE_ENGLISH,
           SHOW_STUDENT_SCORE_CLANG,
           SHOW_STUDENT_SCORE_JAVA,
           SHOW_STUDENT_SCORE_CADV
          );
    printf("%d\t%d\t%d\t%d\t%d\n",
           pn->math,
           pn->english,
           pn->c_lang,
           pn->java,
           pn->c_adv
          );
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
                showScore(userid);
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
