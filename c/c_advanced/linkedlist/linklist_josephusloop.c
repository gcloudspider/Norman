/*#######################################################
##File Name: linklist_singleloop.c
##Created Time:2015年11月24日 星期二 19时08分04秒
##Author: Norman 
##Description: 约瑟夫环(Josephus)
##
##Issue: 用户输入M,N值 ，从1至N开始顺序循环数,每数到M输出该数值,直到全部输出
##
##Analyze: N个元素循环链表,从链表头开始遍历并记数,如果计数i==m踢出元素,##继续循环,当当前元素与下一元素相同时退出循环
##
##Induction:
##
##Summary:
##      1.遍历元素
##      2.
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

int Create_link_list(STU** head) {
    STU *pn;
    char ch;

    while(1){
        pn = malloc(sizeof(STU));
        if(pn == NULL) {
            printf("malloc error !\n");
            return -1;
        }
        
        scanf("%d%s%d%d",
             &pn->stu_num,
             pn->stu_name,
             &pn->stu_age,
             &pn->stu_score
             );

        while((ch=getchar())!='\n');
        pn->next = *head;
        *head = pn;
        printf("is continue ? please input yes or no(Y/N): ");
clear_enter:
        ch = getchar();
        if(ch=='n'||ch=='N') {
            break;
        } else if(ch == 'y'|| ch=='Y'|| ch== '\n') {
            continue;
        } else {
            goto clear_enter;
        }
    }
    
    return 0;
}

void show_link_list(STU **head) {
    STU *pn;
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
    return ;
}


int main() {
    STU* pn;
    STU *head = NULL;
    Create_link_list(&head);
    show_link_list(&head);

    return 0;
}
