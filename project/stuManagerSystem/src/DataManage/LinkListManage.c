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
