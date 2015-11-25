/*########################################################
##File Name: linklist_singlesort.c
##Created Time:2015年11月24日 星期二 16时05分37秒
##Author: Norman 
##Description: 
##
##Issue:   将链表按升序排序 
##
##Analyze: 
##      1.查找最大的节点。
##      2.将该节点从链表中断开
##          2.1:先将head 赋值给一个变量,将head->next 赋值到head
##          2.2:遍历链表判断head == max
##          2.3:是则将p->next = head->next; head->next=NULL
##          2.4:
##      3.将链表头插法插入到new_head中
##      4.将new_head重新赋值给head
##
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

STU* search_max_link_list(STU **head) {
    STU* pn;
    STU* max=*head;
    pn = *head;

    //找到最大的节点
    while(pn) {
        if(pn->stu_num > max->stu_num) {
            max = pn;
        }
        pn= pn->next;
    }
    return max;
}

STU* del_link_list_node(STU **head,STU* new_head,STU* max) {
    STU* p,*q;

    p = *head,q = *head;
    while(p) {
        if(p == max) break;
        q=p;
        p = p->next;
    }
    
    //将max从链表中断开
    if(p) {
        if(p==*head) {
            (*head) = (*head)->next;
        } else {
            q->next=p->next;
        }   
    }

    p->next = new_head;
    new_head = p;
    //printf("new_head=%p",new_head);
    return new_head;
}

void sort_link_list(STU **head) {
    STU *max,*p,*q,*new_head = NULL;
    while(head) {
        if(*head == NULL) break;

        max=search_max_link_list(&*head);
        /*
        p = *head;
        max = *head;
        while(p) {
            if(p->stu_num>max->stu_num) {
                max= p;
            }
            p = p->next;
        }*/
        new_head=del_link_list_node(&*head,new_head,max);
        //TODO: 封装进一步优化 删除和重组分开
        /*
        p =*head;q = *head;
        while(p) {
            if(p == max) break;
            q = p;
            p = p->next;
        }
        
        if(p) {
            if(p==*head) {
                (*head) = (*head)->next;
            } else {
                q->next=p->next;
            }   
        } else
            break;
        p->next = new_head;
        new_head = p;
        */
    }
    *head = new_head;
    return ;
}


int main() {
    STU *pn;
    STU *head = NULL;
    Create_link_list(&head);
    
    printf("Before Sort link list:\n");
    show_link_list(&head);

    printf("link list Sort...\n");
    sort_link_list(&head);

    printf("After Sort link list:\n");
    show_link_list(&head);

    return 0;
}
