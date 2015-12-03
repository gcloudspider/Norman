/*########################################################
##File Name: LinkListModel.c
##Created Time:2015年12月01日 星期二 16时01分27秒
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
#include "LinkListModel.h"
#include "../DataManage/LinkListManage.h"
#include "../DataManage/FileManage.h"
#include "../utils/DataConst.h"
#include "../utils/global.h"

//搜索
void* onSearchStudentInfoModel(STU* head,int userid) {
    STU* pn;
    pn = onSearchStudentLinkList(head,userid);
    return pn;
}

void* onSearchTeacherInfoModel(TEA* head,int userid) {
    TEA* pn;
    pn = onSearchTeacherLinkList(head,userid);
    return pn;
}

//保存
int onSaveStudentLinkListToFileModel(STU* head) {
    int ret;
    ret = WriteDataToStudentFile(&head);
    return ret;
}

void onReloadStudentLinkList(STU* head) {
    int ret,rets;
    STU* pn = NULL;
    ret = ReleaseStudentLinkList(head);
    if(ret == 0) {
        rets = ReadStudentDataToLinkList(&pn);
        if(rets==0) {
            g_pstudent = pn;
            //printf("%s\n",RELOAD_STU_LINK_LIST_SUCCESS);
        } else {
            printf("%s\n",RELOAD_STU_LINK_LIST_FAILED);
            return;
        }   
    }
}

int onSaveTeacherLinkListToFileModel(TEA* head) {
    int ret;
    ret = WriteDataToTeacherFile(&head);
    return ret;
}

void onReloadTeacherLinkList(TEA* head) {
    int ret,rets;
    TEA* pn = NULL;
    ret = ReleaseTeacherLinkList(head);
    if(ret == 0) {
        rets = ReadTeacherDataToLinkList(&pn);
        if(rets==0) {
            g_pteacher = pn;
            //printf("%s\n",RELOAD_STU_LINK_LIST_SUCCESS);
        } else {
            printf("%s\n",RELOAD_STU_LINK_LIST_FAILED);
            return;
        }   
    }
}

int onSaveAdminLinkListToFileModel(ADMIN* head) {
    int ret;
    ret = WriteDataToAdminFile(&head);
    return ret;
}

void onReloadAdminLinkList(ADMIN* head) {
    int ret,rets;
    ADMIN* pn = NULL;
    ret = ReleaseAdminLinkList(head);
    if(ret == 0) {
        rets = ReadAdminDataToLinkList(&pn);
        if(rets==0) {
            g_padmin = pn;
            //printf("%s\n",RELOAD_STU_LINK_LIST_SUCCESS);
        } else {
            printf("%s\n",RELOAD_STU_LINK_LIST_FAILED);
            return;
        }   
    }
}

STU* onSearchScoreSortByID(STU* head){
    return onSortStudentLinkListByID(head);
}

STU* onSearchScoreSortByName(STU* head) {
    return onSortStudentLinkListByName(head);
}

STU* onSearchScoreSortByClassid(STU* head) {
    return onSortStudentLinkListByClassid(head);
}

STU* onSearchScoreSortByTotal(STU* head) {
    return onSortStudentLinkListByTotal(head);
}


int AddStudentNodeToLinkListModel(STU* head,STU* pn) {
    return AddStudentLinkList(head,pn);
}

int AddTeacherNodeToLinkListModel(TEA* head,TEA* pn) {
    return AddTeacherLinkList(head,pn);
}

int AddAdminNodeToLinkListModel(ADMIN* head,ADMIN* pn) {
    return AddAdminLinkList(head,pn);
}
