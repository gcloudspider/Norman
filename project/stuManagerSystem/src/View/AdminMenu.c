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
#include <string.h>
#include "AdminMenu.h"
#include "../utils/DataConst.h"
#include "../utils/DataEnum.h"
#include "../Controller/LinklistController.h"
#include "../utils/global.h"

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
        printf("\t\t##                 3.%s             ##\n",ADD_ADMIN_INFOMATION);
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
                    while((ch=getchar())!='\n');
                    printf("%s",SAVE_NEWSTUDENT_TOFILE);
                    ch = getchar();
                    if(ch == 'y' || ch == 'Y') {
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
                break;
            }
            case '2': {
                TEA* pn=NULL;
                AddTeacherNode(&pn);
                ret = AddUserNodeToLinkList(TEACHER,pn);
                if(ret == 0) {
                    while((ch=getchar())!='\n');
                    printf("%s",SAVE_NEWTEACHER_TOFILE);   
                    ch = getchar();
                    if(ch == 'y' || ch == 'Y') {
                        ret = onSaveLinkListToFile(TEACHER);
                        if(ret == 0) {
                            printf("%s\n",SAVE_FILE_SUCCESS);
                            onReloadLinkList(TEACHER);
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
                break;
            }
            case '3': {
                ADMIN* pn=NULL;
                AddAdminNode(&pn);
                ret = AddUserNodeToLinkList(ADMINISTRATOR,pn);
                if(ret == 0) {
                    while((ch=getchar())!= '\n');
                    printf("%s",SAVE_NEWADMIN_TOFILE);   
                    ch = getchar();
                    if(ch == 'y' || ch == 'Y') {
                        ret = onSaveLinkListToFile(ADMINISTRATOR);
                        if(ret == 0) {
                            printf("%s\n",SAVE_FILE_SUCCESS);
                            onReloadLinkList(ADMINISTRATOR);
                            sleep(3);
                            return;
                        } else {
                            printf("%s\n",SAVE_FILE_FAILED);
                            sleep(3);
                            return;
                        }
                    } else {
                        return;
                    }
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


void modifyStudentInfo() {
    char ch;
    int ret;
    int userid;
    STU* pn;
    char name[64] = {0};
    char telnum[11] = {0};
    char QQ[11] = {0};
    char passwd[32] = {0};
    int id,age,sex,classid;

    system("clear");
    printf("%s\n",SEARCH_STUDENT_INFO);
    PrintStudentInfo(&g_pstudent);

    printf("%s",INPUT_MODIFY_STUDENT_ID);
    scanf("%d",&userid);
    pn = onSearchUserInfo(STUDENT,userid);
    if(pn == NULL) {
        printf("%s\n",QUERY_STUDENT_INFO_ERROR);
        sleep(3);
        return;
    } else {
        printf("%s\n",MODIFY_STUDENT_INFO);
        scanf("%d%s%d%d%s%s%d%s",
            &id,name,&age,&sex,telnum,QQ,&classid,passwd);
        pn->id = id;
        pn->age = age;
        pn->sex = sex;
        pn->classid = classid;
        strcpy(pn->name,name);
        strcpy(pn->telnum,telnum);
        strcpy(pn->QQ,QQ);
        strcpy(pn->passwd,passwd);
        
        printf("%s",INFO_MODIFY_SUCCESS);
        while((ch=getchar())!='\n');
        printf("%s",SAVE_MODIFYSTUDENT_TOFILE);
        ch = getchar();
        if(ch== 'y'||ch == 'Y'){
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
}

void modifyTeacherInfo() {
    char ch;
    int ret,userid;
    char name[64] = {0};
    char passwd[32] = {0};
    int id,age,sex,classid,lession;
    TEA* pn;

    system("clear");
    printf("%s\n",SEARCH_TEACHER_INFO);
    PrintTeacherInfo(&g_pteacher);
    
    printf("%s",INPUT_MODIFY_TEACHER_ID);
    scanf("%d",&userid);
    pn = onSearchUserInfo(TEACHER,userid);
    if(pn == NULL) {
        printf("%s\n",QUERY_STUDENT_INFO_ERROR);
        sleep(3);
        return;
    } else {
        printf("%s\n",MODIFY_TEACHER_INFO);
        scanf("%d%s%d%d%d%d%s",
            &id,name,&age,&sex,&classid,&lession,passwd);
        pn->id = id;
        pn->age = age;
        pn->sex = sex;
        pn->class_no = classid;
        pn->lession = lession;
        strcpy(pn->name,name);
        strcpy(pn->passwd,passwd);
        
        printf("%s",INFO_MODIFY_SUCCESS);
        while((ch=getchar())!='\n');
        printf("%s",SAVE_MODIFYTEACHER_TOFILE);
        ch = getchar();
        if(ch== 'y'||ch == 'Y'){
            ret = onSaveLinkListToFile(TEACHER);
            if(ret == 0) {
                printf("%s\n",SAVE_FILE_SUCCESS);
                onReloadLinkList(TEACHER);
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
}

void modifyAdminInfo() {
    char ch;
    int ret,userid;
    ADMIN* pn;
    char name[64] = {0};
    char passwd[32] = {0};
    int id,age,sex;

    system("clear");
    printf("%s\n",SEARCH_ADMIN_INFO);
    PrintAdminInfo(&g_padmin);
    
    printf("%s",INPUT_MODIFY_ADMIN_ID);
    scanf("%d",&userid);
    pn = onSearchUserInfo(ADMINISTRATOR,userid);
    if(pn == NULL) {
        printf("%s\n",QUERY_STUDENT_INFO_ERROR);
        sleep(3);
        return;
    } else {
        printf("%s\n",MODIFY_ADMIN_INFO);
        scanf("%d%s%d%d%s",
            &id,name,&age,&sex,passwd);
        pn->id = id;
        pn->age = age;
        pn->sex = sex;
        strcpy(pn->name,name);
        strcpy(pn->passwd,passwd);
        
        printf("%s",INFO_MODIFY_SUCCESS);
        while((ch=getchar())!='\n');
        printf("%s",SAVE_MODIFYADMIN_TOFILE);
        ch = getchar();
        if(ch== 'y'||ch == 'Y'){
            ret = onSaveLinkListToFile(ADMINISTRATOR);
            if(ret == 0) {
                printf("%s\n",SAVE_FILE_SUCCESS);
                onReloadLinkList(ADMINISTRATOR);
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
        printf("\t\t##                 3.%s             ##\n",MODIFY_ADMIN_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();
        switch(ch) {
            case '1':
                modifyStudentInfo();
                break;
            case '2':
                modifyTeacherInfo();
                break;
            case '3':
                modifyAdminInfo();
                break;
            case '4':
                return;
                break;
            default:
                break;
        }
    }
}

void delStudentInfo(){
    char ch;
    int userid;
    int ret;

    while(1) {
        system("clear");
        printf("%s\n",SEARCH_STUDENT_INFO);
        PrintStudentInfo(&g_pstudent);
        printf("%s",INPUT_DEL_STUDENT_ID);
        scanf("%d",&userid);
        ret = onDelUserFromLinkList(STUDENT,userid);
        if(ret==0) {
            while((ch=getchar())!='\n');
            printf("%s",INFO_DEL_SUCCESS);
            printf("%s",SAVE_DELSTUDENT_TOFILE);
            ch = getchar();
            if(ch== 'y'||ch == 'Y'){
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
                break;
            }
        } else {
            printf("%s\n",INFO_DEL_FAILED);
            sleep(3);
            break;
        }
    }
}

void delTeacherInfo() {
    char ch;
    int userid;
    int ret;

    while(1) {
        system("clear");
        printf("%s\n",SEARCH_TEACHER_INFO);
        PrintTeacherInfo(&g_pteacher);
        printf("%s",INPUT_DEL_TEACHER_ID);
        scanf("%d",&userid);
        ret = onDelUserFromLinkList(TEACHER,userid);
        if(ret==0) {
            while((ch=getchar())!='\n');
            printf("%s",INFO_DEL_SUCCESS);
            printf("%s",SAVE_DELTEACHER_TOFILE);
            ch = getchar();
            if(ch== 'y'||ch == 'Y'){
                ret = onSaveLinkListToFile(TEACHER);
                if(ret == 0) {
                    printf("%s\n",SAVE_FILE_SUCCESS);
                    onReloadLinkList(TEACHER);
                    sleep(3);
                    return;
                } else {
                    printf("%s",SAVE_FILE_FAILED);
                    sleep(3);
                    return;
                }
            } else {
                break;
            }
        } else {
            printf("%s\n",INFO_DEL_FAILED);
            sleep(3);
            break;
        }
    }   
}

void delAdminInfo() {
    char ch;
    int userid;
    int ret;

    while(1) {
        system("clear");
        printf("%s\n",SEARCH_ADMIN_INFO);
        PrintAdminInfo(&g_padmin);
        printf("%s",INPUT_DEL_ADMIN_ID);
        scanf("%d",&userid);
        ret = onDelUserFromLinkList(ADMINISTRATOR,userid);
        if(ret==0) {
            while((ch=getchar())!='\n');
            printf("%s",INFO_DEL_SUCCESS);
            printf("%s",SAVE_DELADMIN_TOFILE);
            ch = getchar();
            if(ch== 'y'||ch == 'Y'){
                ret = onSaveLinkListToFile(ADMINISTRATOR);
                if(ret == 0) {
                    printf("%s\n",SAVE_FILE_SUCCESS);
                    onReloadLinkList(ADMINISTRATOR);
                    sleep(3);
                    return;
                } else {
                    printf("%s",SAVE_FILE_FAILED);
                    sleep(3);
                    return;
                }
            } else {
                break;
            }
        } else {
            printf("%s\n",INFO_DEL_FAILED);
            sleep(3);
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
        printf("\t\t##                 3.%s             ##\n",DEL_ADMIN_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();
        switch(ch) {
            case '1':
                delStudentInfo();
                break;
            case '2':
                delTeacherInfo();
                break;
            case '3':
                delAdminInfo();
                break;
            case '4':
                return;
                break;
            default:
                break;
        }
    }   
}

void searchStudentInfo() {
    char ch;
    int userid;
    STU* pn;

    system("clear");
    while(1) {
        printf("%s",INPUT_SEARCH_STUDENT_ID);
        scanf("%d",&userid);
        pn = onSearchUserInfo(STUDENT,userid);
        if(pn == NULL) {
            printf("%s\n",QUERY_STUDENT_INFO_ERROR);
            sleep(3);
            return;
        } else {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
            SHOW_STUDENT_NUM,
            SHOW_STUDENT_NAME,
            SHOW_STUDENT_AGE,
            SHOW_STUDENT_SEX,
            SHOW_STUDENT_TELNUM,
            SHOW_STUDENT_QQ,
            SHOW_STUDENT_CLASSID,
            SHOW_STUDENT_PASSWD
            );
            printf("%d\t%s\t%d\t%d\t%s\t%s\t%d\t%s\n",
            pn->id,
            pn->name,
            pn->age,
            pn->sex,
            pn->telnum,
            pn->QQ,
            pn->classid,
            pn->passwd
            );
        }
        while((ch=getchar())!='\n');
        printf("%s",CONTINUE_SEARCH_USER);
        ch = getchar();
        if(ch == 'y'||ch == 'Y') {
            continue;
        }else {
            break;
        }
    }
}

void searchTeacherInfo() {
    char ch;
    int userid;
    TEA* pn;

    system("clear");
    while(1) {
        printf("%s",INPUT_SEARCH_TEACHER_ID);
        scanf("%d",&userid);
        pn = onSearchUserInfo(TEACHER,userid);
        if(pn == NULL) {
            printf("%s\n",QUERY_STUDENT_INFO_ERROR);
            sleep(3);
            return;
        } else {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
            SHOW_TEACHER_NUM,
            SHOW_TEACHER_NAME,
            SHOW_TEACHER_AGE,
            SHOW_TEACHER_SEX,
            SHOW_TEACHER_CLASSNO,
            SHOW_TEACHER_LESSION,
            SHOW_TEACHER_PASSWD
            );
            printf("%d\t%s\t%d\t%d\t%d\t%d\t%s\n",
            pn->id,
            pn->name,
            pn->age,
            pn->sex,
            pn->class_no,
            pn->lession,
            pn->passwd
            );
        }
        while((ch=getchar())!='\n');
        printf("%s",CONTINUE_SEARCH_USER);
        ch = getchar();
        if(ch == 'y'||ch == 'Y') {
            continue;
        }else {
            break;
        }
    }   
}

void searchAdminInfo() {
    char ch;
    int userid;
    ADMIN* pn;

    system("clear");
    while(1) {
        printf("%s",INPUT_SEARCH_ADMIN_ID);
        scanf("%d",&userid);
        pn = onSearchUserInfo(ADMINISTRATOR,userid);
        if(pn == NULL) {
            printf("%s\n",QUERY_STUDENT_INFO_ERROR);
            sleep(3);
            return;
        } else {
            printf("%s\t%s\t%s\t%s\t%s\n",
            SHOW_ADMIN_NUM,
            SHOW_ADMIN_NAME,
            SHOW_ADMIN_AGE,
            SHOW_ADMIN_SEX,
            SHOW_ADMIN_PASSWD
            );
            printf("%d\t%s\t%d\t%d\t%s\n",
            pn->id,
            pn->name,
            pn->age,
            pn->sex,
            pn->passwd
            );
        }
        while((ch=getchar())!='\n');
        printf("%s",CONTINUE_SEARCH_USER);
        ch = getchar();
        if(ch == 'y'||ch == 'Y') {
            continue;
        }else {
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
        printf("\t\t##                 3.%s             ##\n",SEARCH_ADMIN_INFOMATION);
        printf("\t\t##                                              ##\n");
        printf("\t\t##                 4.%s               ##\n",RETURN_PARENT_FOLDER);
        printf("\t\t##                                              ##\n");
        printf("\t\t##################################################\n");
        
        printf("\n\n");
        printf("%s",SELECT_MENU_ELEMENT);
        getchar();
        ch = getchar();
        switch(ch) {
            case '1':
                searchStudentInfo();
                break;
            case '2':
                searchTeacherInfo();
                break;
            case '3':
                searchAdminInfo();
                break;
            case '4':
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
