/*########################################################
##File Name: linklist_singlerev.c
##Created Time:2015年11月24日 星期二 08时06分28秒
##Author: Norman 
##Description:  单链表逆序 
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

typedef struct student {
    int stu_num;
    char stu_name[64];
    int stu_age;
    int stu_score;
    struct student *next;
}STU;

int main() {
    STU* pn,*p,*q,*t;
    STU* head = NULL,*tail=NULL;
    char ch;

    //1.尾插法创建链表
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
        
        if(head == NULL) {
            head=pn;
        }else {
            if(tail->next == NULL) {
                tail->next = pn;
            }
        }
        pn->next = NULL;
        tail=pn;

        printf("Is continue? please input yes/enter or no(Y(enter)/N) : ");
clear_enter:
        ch=getchar();
        if(ch=='n'||ch=='N') {
            break;
        } else if(ch=='y'||ch=='Y'||ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }
    }

    //2.逆序链表
    p = head;
    q=head->next;

    while(q != NULL) {
        t = q->next;
        q->next = p;
        p=q;
        q=t;
    }
    head->next = NULL;
    head = p;
/*
    STU *p = head,*new_head=NULL;       //使用头插法创建新的链表
    while(head) {
        p=head;
        head=head->next;
        p->next=new_head;
        new_head=p;
    }
    head=new_head;
*/



    //3.输出链表
    pn = head;
    printf("num\tname\tage\tscore\n");
    while(pn) {
        printf("%d\t%s\t%d\t%d\n",pn->stu_num,pn->stu_name,pn->stu_age,pn->stu_score);
        pn = pn->next;
    }


    //4.释放链表

    return 0;
}
