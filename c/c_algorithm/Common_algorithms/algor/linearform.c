/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//线性顺序表
//
#define ListSize 100
#include<stdio.h>
#include<stdlib.h>
struct Seqlist{
    int data[ListSize];
    int length;
};


void InsertList(struct Seqlist *L,int x,int i){
    int j;
    if(i<0 || i> L->length){
        puts("position error");
        exit(0);
    }

    if(L->length >= ListSize){
        puts("overflow");
        exit(0);
    }

    for(j=L->length-1;j>=i;j--)
        L->data[j+1] = L->data[j];
    L->data[i] = x;
    L->length++;
}

void DeleteList(struct Seqlist *L,int i){
    int j;
    if(i<0 || i> L->length){
        puts("position error");
        exit(0);
    }

    for(j=i+1;j<L->length;j++){
        L->data[j-1] = L->data[j];
        L->length--;
    }
}

void Initlist(struct Seqlist *L){
    L->length = 0;
}

int main(){
    struct Seqlist s;
    int i=0,k;
    Initlist(&s);
    printf("input data: ");
    do{
        scanf("%d",&k);
        if(k==0) break;
        InsertList(&s,k,i);
        printf("%d ",s.data[i++]);
    }while(1);
    printf("\n");
    printf("delete element: \n");
    scanf("%d",&k);
    DeleteList(&s,k);
    printf("output sequeue list: \n");
    for(i=0;i<ListSize-1;i++){
        printf("%d ",s.data[i]);
    }
}
