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
#include "FileManage.h"

//从文件读入数据到双向链表
int ReadStudentDataToLinkList(STU **head) {
    FILE* fp;
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

        fscanf(fp,"%d\t%s\t%d\t%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
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
               &stu->c_adv,
               &stu->total
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
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
          SHOW_STUDENT_NUM,
          SHOW_STUDENT_NAME,
          SHOW_STUDENT_CLASSID,
          SHOW_STUDENT_SCORE_MATH,
          SHOW_STUDENT_SCORE_ENGLISH,
          SHOW_STUDENT_SCORE_CLANG,
          SHOW_STUDENT_SCORE_JAVA,
          SHOW_STUDENT_SCORE_CADV,
          SHOW_STUDENT_TOTAL_SCORE);
    while(pn) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
              pn->id,
              pn->name,
              pn->classid,
               pn->math,
               pn->english,
               pn->c_lang,
               pn->java,
               pn->c_adv,
               pn->total
              );   
        pn = pn->next;
    }
    return;
}

//从文件读数据写入双向链表
int ReadTeacherDataToLinkList(TEA **head) {
    FILE* fp;
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
        fprintf(fp,"%d\t%s\t%d\t%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
                pn->id,
                pn->name,
                pn->age,
                pn->sex,
                pn->telnum,
                pn->QQ,
                pn->passwd,
                pn->classid,
               pn->math,
               pn->english,
               pn->c_lang,
               pn->java,
               pn->c_adv,
                pn->total
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

void PrintStudentInfo(STU **head) {
    STU* pn;
    pn = *head;
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
    while(pn) {
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
        pn = pn->next;
    }
    return;   
}

void PrintTeacherInfo(TEA **head) {
    TEA* pn;
    pn = *head;
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
          SHOW_TEACHER_NUM,
          SHOW_TEACHER_NAME,
          SHOW_TEACHER_AGE,
          SHOW_TEACHER_SEX,
          SHOW_TEACHER_CLASSNO,
          SHOW_TEACHER_LESSION,
          SHOW_TEACHER_PASSWD);
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
}

void PrintAdminInfo(ADMIN **head) {
    ADMIN* pn;
    pn = *head;
    printf("%s\t%s\t%s\t%s\t%s\n",
          SHOW_ADMIN_NUM,
          SHOW_ADMIN_NAME,
          SHOW_ADMIN_AGE,
          SHOW_ADMIN_SEX,
          SHOW_ADMIN_PASSWD);
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
}
