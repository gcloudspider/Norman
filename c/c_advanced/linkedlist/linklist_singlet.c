/*########################################################
##File Name: linklist_singlet.c
##Created Time:2015年11月23日 星期一 14时05分52秒
##Author: Norman 
##Description: 尾插法
##
##Issue: 
##
##Analyze: 
##
##      算法分析:
##          创建表,读入数据,生成新结点
##          将新结点插入到当前链表的表尾结点之后
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
    STU* head= NULL,*Tail=NULL;
    STU *pn;
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
        if(head == NULL) {
            head = pn;
        } else {
            if(Tail->next == NULL) {
                Tail->next = pn;
            }
        }

        pn->next = NULL;
        Tail=pn;

        printf("is continue? please input yes or no(Y/N): ");
clear_method:
        ch = getchar();
        if(ch == 'n' || ch=='N') {
            break;
        } else if(ch == '\n'|| ch == 'y' || ch == 'Y') {
            continue;
        } else{
            goto clear_method;
        }

    }

    pn = head;
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

    return 0;
}
