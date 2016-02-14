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

#define M 100
#include <stdio.h>
typedef struct{
    int data[M];
    int front,rear;
}queue;

int empty(queue *q){
    if(q->rear == q->front)
        return 1;
    else 
        return 0;
}

int getfront(queue *q){
    int v;
    if(empty(q)){
        printf("empty .\n");
        return 0;
    } else {
        return q->data[(q->front+1)%M];
    }
}

void enqueue(queue *q,int x){
    if(q->front == (q->rear+1)%M){
        printf("full.\n");
        return ;
    }else {
        q->rear = (q->rear+1)%M;
        q->data[q->rear] = x;
    }
}

void dequeue(queue* q){
    if(empty(q)){
        printf("empty .\n");
        return ;
    } else {
        q->front = (q->front +1)%M;
    }
}

int main(){
    queue que,*q;
    int a[5] = {10,20,30,40,50},i;
    q = &que;
    for(i=0;i<5;i++){
        enqueue(q,a[i]);
    }
    i = 4;
    while(!empty(q)){
        a[i--] = getfront(q);
        dequeue(q);
    }
    printf("the array elements is:\n");
    for(i=0;i<5;i++){
        printf("%3d ",a[i]);
    }
}
