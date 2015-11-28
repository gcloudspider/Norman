/*########################################################
##File Name: filemanage.c
##Created Time:2015年11月28日 星期六 10时20分57秒
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
#include "../../src/DataManager/FileManager.h"
#include "../../src/utils/DataStruct.h"

int main() {
    STU* head_student = NULL;
    TEA* head_teacher = NULL;
    ReadStudentDataToLinkList(&head_student);
    PrintStudentDoubleLinkList(&head_student);

    ReadTeacherDataToLinkList(&head_teacher);
    PrintTeacherDoubleLinkList(&head_teacher);
    return 0;
}
