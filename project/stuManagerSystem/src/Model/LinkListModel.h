/*########################################################
##File Name: LinkListModel.h
##Created Time:2015年12月01日 星期二 16时01分21秒
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

#ifndef _LINKLISTMODEL_H
#define _LINKLISTMODEL_H
#include "../utils/DataStruct.h"

void* onSearchStudentInfoModel(STU* head,int userid);
void* onSearchTeacherInfoModel(TEA* head,int userid);

int onSaveStudentLinkListToFileModel(STU* head);

void onReloadStudentLinkList(STU* head);


STU* onSearchScoreSortByID(STU* head);  
STU* onSearchScoreSortByName(STU* head);  
STU* onSearchScoreSortByClassid(STU* head);  
STU* onSearchScoreSortByTotal(STU* head);  



int AddStudentNodeToLinkListModel(STU* head,STU* pn);
int AddTeacherNodeToLinkListModel(TEA* head,TEA* pn);
int AddAdminNodeToLinkListModel(ADMIN* head,ADMIN* pn);
#endif
