/*########################################################
##File Name: FileManager.c
##Created Time:2015年11月28日 星期六 09时58分28秒
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
#include "FileManager.h"

//从文件读入数据到双向链表
int ReadStudentDataToLinkList(STU **head) {
    FILE* fp;
    size_t ret;
    STU* stu,*p;

    fp = fopen(STU_FILE_STORAGE_NAME,"r+");
    if(fp == NULL) {
        perror("while fopen():");
        return -1;
    }
    
    while(feof(fp)==0) {
        stu = malloc(sizeof(STU));
        if(stu == NULL) {
            printf("malloc error!\n");
            return -1;
        }

        fscanf(fp,"%d\t%s\t%d\t%d\t%s\t%s\t%s\t%d\n",
              &stu->id,
               stu->name,
              &stu->age,
              &stu->sex,
              stu->telnum,
              stu->QQ,
              stu->passwd,
              &stu->classid
              );

        if(*head) {
            stu->next = NULL;
            stu->pre=p;
            p->next = stu;
        } else {
            stu->next = *head;
            stu->pre = *head;
            *head = stu;
        }
        p = stu;

    }

    fclose(fp);

    return 0;
}


//打印学生双向链表
void PrintStudentDoubleLinkList(STU **head) {
    STU* pn;
    pn = *head;
    printf("num\tname\tage\tsex\ttelnum\tQQ\tpasswd\tclassid\n");
    while(pn) {
        printf("%d\t%s\t%d\t%d\t%s\t%s\t%s\t%d\n",
              pn->id,
              pn->name,
              pn->age,
              pn->sex,
              pn->telnum,
              pn->QQ,
              pn->passwd,
              pn->classid
              );   
        pn = pn->next;
    }
    return;
}

//从文件读数据写入双向链表
int ReadTeacherDataToLinkList(TEA **head) {
    FILE* fp;
    size_t ret;
    TEA* tea,*p;

    fp = fopen(TEA_FILE_STORAGE_NAME,"r+");
    if(fp == NULL) {
        perror("while fopen():");
        return -1;
    }
    
    while(feof(fp)==0) {
        tea = malloc(sizeof(TEA));
        if(tea == NULL) {
            printf("malloc error!\n");
            return -1;
        }

        fscanf(fp,"%d\t%s\t%d\t%d\t%d\t%d\t%s\n",
              &tea->id,
               tea->name,
              &tea->age,
              &tea->sex,
              &tea->class_no,
              &tea->lession,
              tea->passwd
              );

        if(*head) {
            tea->next = NULL;
            tea->pre=p;
            p->next = tea;
        } else {
            tea->next = *head;
            tea->pre = *head;
            *head = tea;
        }
        p = tea;
    }

    fclose(fp);

    return 0;
}


//打印教师双向链表
void PrintTeacherDoubleLinkList(TEA **head) {
    TEA* pn;
    pn = *head;
    printf("num\tname\tage\tsex\tclass_no\tlession\tpasswd\n");
    while(pn) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%s\n",
              pn->id,
              pn->name,
              pn->age,
              pn->sex,
              pn->class_no,
              pn->lession,
              pn->passwd
              );   
        pn = pn->next;
    }
    return;
}

int WriteDataToStudentFile(STU **head) {
    FILE *fp;
    STU* pn;

    fp = fopen(STU_FILE_STORAGE_NAME,"w+");
    if(fp == NULL) {
        perror("while fopen():");
        return -1;
    }
    
    pn = *head;
    while(pn) {    
        fprintf(fp,"%d\t%s\t%d\t%d\t%s\t%s\t%s\t%d\n",
                pn->id,
                pn->name,
                pn->age,
                pn->sex,
                pn->telnum,
                pn->QQ,
                pn->passwd,
                pn->classid
               );
        pn=pn->next;
    }

    fclose(fp);
    return 0;
}

int WriteDataToTeacherFile(TEA **head) {
    FILE *fp;
    TEA* pn;

    fp = fopen(TEA_FILE_STORAGE_NAME,"w+");
    if(fp == NULL) {
        perror("while fopen():");
        return -1;
    }
    
    pn = *head;
    while(pn) {    
        fprintf(fp,"%d\t%s\t%d\t%d\t%d\t%d\t%s\n",
              pn->id,
              pn->name,
              pn->age,
              pn->sex,
              pn->class_no,
              pn->lession,
              pn->passwd);
        pn=pn->next;
    }

    fclose(fp);
    return 0;
}



int ReadAdminDataToLinkList(ADMIN **head) {
    FILE* fp;
    size_t ret;
    ADMIN* admin,*p;

    fp = fopen(ADMIN_FILE_STORAGE_NAME,"r+");
    if(fp == NULL) {
        perror("while fopen():");
        return -1;
    }
    
    while(feof(fp)==0) {
        admin = malloc(sizeof(ADMIN));
        if(admin == NULL) {
            printf("malloc error!\n");
            return -1;
        }

        fscanf(fp,"%d\t%s\t%d\t%d\t%s\n",
               &admin->id,
               admin->name,
              &admin->age,
              &admin->sex,
              admin->passwd
              );

        if(*head) {
            admin->next = NULL;
            admin->pre=p;
            p->next = admin;
        } else {
            admin->next = *head;
            admin->pre = *head;
            *head = admin;
        }
        p = admin;
    }

    fclose(fp);

    return 0;
}

int WriteDataToAdminFile(ADMIN **head) {
    FILE *fp;
    ADMIN* pn;

    fp = fopen(ADMIN_FILE_STORAGE_NAME,"w+");
    if(fp == NULL) {
        perror("while fopen():");
        return -1;
    }
    
    pn = *head;
    while(pn) {    
        fprintf(fp,"%d\t%s\t%d\t%d\t%s\n",
              pn->id,
              pn->name,
              pn->age,
              pn->sex,
              pn->passwd);
        pn=pn->next;
    }

    fclose(fp);
    return 0;
}

void PrintAdminDoubleLinkList(ADMIN **head) {
    ADMIN* pn;
    pn = *head;
    printf("id\tname\tage\tsex\tpasswd\n");
    while(pn) {
        printf("%d\t%s\t%d\t%d\t%s\n",
               pn->id,
              pn->name,
              pn->age,
              pn->sex,
              pn->passwd
              );   
        pn = pn->next;
    }
    return;
}
