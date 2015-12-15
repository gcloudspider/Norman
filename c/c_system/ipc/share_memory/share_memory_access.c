/*########################################################
##File Name: share_memory_access.c
##Created Time:2015年12月15日 星期二 19时48分46秒
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
#include"head.h"

int main(){
    int id,ret;
    char *p;

    id = shmget(6000,1024,IPC_CREAT|0666);
    p = shmat(id,NULL,0);

    printf("p = %s\n",p);
    return 0;
}
