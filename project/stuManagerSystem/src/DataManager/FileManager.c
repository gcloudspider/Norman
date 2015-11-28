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
    STU* stu;

    fp = fopen(STU_FILE_STORAGE_NAME,"w+");
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
    }

    fclose(fp);

    return 0;
}




