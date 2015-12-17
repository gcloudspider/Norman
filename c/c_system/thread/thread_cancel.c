/*########################################################
##File Name: thread_cancel.c
##Created Time:2015年12月17日 星期四 20时09分33秒
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
#include "head.h"

void *func_thread(void *v){
    int i = 10000;
    while((*(int *)v)--){
        printf("%d\n",*(int *)v);
    }

    return (void*)10;
}

int main(){
    pthread_t ptid;
    int ret;
    int i = 10000;

    void *rret;

    ret = pthread_create(&ptid,NULL,func_thread,&i);

    while(1){
        if(i<1000){
            /*由于发送的为信号,不太可靠,线程在接收到信号，
            * 需要处理所以会有时间片问题*/
            pthread_cancel(ptid);       //取消线程，给线程发送终止信号
            break;
        }
    }
    printf("Main return!\n");

    return 0;
}
