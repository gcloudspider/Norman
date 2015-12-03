/*########################################################
##File Name: ReleaseLinkList.c
##Created Time:2015年11月30日 星期一 10时02分05秒
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
#include<stdlib.h>
#include "LinkListManage.h"
#include "../utils/DataStruct.h"

int ReleaseStudentLinkList(STU *head) {
    STU *pn = NULL;
    while(head) {
        pn = head->next;
        free(head);
        head = pn;
    }
    return 0;
}

int ReleaseTeacherLinkList(TEA *head) {
    TEA *pn = NULL;
    while(head) {
        pn = head->next;
        free(head);
        head = pn;
    }
    return 0;
}

int ReleaseAdminLinkList(ADMIN *head) {
    ADMIN *pn = NULL;
    while(head) {
        pn = head->next;
        free(head);
        head = pn;
    }
    return 0;
}


STU* onSearchStudentLinkList(STU *head,int userid) {
    STU* pn = NULL;
    while(head) {
        if(head->id == userid) {
            pn = head;
        }
        head = head->next;
    }
    return pn;
}

TEA* onSearchTeacherLinkList(TEA *head,int userid) {
    TEA* pn = NULL;
    while(head) {
        if(head->id == userid) {
            pn = head;
        }
        head = head->next;
    }
    return pn;
}

ADMIN* onSearchAdminLinkList(ADMIN *head,int userid) {
    ADMIN* pn = NULL;
    while(head) {
        if(head->id == userid) {
            pn = head;
        }
        head = head->next;
    }
    return pn;
}

//排序
STU* onSortStudentLinkListByID(STU* head) {
    STU *pn,*max;
    STU *new_head = NULL;
    printf("head=%p\n",head);

    while(head) {
        max = head;
        pn = head;
        while(pn) {
            //查找最大节点
            if(pn->id > max->id) {
                max = pn;
            }
            pn = pn->next;
        }
        //printf("search max=%p\tstu_num=%d\n",max,max->stu_num);

        if(max) {
            //是否new_head 是否为空
            if(new_head) {
                if(max == head) {
                    if(max->next) {     //是第一个但head链表还有节点
                        max->next->pre= NULL;
                        head = max->next;
                        max->next = new_head;
                        new_head->pre = max;
                        new_head = max;
                    } else {            //head中最后一个
                        max->next = new_head;
                        new_head->pre = max;
                        new_head = max;
                        head = NULL;
                    }
                } else {
                    if(max->next) {
                        max->pre->next = max->next;
                        max->next->pre = max->pre;
                        max->next = new_head;
                        new_head->pre = max;
                        max->pre = NULL;
                        new_head = max;
                    } else {        //new_head有节点,head有节点max 是最后一个
                        max->pre->next = NULL;
                        max->next = new_head;
                        max->pre = NULL;
                        new_head->pre = max;
                        new_head = max;
                    }
                }
            } else {
                //判断将添加max 为head 第一个
                if(max == head) {
                    //判断将添加max 为head 最后一个
                    if(max->next) {
                        max->next->pre = NULL;
                        head = max->next;
                        max->next = NULL;
                        new_head = max;
                    } else {
                        head = NULL;
                        new_head=max;
                    }
                } else {
                    //判断是否为最后一个
                    if(max->next){
                        max->pre->next = max->next;
                        max->next->pre = max->pre;
                        max->next = NULL;
                        max->pre = NULL;
                        new_head = max;
                    } else {
                        max->pre->next = NULL;
                        max->pre = NULL;
                        new_head = max;
                    }
                }   
            }
        } else {
            break;
        }   
    }
    
    printf("new_head=%p\n",new_head);
    //*head = new_head;
    return new_head;
}

STU* onSortStudentLinkListByName(STU* head) {

}

STU* onSortStudentLinkListByClassid(STU* head) {

}

STU* onSortStudentLinkListByTotal(STU* head) {
    
}

int DelStudentLinkList(STU *head,int userid) {
    //TODO:删除学生链表中的某个节点
    return 0;
}

int DelTeacherLinkList(TEA *head,int userid) {
    //TODO:删除教师链表中某个节点
    return 0;
}

int DelAdminLinkList(ADMIN *head,int userid) {
    //TODO:删除管理员链表中某个节点
    return 0;
}


int ModifyStudentLinkList(STU *head,int userid,char *passwd) {
    //TODO: 修改学生链表信息
    return 0;
}

int ModifyTeacherLinkList(TEA *head,int userid,char *passwd) {
    //TODO:修改教师链表节点信息
    return 0;
}

int ModifyAdminLinkList(ADMIN *head,int userid,char *passwd) {
    //TODO:修改管理员链表节点信息
    return 0;
}


int AddStudentLinkList(STU *head,STU* pn) {
    //TODO:新增学生
    STU* stu = NULL;
    stu = head;
    while(stu) {
        if(stu->next == NULL) break;  
    }
    
    stu->next = pn;
    pn->pre = stu;

    return 0;
}

int AddTeacherLinkList(TEA *head,TEA* pn) {
    //TODO:新增教师
    TEA* tea = NULL;
    tea = head;
    while(tea) {
        if(tea->next == NULL) break;  
    }
    
    tea->next = pn;
    pn->pre = tea;

    return 0;
}

int AddAdminLinkList(ADMIN *head,ADMIN* pn) {
    //TODO:新增管理员
    ADMIN* admin = NULL;
    admin = head;
    while(admin) {
        if(admin->next == NULL) break;  
    }
    
    admin->next = pn;
    pn->pre = admin;

    return 0;
}
