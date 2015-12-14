/*########################################################
##File Name: singnal.c
##Created Time:2015年12月14日 星期一 14时57分38秒
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

/*函数指针*/
typedef void(*sighandler_t)(int);

void do_signal(int n){
    printf("haha\n");
    exit(0);
}

sighandler_t killsignal = do_signal;

int main(){
    while(1){
        signal(2,killsignal);
        printf(".");
        fflush(stdout);
        usleep(1000*50);
    }
    
    return 0;
}
