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
void AddStudentNode(STU** head) {
    char ch;
    STU* pn,*p;
    printf("%s\n",ADD_STUDENTNODE_INFO);

    while(1) {
        pn = malloc(sizeof(STU));
        if(pn == NULL) {
            printf("malloc error!\n");
            return ;
        }

        scanf("%d%s%d%d%s%s%s%d%d%d%d%d%d%d",
            &pn->id,
            pn->name,
            &pn->age,
            &pn->sex,
            pn->telnum,
            pn->QQ,
            pn->passwd,
            &pn->classid,
            &pn->math,
            &pn->english,
            &pn->c_lang,
            &pn->java,
            &pn->c_adv,
            &pn->total
            );
        while((ch=getchar())!='\n');
        
        if(*head) {
            pn->next = NULL;
            pn->pre=p;
            p->next = pn;
        } else {
            pn->next = *head;
            pn->pre = *head;
            *head = pn;
        }
        p = pn;
        printf("%s",INPUT_INFO_CONTINUE);
clear_enter:
        ch =getchar();
        if(ch == 'n'||ch == 'N') {
            break;
        } else if(ch == 'y'|| ch == 'Y' || ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }
    }

    printf("%p\n",*head);
    return ;
}

void AddTeacherNode(TEA** head) {
    char ch;
    TEA* pn,*p;
    printf("%s\n",ADD_TEACHERNODE_INFO);
    
    while(1) {
        pn = malloc(sizeof(TEA));
        if(pn == NULL) {
            printf("malloc error!\n");
            return ;
        }

        scanf("%d%s%d%d%d%d%s",
            &pn->id,
            pn->name,
            &pn->age,
            &pn->sex,
            &pn->class_no,
            &pn->lession,
            pn->passwd
            );
        while((ch=getchar())!='\n');
        
        if(*head) {
            pn->next = NULL;
            pn->pre=p;
            p->next = pn;
        } else {
            pn->next = *head;
            pn->pre = *head;
            *head = pn;
        }
        p = pn;
        printf("%s",INPUT_INFO_CONTINUE);
clear_enter:
        ch =getchar();
        if(ch == 'n'||ch == 'N') {
            break;
        } else if(ch == 'y'|| ch == 'Y' || ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }
    }

    return;
}

void AddAdminNode(ADMIN** head) {
    char ch;
    ADMIN* pn,*p;
    printf("%s\n",ADD_ADMINNODE_INFO);

    while(1) {
        pn = malloc(sizeof(ADMIN));
        if(pn == NULL) {
            printf("malloc error!\n");
            return ;
        }

        scanf("%d%s%d%d%s",
             &pn->id,
             pn->name,
             &pn->age,
             &pn->sex,
              pn->passwd
             );
        while((ch=getchar())!='\n');
        
        if(*head) {
            pn->next = NULL;
            pn->pre=p;
            p->next = pn;
        } else {
            pn->next = *head;
            pn->pre = *head;
            *head = pn;
        }
        p = pn;
        printf("%s",INPUT_INFO_CONTINUE);
clear_enter:
        ch =getchar();
        if(ch == 'n'||ch == 'N') {
            break;
        } else if(ch == 'y'|| ch == 'Y' || ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }
    }
    return;
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
                STU* pn=NULL ;
                AddStudentNode(&pn);
                printf("%p\n",&pn);
                ret = AddUserNodeToLinkList(STUDENT,pn);
                if(ret == 0) {
                    printf("success");
                    sleep(5);
                }
                break;
            }
            case '2': {
                TEA* pn=NULL;
                AddTeacherNode(&pn);
                ret = AddUserNodeToLinkList(TEACHER,pn);
                if(ret == 0) {
                    
                }
                break;
            }
            case '3': {
                ADMIN* pn=NULL;
                AddAdminNode(&pn);
                printf("%p\n",&pn);
                ret = AddUserNodeToLinkList(ADMINISTRATOR,pn);
                if(ret == 0) {
                    printf("sss\n");
                    sleep(5);
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
