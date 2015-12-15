/*########################################################
##File Name: signal_settimer.c
##Created Time:2015年12月14日 星期一 16时35分44秒
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

void do_alarm(int s){
    printf("It's a goodtime!\n");
}

void do_virtual(int s){
    printf("User:virtual timer!\n");
}

struct itimerval mytimer={
    {3,0},{3,0}
};

struct itimerval virtual={
    {1,1000*500},
    {1,1000*500}
};

int main(){
    int ret;
    
    signal(26,do_virtual);
    //signal(SIGALRM,do_alarm);
    
    //setitimer(ITIMER_REAL,&mytimer,NULL);
    setitimer(ITIMER_VIRTUAL,&virtual,NULL);

    while(1){
        //printf("hello\n");
       // sleep(1);
    }
    
    return 0;
}
