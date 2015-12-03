/*########################################################
##File Name: LinklistController.c
##Created Time:2015年12月01日 星期二 15时53分22秒
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
#include "LinklistController.h"
#include "../utils/DataEnum.h"
#include "../Model/LinkListModel.h"
#include "../utils/global.h"

void* onSearchUserInfo(int usertype,int userid) {
    void* ret;
    switch(usertype) {
        case STUDENT:
            ret = onSearchStudentInfoModel(g_pstudent,userid);
            break;
        case TEACHER:
            ret = onSearchTeacherInfoModel(g_pteacher,userid);
            break;
        case ADMINISTRATOR:
            //ADMIN* ret;
            break;
        default:
            break;
    }
    return ret;
}

int onSaveLinkListToFile(int usertype) {
    int ret;
    switch(usertype) {
        case STUDENT:
            ret = onSaveStudentLinkListToFileModel(g_pstudent);
            break;
        case TEACHER:
            break;
        case ADMINISTRATOR:
            break;
        default:
            break;
    }    
    return ret;
}

void onReloadLinkList(int usertype) {
    switch(usertype) {
        case STUDENT:
            onReloadStudentLinkList(g_pstudent);
            break;
        case TEACHER:
            break;
        case ADMINISTRATOR:
            break;
        default:
            break;
    }
}

STU* onSearchScoreSort(int sortkey) {
    STU * ret;
    switch(sortkey) {
        case ID:
            ret = onSearchScoreSortByID(g_pstudent);  
            break;
        case NAME:
            ret = onSearchScoreSortByName(g_pstudent);  
            break;
        case CLASSID:
            ret = onSearchScoreSortByClassid(g_pstudent);  
            break;
        case TOTAL:
            ret = onSearchScoreSortByTotal(g_pstudent);  
            break;
        default:
            break;
    }
    return ret;
}


int AddUserNodeToLinkList(int usertype,void* pn) {
    int ret;
    switch(usertype) {
        case STUDENT:
            ret = AddStudentNodeToLinkListModel(g_pstudent,pn);
            break;
        case TEACHER:
            ret = AddTeacherNodeToLinkListModel(g_pteacher,pn);
            break;
        case ADMINISTRATOR:
            ret = AddAdminNodeToLinkListModel(g_padmin,pn);
            break;
        default:
            break;
    }
    return ret;
}
