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

//删除链表节点
int DelStudentLinkList(STU *head,int userid);
int DelTeacherLinkList(TEA *head,int userid);
int DelAdminLinkList(ADMIN *head,int userid);

//修改链表密码
int ModifyStudentLinkList(STU *head,int userid,char *passwd);
int ModifyTeacherLinkList(TEA *head,int userid,char *passwd);
int ModifyAdminLinkList(ADMIN *head,int userid,char *passwd);

//新增用户
int AddStudentLinkList(STU *head,STU* pn);
int AddTeacherLinkList(TEA *head,TEA* pn);
int AddAdminLinkList(ADMIN *head,ADMIN* pn);

//排序链表
STU* onSortStudentLinkListByID(STU* head);
STU* onSortStudentLinkListByName(STU* head);
STU* onSortStudentLinkListByClassid(STU* head);
STU* onSortStudentLinkListByTotal(STU* head);
#endif
