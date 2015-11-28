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

int ReadStudentDataToLinkList(STU **head);
int WriteDataToStudentFile(STU **head);

int ReadTeacherDataToLinkList(TEA **head);
int WriteDataToTeacherFile(TEA **head);

void PrintStudentDoubleLinkList(STU **head);
void PrintTeacherDoubleLinkList(TEA **head);

#endif
