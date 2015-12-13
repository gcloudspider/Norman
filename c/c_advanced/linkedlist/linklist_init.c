/*########################################################
##File Name: linklist_init.c
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

int main(){
    SqList L;
    ElemType e;
    Status i;

    i=InitList(&L);
    printf("初始化L L.length=%d\n",L.length);
}
