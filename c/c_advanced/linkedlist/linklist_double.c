/*########################################################
##File Name: linklist_double.c
##Created Time:2015年11月25日 星期三 17时34分24秒
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
#include <stdlib.h>
typedef struct student {
    int stu_num;
    char stu_name[64];
    int stu_age;
    int stu_score;
    struct student *pre;
    struct student *next;
}STU;

int create_double_link_list(STU **head) {
    STU* pn;
    char ch;

    while(1) {
        pn = malloc(sizeof(STU));
        if(pn == NULL) {
            printf("malloc error!\n");
            return -1;
        }

        scanf("%d%s%d%d",
             &pn->stu_num,
             pn->stu_name,
             &pn->stu_age,
             &pn->stu_score
             );

        while((ch=getchar())!= '\n');
        if(*head) {
            pn->next = *head;
            (*head)->pre = pn;
            *head = pn;
            pn->pre = NULL;
        }else {
            *head=pn;
            pn->next = NULL;
            pn->pre = NULL;
        }

        printf("IS continue? please input yes or no(Y/N): ");

clear_enter:
        ch = getchar();
        if(ch=='n'||ch=='N') {
            break;
        } else if(ch=='y'|| ch=='Y' || ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }
    }
}


void print_double_link_list(STU **head) {
    STU* pn;
    pn = *head;
    printf("num\tname\tage\tscore\n");
    while(pn) {
        printf("%d\t%s\t%d\t%d\n",
              pn->stu_num,
              pn->stu_name,
              pn->stu_age,
              pn->stu_score
              );
        pn= pn->next;
    }

    return ;
}

int delete_double_link_list(STU **head,int n) {
    STU* pn;
    pn = *head;
    //1.查找要删除的节点
    while(pn) {
        if(pn->stu_num == n) break;
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

void reveser_double_link_list(STU **head) {
    STU *pn,*new_head= NULL;
    pn = *head;
    while(pn) {
        if(new_head) {
            if(pn->next){
                pn->next->pre = NULL;
                new_head->pre = pn;
                *head = pn->next;
                pn->next = new_head;
                pn = *head;
                new_head = new_head->pre;
            }else {
                //pn 为最后一个
                new_head->pre = pn;
                pn->next = new_head;
                new_head = pn;
                pn = pn->pre;
            }
        } else {
            //new_head中第一个节点
            pn->next->pre = NULL;
            *head = pn->next;
            new_head = pn;
            pn->next = NULL;
            pn = *head;
        }
    }
    *head = new_head;
    return;
}

STU* search_max_double_link_list(STU **head) {
    
}

void sort_double_link_list(STU **head) {
    STU *pn,*max;
    STU *new_head = NULL;
    printf("head=%p",*head);

    while(head) {
        max = *head;
        pn = *head;
        while(pn) {
            //查找最大节点
            if(pn->stu_num > max->stu_num) {
                max = pn;
                break;
            }
            pn = pn->next;
        }
        printf("search max=%p\n",max);

        if(max) {
            //是否new_head第一个
            if(max == *head) {
                if(max->next) {
                    max->next->pre = NULL;
                    *head = max->next;
                    max->next = new_head;
                    new_head = max;
                } else {
                    
                }
            } else {
                if(max->next) {
                    max->next->pre = max->pre;
                    max->pre->next = max->next;
                    max->pre = NULL;
                    max->next = new_head;
                    new_head = max;
                } else {
                    max->pre->next = NULL;
                    max->pre = NULL;
                    max->next = new_head;
                    new_head = max;
                }
            }
        } else {
            break;
        }   
    }
    *head = new_head;
    return ;
}

int main() {
    STU* head = NULL;
    int num;
    int ret;
    //创建双链表
    create_double_link_list(&head);
    //打印双向链表
    print_double_link_list(&head);

    printf("please input delete stu number: \n");
    scanf("%d",&num);
    //删除双向链表中一个节点
    ret = delete_double_link_list(&head,num);
    if(!ret){
       printf("Deleted Successfuly...\n"); 
    } else {
        printf("Deleted Failed!\n");
    }
    
    print_double_link_list(&head);
    //反序双向链表
    printf("reverse double link list\n");
    reveser_double_link_list(&head);
 
    print_double_link_list(&head);
    //排序双向链表
    printf("sort double link list\n");
    sort_double_link_list(&head);

    print_double_link_list(&head);

    return 0;
}
