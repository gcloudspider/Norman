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

void* onSearchStudentInfoModel(STU* head,int userid) {
    STU* pn;
    pn = onSearchStudentLinkList(head,userid);
    return pn;
}
