/*########################################################
##File Name: linklist_chileNode.c
##Created Time:2015年12月07日 星期一 08时52分16秒
##Author: Norman 
##Description: 双向多层链表,节点中有子节点，将子节点排成一列,然后还能还原回去
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

typedef struct MultiNode{
    struct MultiNode *next;
    struct MultiNode *pre;
    struct MultiNode *child;
    int value;
}MN;

int main(){
    MN *head=NULL,*tail=NULL;
    MN *pn,*preNode=NULL;
    int tag=0;
    char ch;

    while(1){

        pn = malloc(sizeof(MN));
        if(pn == NULL) {
            printf("malloc error!");
            return -1;
        }
        printf("please input value: ");
        scanf("%d",&pn->value);
        
        if(head) {
            if(tag == 1){
                pn->next = NULL;
                pn->pre = preNode;
                pn->child = NULL;
            } else {

            }
        } else {
            pn->next = NULL;
            pn->pre = NULL;
            pn->child = NULL;
            head = pn;
        }

        preNode = pn;
        while((ch = getchar())!='\n');
        printf("is continue add child ?\n");
        ch= getchar();
        if(ch == 'y'||ch == 'Y'){
            tag = 1;
        } else {
            tag = 0;
        }
    }

    return 0;
}

