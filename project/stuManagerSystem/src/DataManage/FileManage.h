/*########################################################
##File Name: FileManager.h
##Created Time:2015年11月28日 星期六 09时32分30秒
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

#ifndef _FILEMANAGER_H
#define _FILEMANAGER_H
#include "../utils/DataStruct.h"
#include <stdio.h>

//学生链表操作
int ReadStudentDataToLinkList(STU **head);
int WriteDataToStudentFile(STU **head);
void PrintStudentDoubleLinkList(STU **head);

//教师链表操作
int ReadTeacherDataToLinkList(TEA **head);
int WriteDataToTeacherFile(TEA **head);
void PrintTeacherDoubleLinkList(TEA **head);

//管理员链表操作
int ReadAdminDataToLinkList(ADMIN **head);
int WriteDataToAdminFile(ADMIN **head);
void PrintAdminDoubleLinkList(ADMIN **head);

//打印基本信息
void PrintStudentInfo(STU **head);
void PrintTeacherInfo(TEA **head);
void PrintAdminInfo(ADMIN **head);
#endif
