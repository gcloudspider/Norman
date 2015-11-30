/*########################################################
##File Name: ReleaseLinkList.h
##Created Time:2015年11月30日 星期一 10时01分58秒
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

#ifndef _RELEASELINKLIST_H
#define _RELEASELINKLIST_H
#include "../utils/DataStruct.h"

//释放链表
int ReleaseStudentLinkList(STU *head);
int ReleaseTeacherLinkList(TEA *head);
int ReleaseAdminLinkList(ADMIN *head);

//查找链表
STU* onSearchStudentLinkList(STU *head,int userid);
TEA* onSearchTeacherLinkList(TEA *head,int userid);
ADMIN* onSearchAdminLinkList(ADMIN *head,int userid);


#endif
