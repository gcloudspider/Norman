/*########################################################
##File Name: AdminMenu.h
##Created Time:2015年11月30日 星期一 19时58分16秒
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

#ifndef _ADMINMENU_H
#define _ADMINMENU_H
#include "../utils/DataStruct.h"

void ShowAdminMenu();

void AddUserInfo();
void AddStudentNode(STU** pn);
void AddTeacherNode(TEA** pn);
void AddAdminNode(ADMIN** pn);

void ModifyUserInfo();
void modifyStudentInfo();
void modifyTeacherInfo();
void modifyAdminInfo();

void DelUserInfo();
void delStudentInfo();
void delTeacherInfo();
void delAdminInfo();

void SearchUserInfo();
void searchStudentInfo();
void searchTeacherInfo();
void searchAdminInfo();

#endif
