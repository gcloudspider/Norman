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
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>

typedef struct student {
    int stu_num;
    char stu_name[64];
    int stu_age;
    int stu_score;
    struct student *next;
}STU;


int main() {
    STU* head= NULL,Tail=NULL;
    STU* pn;
    char ch;

    while(1) {
        //1.申请内存
        //2.初始化pn
        //head->pn
        //pn->next -> 下一个pn指针
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

        head = pn;
        

clear_method:
        ch = getchar();
        if(ch == 'n' || ch=='N') {
            break;
        } else if(ch == '\n'|| ch == 'y' || ch == 'Y') {
            continue;
        } else{
            goto clear_method
        }

    }

    while(1) {
        

    }

    return 0;
}
