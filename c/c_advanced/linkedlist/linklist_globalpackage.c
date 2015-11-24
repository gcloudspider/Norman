/*########################################################
##File Name: linklist_package.c
##Created Time:2015年11月23日 星期一 19时11分23秒
##Author: Norman 
##Description: 全局变量方式
##
##      1.创建链表
##      2.增加链表
##      3.查找链表
##      4.删除链表
##      5.修改链表
##      6.释放链表
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
    struct student *next;
}STU;

STU* head = NULL;

void create_link_list() {
    STU* pn;
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

        pn->next = head;
        head = pn;
        while((ch = getchar())!='\n');

        printf("is continue? please input yes or no(Y/N): ");
clear_enter:
        ch = getchar();
        if(ch == 'n'||ch== 'N')
            break;
        else if(ch == 'y' || ch== 'Y' || ch=='\n')
            continue;
        else
            goto clear_enter;
    }
    return ;
}

void show_link_list() {

    STU *pn;
    pn=head;
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


int insert_link_list(STU* pn) {
    if(pn == NULL) return -1;
    pn->next = head;
    head = pn;
    return 0;
}

void release_link_list() {
    STU *pn;

    while(head) {
        pn=head->next;
        free(head);
        head = pn;
    }
    return ;
}

STU* search_link_list() {
    STU* pn;
    pn=head;
    STU* pm;
    int max=0;
    while(pn) {
        if(pn->stu_score>max){
            max = pn->stu_score;
            pm = pn;
        }
        pn = pn->next;
    }
    
    return pm;
}

print_max_score(int score) {
    STU* pn;
    pn = head;

    while(pn) {
        if(pn->stu_score == score) {
            printf("num=%d\tname=%s\tage=%d\tscore=%d\n",
                pn->stu_num,
                pn->stu_name,
                pn->stu_age,
                pn->stu_score
            );
        }
        pn=pn->next;
    }
}

int main() {

    create_link_list();

    printf("insert link list:\n");
    STU* pn;
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

    insert_link_list(pn);

    show_link_list();
    
    printf("search score max user info\n");

    STU* pm;
    pm=search_link_list();

    print_max_score(pm->stu_score);

    release_link_list();

    return 0;
}
