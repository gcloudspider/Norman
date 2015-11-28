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
void WriteDataToStudentFile();

void ReadTeacherDataToLinkList();
void WriteDataToTeacherFile();

#endif
