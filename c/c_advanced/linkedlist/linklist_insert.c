/*########################################################
##File Name: linklist_insert.c
##Created Time:2015年12月13日 星期日 19时28分57秒
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

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 2015
typedef int ElemType;
typedef int Status;

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;


Status InitList(SqList *L){
    L->length  =0;
    return OK;
}

SqList Create(SqList L){
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<10;i++){
        L.data[i] = rand()%100;
        L.length++;
    }
    return L;
}

Status print(ElemType c){
    printf("%d\t",c);
    return OK;
}

Status ListTraverse(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        print(L.data[i]);
    }
    printf("\n");
    return OK;
}

Status ListInsert(SqList *L,int i,ElemType e){
    int k;
    if(L->length == MAXSIZE)
        return ERROR;
    if(i<1 || i>L->length+1)
        return ERROR;

    if(i<=L->length){
        for(k=L->length-1;k>=i-1;k--){
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;

    return OK;
}

int main(){
    SqList L;
    ElemType e;
    Status i;
    char opp;
    int j,k;
    int pos;
    ElemType value;

    i=InitList(&L);
    printf("初始化L L.length=%d\n",L.length);
    printf("\n1.遍历线性表 \n2.线性表赋值 \n3.线性表插入\n0.退出\n请选择你的操作:\n");
    while(opp != '0'){
        scanf("%c",&opp);
        switch(opp){
            case '1':
                ListTraverse(L);
                printf("\n");
                break;
            case '2':
                L = Create(L);
                printf("在L的表头依次插入1~5后:L.data=");
                ListTraverse(L);
                printf("\n");
                break;
            case '3':
                printf("请输入插入元素位置:");
                scanf("%d",&pos);
                printf("请输入插入元素的值:");
                scanf("%d",&value);
                i = ListInsert(&L,pos,value);
                printf("插入完毕,现在线性表为:\n");
                ListTraverse(L);
                printf("\n");
                break;
            case '0':
                exit(0);
                break;
            default:
                break;
        }
    }
}
