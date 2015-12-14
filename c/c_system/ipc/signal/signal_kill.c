/*########################################################
##File Name: signal_kill.c
##Created Time:2015年12月14日 星期一 15时21分31秒
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

int main(int argc,char* argv[]){
    int pid;
    int i=5;
    if(argc>1 && argc < 3) return -1;
    
    if(argc == 1){
        while(i--){
            printf("%d\n",i);
        }
        //raise(9);     //用户态中断,显示已杀死
        abort();    //内核态中中断，显示核心转储
    }
    

    kill(atoi(argv[2]),atoi(&argv[1][1]));
    return 0;
}

