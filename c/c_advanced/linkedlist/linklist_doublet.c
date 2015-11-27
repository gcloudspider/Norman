/*########################################################
##File Name: linklist_doublet.c
##Created Time:2015年11月27日 星期五 13时35分42秒
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
typedef struct student{
    int stu_num;
    char stu_name[64];
    int stu_age;
    int stu_score;
    struct student *pre;
    struct student *next;
}STU;

void create_double_link_list(STU **head) {
    STU* pn,*p;
    char ch;
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
        
        if(*head) {
            pn->next = NULL;
            pn->pre=p;
            p->next = pn;
        } else {
            pn->next = *head;
            pn->pre = *head;
            *head = pn;
        }
        p = pn;
        printf("is continue? please input yes or no(Y/N):");
clear_enter:
        ch =getchar();
        if(ch == 'n'||ch == 'N') {
            break;
        } else if(ch == 'y'|| ch == 'Y' || ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }
        
    }
}

void show_double_link_list(STU** head) {
    
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
        pn = pn->next;
    }

}


int main() {
    
    STU* head = NULL;

    create_double_link_list(&head);

    show_double_link_list(&head);

    return 0;
}
