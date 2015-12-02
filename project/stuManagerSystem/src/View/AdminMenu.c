/*########################################################
##File Name: AdminMenu.c
##Created Time:2015年11月30日 星期一 19时58分22秒
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
#include <stdlib.h>
#include "AdminMenu.h"
#include "../utils/DataConst.h"
#include "../utils/DataEnum.h"
#include "../utils/DataStruct.h"
#include "../Controller/LinklistController.h"
STU* AddStudentNode() {
    STU* stu = NULL;
    stu = malloc(sizeof(STU));
    if(stu == NULL) {
        printf("malloc error!\n");
        return NULL;
    }
    printf("%s\n",ADD_STUDENTNODE_INFO);

    scanf("%d\t%s\t%d\t%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
        &stu->id,
        stu->name,
        &stu->age,
        &stu->sex,
        stu->telnum,
        stu->QQ,
        stu->passwd,
        &stu->classid,
        &stu->math,
        &stu->english,
        &stu->c_lang,
        &stu->java,
        &stu->c_adv
         );

    stu->pre = NULL;
    stu->next = NULL;

    printf("%p\n",stu);
    return stu;
}

TEA* AddTeacherNode() {
    TEA* tea = NULL;
    tea = malloc(sizeof(TEA));
    if(tea == NULL) {
        printf("malloc error!\n");
        return NULL;
    }
    printf("%s\n",ADD_TEACHERNODE_INFO);

    scanf("%d\t%s\t%d\t%d\t%d\t%d\t%s\n",
        &tea->id,
        tea->name,
        &tea->age,
        &tea->sex,
        &tea->class_no,
        &tea->lession,
        tea->passwd
        );

    tea->pre = NULL;
    tea->next = NULL;

    printf("%p\n",tea);
    return tea;
}

ADMIN* AddAdminNode() {
    ADMIN* admin = NULL;
    admin = malloc(sizeof(ADMIN));
    if(admin == NULL) {
        printf("malloc error!\n");
        return NULL;
    }
    printf("%s\n",ADD_ADMINNODE_INFO);

    scanf("%d\t%s\t%d\t%d\t%s\n",
        &admin->id,
        admin->name,
        &admin->age,
        &admin->sex,
        admin->passwd
        );

    admin->pre = NULL;
    admin->next = NULL;

    printf("%p\n",admin);
    return admin;
}

void AddUserInfo() {
    char ch;
    int ret;
    while(1) {
        system("clear");

        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",ADD_STUDENT_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",ADD_TEACHER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",ADD_ADMIN_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();

        switch(ch) {
            case '1':{
                STU* pn ;
                pn = AddStudentNode();
                ret = AddUserNodeToLinkList(STUDENT,pn);
                if(ret == 0) {
                    printf("success");
                    sleep(5);
                }
                break;
            }
            case '2': {
                TEA* pn;
                pn = AddTeacherNode();
                ret = AddUserNodeToLinkList(TEACHER,pn);
                if(ret == 0) {
                    
                }
                break;
            }
            case '3': {
                ADMIN* pn;
                pn = AddAdminNode();
                ret = AddUserNodeToLinkList(ADMINISTRATOR,pn);
                if(ret == 0) {
                    
                }
                break;
            }
            case '4':
                return;
                break;
            default:
                break;
        }       
    }
}



void ModifyUserInfo() {
    //TODO:修改用户信息
    char ch;
    while(1) {
        system("clear");

        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",MODIFY_STUDENT_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",MODIFY_TEACHER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
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
                return;
                break;
            default:
                break;
        }
    }
}

void DelUserInfo() {
    //TODO:删除用户信息
    char ch;
    while(1) {
        system("clear");

        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",DEL_STUDENT_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",DEL_TEACHER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
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
                return;
                break;
            default:
                break;
        }
    }   
}

void SearchUserInfo() {
    //TODO:搜索用户信息
    char ch;
    while(1) {
        system("clear");

        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",SEARCH_STUDENT_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",SEARCH_TEACHER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
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
                return;
                break;
            default:
                break;
        }
    }   
}

void SearchScore() {
    //TODO:搜索成绩
    char ch;
    while(1) {
        system("clear");

        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",MODIFY_STUDENT_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",MODIFY_TEACHER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
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
                return;
                break;
            default:
                break;
        }
    }   
}

void ShowAdminMenu() {
    char ch;

    while(1) {
        system("clear");
        printf("\t\t##################################################\n");
        printf("\t\t##              %s            ##\n",MAIN_MENU_WELCOME_TITLE);
        printf("\t\t##################################################\n");
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 1.%s               ##\n",ADD_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 2.%s               ##\n",MODIFY_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 3.%s               ##\n",DEL_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",SEARCH_USER_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 5.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 6.%s                       ##\n",LOGOUT);
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();
        switch(ch) {
            case '1':
                AddUserInfo();
                break;
            case '2':
                ModifyUserInfo();
                break;
            case '3':
                DelUserInfo();
                break;
            case '4':
                SearchUserInfo();
                break;
            case '5':
                return;
                break;
            case '6':
                ReleaseAppController();
                exit(0);
                break;
            default:
                break;
        }
    }   
}
