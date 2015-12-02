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


void onSearchScoreSortByID(STU** head);  
void onSearchScoreSortByName(STU** head);  
void onSearchScoreSortByClassid(STU** head);  
void onSearchScoreSortByTotal(STU** head);  
#endif
