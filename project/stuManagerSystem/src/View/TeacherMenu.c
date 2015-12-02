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
#include "../utils/DataStruct.h"
#include "../utils/DataEnum.h"
#include "../Controller/LinklistController.h"

void showTeaInfo(int userid) {
    char ch;
    TEA* pn = NULL;
    pn = onSearchUserInfo(TEACHER,userid);
    
    if(pn == NULL) {
        printf("%s",QUERY_STUDENT_INFO_ERROR);
        return;
    }

    while(1) {
        system("clear");
        printf("%s\t%s\t%s\t%s\t%s\t%s\n",
            SHOW_TEACHER_NUM,
            SHOW_TEACHER_NAME,
            SHOW_TEACHER_AGE,
            SHOW_TEACHER_SEX,
            SHOW_TEACHER_CLASSNO,
            SHOW_TEACHER_LESSION
            );
        printf("%d\t%s\t%d\t%d\t%d\t%d\n",
            pn->id,
            pn->name,
            pn->age,
            pn->sex,
            pn->class_no,
            pn->lession
            );
        while((ch = getchar()) != '\n');

        printf("%s",INPUTY_RETURN_PARENT_FOLDER);
        ch=getchar();
        if(ch=='y'||ch=='Y') {
            break;
        }
    }
    return ;
}

void modifyStuScore() {
    char ch;
    int math,eng,clang,java,cadv;
    STU* pn = NULL;
    int userid;
    printf("%s",SEARCH_STU_FROM_ID);
    scanf("%d",&userid);
    pn = onSearchUserInfo(STUDENT,userid);
    
    if(pn == NULL) {
        printf("%s\n",QUERY_STUDENT_INFO_ERROR);
        sleep(3);
        return;
    } else {
        printf("%s\n",SEARCH_STU_SCORE);
        printf("1.%s\t%d\n",SHOW_STUDENT_SCORE_MATH,pn->math);
        printf("2.%s\t%d\n",SHOW_STUDENT_SCORE_ENGLISH,pn->english);
        printf("3.%s\t%d\n",SHOW_STUDENT_SCORE_CLANG,pn->c_lang);
        printf("4.%s\t%d\n",SHOW_STUDENT_SCORE_JAVA,pn->java);
        printf("5.%s\t%d\n",SHOW_STUDENT_SCORE_CADV,pn->c_adv);

        printf("%s\n",SELECT_MODIFY_STU_LESSION);
        scanf("%d%d%d%d%d",&math,&eng,&clang,&java,&cadv);
        pn->math = math;
        pn->english = eng;
        pn->c_lang = clang;
        pn->java = java;
        pn->c_adv = cadv;
        printf("%s\n",SEARCH_STU_AFTER_SCORE);
        printf("1.%s\t%d\n",SHOW_STUDENT_SCORE_MATH,pn->math);
        printf("2.%s\t%d\n",SHOW_STUDENT_SCORE_ENGLISH,pn->english);
        printf("3.%s\t%d\n",SHOW_STUDENT_SCORE_CLANG,pn->c_lang);
        printf("4.%s\t%d\n",SHOW_STUDENT_SCORE_JAVA,pn->java);
        printf("5.%s\t%d\n",SHOW_STUDENT_SCORE_CADV,pn->c_adv);
    }
    while((ch=getchar())!='\n');
    printf("%s",SAVE_STUDENT_SCORE);
    
    ch = getchar();
    if(ch == 'y' || ch == 'Y'||ch == '\n') {
        int ret;
        ret = onSaveLinkListToFile(STUDENT);
        if(ret == 0) {
            printf("%s\n",SAVE_FILE_SUCCESS);
            onReloadLinkList(STUDENT);
            sleep(3);
            return;
        } else {
            printf("%s",SAVE_FILE_FAILED);
            sleep(3);
            return;
        }
    } else {
        return;
    }
}

void showScorebyID() {
    STU* pn;
    pn = onSearchScoreSort(ID); 
}

void showScorebyName() {

}

void showScorebyClassid() {

}

void showScoreByCount() {

}

void ShowTeacherMenu(int userid) {
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
        printf("\t\t##                 3.%s             ##\n",SEARCH_STUDENT_NUM);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s             ##\n",SEARCH_STUDENT_NAME);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 5.%s             ##\n",SEARCH_STUDENT_CLASSID);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 6.%s           ##\n",SEARCH_STUDENT_SCORE);
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
                showTeaInfo(userid);
                break;
            case '2':
                modifyStuScore();
                break;
            case '3':
                showScorebyID();
                break;
            case '4':
                showScorebyName();
                break;
            case '5':
                showScorebyClassid();
                break;
            case '6':
                showScoreByCount();
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
