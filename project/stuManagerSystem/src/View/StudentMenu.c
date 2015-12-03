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
#include<string.h>
#include "StudentMenu.h"
#include "../utils/DataConst.h"
#include "../utils/DataEnum.h"
#include "../utils/DataStruct.h"
#include "../Controller/LinklistController.h"

void showStuInfo(int userid) {
    char ch;
    STU* pn = NULL;
    pn = onSearchUserInfo(STUDENT,userid);
    
    if(pn == NULL) {
        printf("%s",QUERY_STUDENT_INFO_ERROR);
        return;
    }
    
    while(1) {
        system("clear");
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
        while((ch = getchar()) != '\n');

        printf("%s",INPUTY_RETURN_PARENT_FOLDER);
        ch=getchar();
        if(ch=='y'||ch=='Y') {
            break;
        }
    }
    return ;
}

void showScore(userid) {
    char ch;
    STU* pn = NULL;
    pn = onSearchUserInfo(STUDENT,userid);
    
    if(pn == NULL) {
        printf("%s",QUERY_STUDENT_SCORE_ERROR);
        return ;
    }
    while(1) {
        system("clear");
        printf("%s\t%s\t%s\t%s\t%s\t%s\n",
               SHOW_STUDENT_SCORE_MATH,
            SHOW_STUDENT_SCORE_ENGLISH,
            SHOW_STUDENT_SCORE_CLANG,
            SHOW_STUDENT_SCORE_JAVA,
            SHOW_STUDENT_SCORE_CADV,
            SHOW_STUDENT_TOTAL_SCORE
            );
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
            pn->math,
            pn->english,
            pn->c_lang,
            pn->java,
            pn->c_adv,
            pn->total
        );
        while((ch = getchar()) != '\n');

        printf("%s",INPUTY_RETURN_PARENT_FOLDER);
        ch=getchar();
        if(ch=='y'||ch=='Y') {
            break;
        }
    }
}

void modifyPasswd(int userid) {
    char newpasswd[32] = {0};
    char newpasswd2[32] = {0};
    char ch;
    STU* pn = NULL;
    pn = onSearchUserInfo(STUDENT,userid);
    
    if(pn == NULL) {
        printf("%s",QUERY_STUDENT_PASSWD_ERROR);
        return ;
    }
    while(1) {
        system("clear");

        printf("%s",INPUT_STUDENT_NEW_PASSWD);
        scanf("%s",newpasswd);
        while((ch=getchar())!= '\n');
        if(strcmp(newpasswd,pn->passwd)==0){
            printf("%s\n",INPUT_NEW_PASSWD_THE_SAME);
            sleep(3);
            continue;
        }

        printf("%s",INPUT_STUDENT_NEW_PASSWD_AGAIN);
        scanf("%s",newpasswd2);
        while((ch=getchar())!= '\n');
        if(strcmp(newpasswd2,newpasswd)!=0) {
            printf("%s\n",INPUT_NEW_PASSWD_NOTSAME);
            sleep(3);
            continue;
        } else {
            printf("%s\t%s\n",pn->passwd,newpasswd2);
            strcpy(pn->passwd,newpasswd2);
        }
    
        printf("%s",SAVE_STUDENT_PASSWD);
        ch = getchar();
        if(ch == 'y'||ch == 'Y'||ch == '\n'){
            //TODO:写入文件
            int ret;
            ret = onSaveLinkListToFile(STUDENT);
            if(ret == 0) {
                printf("%s\n",SAVE_FILE_SUCCESS);
                onReloadLinkList(STUDENT);
                sleep(3);
                break;
            } else {
                printf("%s",SAVE_FILE_FAILED);
                sleep(3);
                continue;
            }
        } else {
            break;
        }
    }
    return;
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
        printf("\t\t##                 2.%s               ##\n",MODIFY_STUDENT_PASSWD);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",QUERY_STUDENT_SCORE);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 5.%s                       ##\n",LOGOUT);
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        while((ch=getchar())!= '\n');
        printf("%s",SELECT_MENU_ELEMENT);
        ch = getchar();
        switch(ch) {
            case '1':
                showStuInfo(userid);
                break;
            case '2':
                modifyPasswd(userid);
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
