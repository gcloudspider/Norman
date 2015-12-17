/*########################################################
##File Name: thread_detach.c
##Created Time:2015年12月17日 星期四 19时36分02秒
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

void *func_thread(void *v){
    int i = 10;
    while(i--){
        printf("%d %s\n",i,(char*)v);
        usleep(1000*500);
    }
    return (void*)100;
}

int main(){
    pthread_t ptid;

    int ret;
    void *rret;

    ret = pthread_create(&ptid,NULL,func_thread,"hello");

    //pthread_detach(ptid);

    getchar();

    printf("Main return!\n");

    return 0;
}
