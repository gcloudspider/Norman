/*########################################################
##File Name: point_strcpy.c
##Created Time:2015年12月07日 星期一 15时57分16秒
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
#include<string.h>

typedef struct node{
};

typedef struct hashT{
    char key;
    int num;
    char name[20];
    char sex;
}HashTable,*t;

void Getmemory(char *p){            //局部变量
    p = (char*) malloc(100);
    printf("%p\n",p);
}

void Test(void){
    char *str = NULL;
    Getmemory(str);
    strcpy(str,"hello world");      //拷贝发生段错误
    printf("%s",str);
}

void GetMemory(char** p,int num){
    *p = (char*) malloc(num);
}

void test(void){
    char *str = NULL;
    GetMemory(&str,100);
    strcpy(str,"hello world");
    printf("%s\n",str);
}

int main(){
    //Test();
    printf("%d\n",sizeof(struct node));
    printf("sizof(HashTable)=%d\n",sizeof(HashTable));
    printf("sizof(t)=%d\n",sizeof(t));
    //test();
    return 0;
}
