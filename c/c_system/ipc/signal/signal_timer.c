/*########################################################
##File Name: signal_timer.c
##Created Time:2015年12月14日 星期一 20时24分24秒
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

void mysleep(int i){
    int pid;
    pid=getpid();
    signal(SIGSTOP,)
    while(1){
        pause();
    }

}

int main(){
    int pid;
    int i;
    char name[1024];

    pid = fork();
    if(pid > 0){
        for(i=0;i<30;i++){
            mysleep(1);
            sprintf(name,"file_%d",i);
             ret = creat(name,0666);
            if(-1 == ret){
                perror("creat");
            } else {
                printf("create file %s success\n",name);
            }
        }        
    } else if(pid ==0){
        for(i=1;i<30;i++){
            mysleep(2);
            sprintf(name,"file_%d",i);
            ret = remove(name);
            if(-1 == ret){
                perror("remove");
            } else {
                printf("delete file %s success\n",name);
            }
        }   
    } else {
        perror("fork");
        return pid;
    }

    return 0;
}
