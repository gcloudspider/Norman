/*########################################################
##File Name: InitAppModel.c
##Created Time:2015年11月29日 星期日 11时17分53秒
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
#include "InitAppModel.h"
#include "../DataManage/FileManage.h"
#include "../utils/DataStruct.h"
#include "../utils/global.h"

void InitStudentModel() {
    STU *head = NULL;
    int ret;
    ret = ReadStudentDataToLinkList(&head);
    if(ret==0) {
        g_pstudent = head;
        //printf("Create Student Double Link List From File Sucessfuly!\n");
        //PrintStudentDoubleLinkList(&head);
    } else {
        printf("Create Student Double Link List Error!\n");
    }
}

void InitTeacherModel() {
    TEA* head = NULL;
    int ret;
    ret = ReadTeacherDataToLinkList(&head);
    if(ret == 0) {
        g_pteacher = head;
        //printf("Create Teacher Double Link List From File Sucessfuly!\n");
        //PrintTeacherDoubleLinkList(&head);
    } else {
        printf("Create Teacher Double Link List Error!\n");
    }
}

void InitAdminModel() {
    ADMIN* head = NULL;
    int ret;
    ret = ReadAdminDataToLinkList(&head);
    if(ret == 0) {
        g_padmin = head;
        //printf("Create Admin Double Link List From File Sucessfuly!\n");
        //PrintAdminDoubleLinkList(&head);
    } else {
        printf("Create Admin Double Link List Error!\n");
    }
}

