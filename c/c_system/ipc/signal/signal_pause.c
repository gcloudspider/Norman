/*########################################################
##File Name: signal_pause.c
##Created Time:2015年12月14日 星期一 17时54分53秒
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

void do_sigint(int s){
    printf("hello!\n");
}

int main(int argc,char* argv[]){
    signal(SIGINT,do_sigint);
    printf("getpid()=%d\n",getpid());

    while(1){
        pause();
    }
    return 0;
}
