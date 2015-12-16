/*########################################################
##File Name: thread_create.c
##Created Time:2015年12月16日 星期三 14时31分03秒
##Author: Norman 
##Description: 
##          1.主线程创建文件
##          2.子线程删除文件
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
int flag = 0;

void call_back(int s){
    static int a = 0;
    char file[1024] = {0};
    a++;
    if(a<=30){
        sprintf(file,"file_%d",a);
        creat(file,0666);
        printf("create file %s success!\n",file);
    }
    if(a%2==0){
        flag = 1;
    }
    alarm(1);
}

void* thread_del_file(void* v){
    int i;
    char file[1024];
    int ret;
    
    while(i<=30){
        if(flag){
            flag = 0;
        sprintf(file,"file_%d",i);
        remove(file);
        printf("remove file %s success\n",file);
        i++;
        }   
    }
    return v;
}

int main(){
    pthread_t threadid;
    int f,ret;
    void *rret;
    char name[20];

    pthread_create(&threadid,NULL,thread_del_file,NULL);

    signal(SIGALRM,call_back);
    alarm(1);
    int i = 30;
    while(i--){
        pause();
    }

    pthread_join(threadid,&rret);
    return 0;
}
