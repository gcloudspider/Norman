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
            //STU *ret;
            ret = onSearchStudentInfoModel(g_pstudent,userid);
            break;
        case TEACHER:
            //TEA *ret;
            break;
        case ADMINISTRATOR:
            //ADMIN* ret;
            break;
        default:
            break;
    }
    return ret;
}
