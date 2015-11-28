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
    STU* head = NULL;
    
    ReadStudentDataToLinkList(&head);
    PrintStudentDoubleLinkList(&head);

    return 0;
}
