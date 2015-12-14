/*########################################################
##File Name: signal_alarm.c
##Created Time:2015年12月14日 星期一 17时50分02秒
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
void do_alarm(int s){
    printf("It's a goodtime!\n");
    alarm(3);
}

int main(){
    signal(SIGALRM,do_alarm);   //注册实时信号
    alarm(3);                   //设置当前开启计时

    while(1){
        printf("hello\n");
        sleep(1);
    }
    return 0;
}
