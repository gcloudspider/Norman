/*########################################################
##File Name: linklist_singlerevk.c
##Created Time:2015年11月24日 星期二 10时37分34秒
##Author: Norman 
##Description: 打印出链表倒数n个信息
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
    STU* pn;
    STU* head=NULL,*tail=NULL;
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
        /*
        pn->next=head;
        head = pn;
        */

        if(head == NULL) {
            head = pn;
        } else {
            if(tail->next == NULL) {
                tail->next = pn;
            }
        }

        pn->next = NULL;
        tail=pn;

        while((ch=getchar())!= '\n');
        printf("is continue? please input yes or no(Y/N): ");
clear_enter:
        ch = getchar();
        if(ch=='n'||ch=='N'){
            break;
        } else if(ch=='y'|| ch=='Y'|| ch=='\n') {
            continue;
        } else {
            goto clear_enter;
        }
    }


    STU *p=head,*q=head;
    printf("p=%p\tq=%p\thead=%p\n",p,q,head);
    int i=0,n;
    printf("please search rev num:\n");
    scanf("%d",&n);

    while(p) {
        i++;
        if(i>n){
            q=q->next;
            //printf("q=%p\n",q);
            /*printf("rev student info:num=%d name=%s age=%d score=%d \n",
                q->stu_num,
                q->stu_name,
                q->stu_age,
                q->stu_score);*/
        }
        p=p->next;
        //printf("p=%p\n",p);
    }

    printf("rev student info:num=%d name=%s age=%d score=%d \n",
           q->stu_num,
          q->stu_name,
          q->stu_age,
          q->stu_score);

    return 0;
}
