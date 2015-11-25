/*########################################################
##File Name: linklist_singleinsert.c
##Created Time:2015年11月24日 星期二 20时57分44秒
##Author: Norman 
##Description: 
##
##Issue:有序的链表,插入一个节点后依然有序 
##
##Analyze: 
##      1.添加一个节点pn
##      2.根据节点p的num 找到>=p <=p->next
##      3.将p->next = pn
##      4.将pn的pn->next = p->next
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int stu_num;
    char stu_name[64];
    int stu_age;
    int stu_score;
    struct student *next;
}STU;


void create_link_list(STU** head) {
    STU* pn;

    while(1) {
        pn = malloc(sizeof(STU));
        if(pn == NULL) {
            printf("malloc error!\n");
            return ;
        }

        scanf("%d%s%d%d",
             &pn->stu_num,
             pn->stu_name,
             &pn->stu_age,
             &pn->stu_score
             );

        while((ch=getchar())!='\n');
        pn->next = *head;
        head = pn;

        printf("is continue ? please input yes or no(Y/N): ");
clear_enter:
        ch=getchar();
        if(ch=='n'||ch=='N') {
            break;
        } else if(ch=='y'|| ch=='Y'||ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }   
    }
}

void show_link_list(STU** head) {
    STU* pn;
    pn = *head;
    while(pn) {
        printf("%d%s%d%d",
               pn->stu_num,
              pn->stu_name,
              pn->stu_age,
              pn->stu_score
              );
        pn = pn->next;
    }
    return ;
}


int main() {
    STU* head = NULL;
    create_link_list(&head);

    show_link_list(&head);

    return 0;
}
