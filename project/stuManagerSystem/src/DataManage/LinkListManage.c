/*########################################################
##File Name: ReleaseLinkList.c
##Created Time:2015年11月30日 星期一 10时02分05秒
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
#include "LinkListManage.h"
#include "../utils/DataStruct.h"

int ReleaseStudentLinkList(STU *head) {
    STU *pn = NULL;
    while(head) {
        pn = head->next;
        free(head);
        head = pn;
    }
    return 0;
}

int ReleaseTeacherLinkList(TEA *head) {
    TEA *pn = NULL;
    while(head) {
        pn = head->next;
        free(head);
        head = pn;
    }
    return 0;
}

int ReleaseAdminLinkList(ADMIN *head) {
    ADMIN *pn = NULL;
    while(head) {
        pn = head->next;
        free(head);
        head = pn;
    }
    return 0;
}


STU* onSearchStudentLinkList(STU *head,int userid) {
    STU* pn = NULL;
    while(head) {
        if(head->id == userid) {
            pn = head;
        }
        head = head->next;
    }
    return pn;
}

TEA* onSearchTeacherLinkList(TEA *head,int userid) {
    TEA* pn = NULL;
    while(head) {
        if(head->id == userid) {
            pn = head;
        }
        head = head->next;
    }
    return pn;
}

ADMIN* onSearchAdminLinkList(ADMIN *head,int userid) {
    ADMIN* pn = NULL;
    while(head) {
        if(head->id == userid) {
            pn = head;
        }
        head = head->next;
    }
    return pn;
}



int DelStudentLinkList(STU *head,int userid) {
    //TODO:删除学生链表中的某个节点
    return 0;
}

int DelTeacherLinkList(TEA *head,int userid) {
    //TODO:删除教师链表中某个节点
    return 0;
}

int DelAdminLinkList(ADMIN *head,int userid) {
    //TODO:删除管理员链表中某个节点
    return 0;
}


int ModifyStudentLinkList(STU *head,int userid,char *passwd) {
    //TODO: 修改学生链表信息
    return 0;
}

int ModifyTeacherLinkList(TEA *head,int userid,char *passwd) {
    //TODO:修改教师链表节点信息
    return 0;
}

int ModifyAdminLinkList(ADMIN *head,int userid,char *passwd) {
    //TODO:修改管理员链表节点信息
    return 0;
}


int AddStudentLinkList(STU *head,STU* pn) {
    //TODO:新增学生
    return 0;
}

int AddTeacherLinkList(TEA *head,TEA* pn) {
    //TODO:新增教师
    return 0;
}

int AddAdminLinkList(ADMIN *head,ADMIN* pn) {
    //TODO:新增管理员
    return 0;
}
