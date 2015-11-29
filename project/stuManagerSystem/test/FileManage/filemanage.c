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


int delete_double_link_list(STU **head,int n) {
    STU* pn;
    pn = *head;
    //1.查找要删除的节点
    while(pn) {
        if(pn->id == n) break;
        pn = pn->next;
    }

    if(pn){
        if(pn == *head) {
            //要删除的是第一个
            if(pn->next) {          //是否为最后一个
                pn->next->pre = NULL;
                *head = pn->next;
            }else {
                *head=NULL;          //是最后一个,解除head指针指向
            }
        } else {
            if(pn->next){
             pn->next->pre=pn->pre;
             pn->pre->next = pn->next;
            }else {
                pn->pre->next = pn->next;
            }
        }
    } else {
        return -1;
    }
    return 0;
}


int main() {
    STU* head_student = NULL;
    TEA* head_teacher = NULL;
    ADMIN* head_admin = NULL;

    //测试admin链表
    ReadAdminDataToLinkList(&head_admin);
    PrintAdminDoubleLinkList(&head_admin);

    //测试student链表
    ReadStudentDataToLinkList(&head_student);
    PrintStudentDoubleLinkList(&head_student);

    //测试teacher链表
    ReadTeacherDataToLinkList(&head_teacher);
    PrintTeacherDoubleLinkList(&head_teacher);

    delete_double_link_list(&head_student,1001);
    delete_double_link_list(&head_student,1006);
    PrintStudentDoubleLinkList(&head_student);
    //测试链表回写文件
    WriteDataToStudentFile(&head_student);

    return 0;
}
