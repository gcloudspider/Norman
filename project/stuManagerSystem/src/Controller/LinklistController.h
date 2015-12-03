/*########################################################
##File Name: LinklistController.h
##Created Time:2015年12月01日 星期二 15时53分08秒
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

#ifndef _LINKLISTCONTROLLER_H
#define _LINKLISTCONTROLLER_H
#include "../utils/DataStruct.h"

void* onSearchUserInfo(int usertype,int userid);

int onSaveLinkListToFile(int usertype);

void onReloadLinkList(int usertype);

STU* onSearchScoreSort(int sortkey);


int AddUserNodeToLinkList(int usertype,void* pn);

#endif
