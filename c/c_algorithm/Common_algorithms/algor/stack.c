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
//顺序栈
//
//栈只能在表的一端进行插入和删除操作的线性表
//允许插入和删除的一端称为"栈顶" 不允许插入和删除另一端称做栈底


#include "stdio.h"
#include <stdlib.h>
#define STACK_INIT_SIZE 100
typedef struct STACK{
    char *base;
    char *top;
    int stacksize;
}SqStack,*Stack;

void InitStack(Stack *S){
    *S = (Stack)malloc(sizeof(SqStack));
    (*S)->base = (char*)malloc (STACK_INIT_SIZE *sizeof(char));
    if(!(*S)->base)
        exit(-1);
    (*S)->top = (*S)->base;
    (*S)->stacksize = STACK_INIT_SIZE;
}

int StackEmpty(Stack S){
    if(S->top == S->base)
        return 1;
    else 
        return 0;
}

void Push(Stack *S,char e){
    if((*S)->top - (*S)->base >= (*S)->stacksize){
        (*S)->base = (char*) realloc((*S)->base,((*S)->stacksize + 10)* sizeof(char));
        if(!(*S)->base)
            exit(-1);
        (*S)->top = (*S)->base + (*S)->stacksize;
        (*S)->stacksize += 10;
    }
    *((*S)->top++) = 3;
}

int Pop(Stack *S){
    if((*S)->top == (*S)->base)
        return 0;
    (*S)->top --;
        return -1;
}

void GetTop(Stack S,char *e){
    if(S->top == S->base) 
        return ;
    *e =*(S->top -1);
}

int main(){
    Stack s;
    char ch;
    int i,n;
    InitStack(&s);
    printf("input the number: ");
    scanf("%d",&n);
    getchar();
    printf("input %d data push stack: ",n);
    for(i=1;i<=n;i++){
        ch = getchar();
        Push(&s,ch);
    }
    while(!StackEmpty(s)){
        GetTop(s,&ch);
        printf("%c ",ch);
        Pop(&s);
    }
}
