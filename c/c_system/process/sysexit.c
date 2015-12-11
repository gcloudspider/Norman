/*########################################################
##File Name: sysexit.c
##Created Time:2015年12月10日 星期四 15时35分05秒
##Author: Norman 
##Description: 
##  1.所有用户空间程序启动都是先有init进程发起
    2.
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
#include<unistd.h>


void bye(){
    printf("that was all ,folks\n");
}

void goodbye(int status,void *arg){
    printf("goodbyed!%d %s\n",status,(char*)arg);
}

void get(){
    int i = 0;
    while(1){
        i++;
        printf("%d\n",i);
        if(i>10){
            exit(0);
        }
    }   
}

int main(){
    
    int ret;
    //ret = atexit(bye);
    char* str = "haha";
    on_exit(goodbye,(void*)str);
    /*
    if(ret !=0){
        fprintf(stderr,"cannot set exit function\n");
        exit(2);
    }
    */
    get();
    
    return 0;
}


