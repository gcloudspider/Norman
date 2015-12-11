/*########################################################
##File Name: sysfork2.c
##Created Time:2015年12月10日 星期四 20时09分25秒
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
#include<unistd.h>

int main(){
    int i=0;
    printf("i son/pa ppid pid fpid\n");
    for(i=0;i<2;i++){
        pid_t fpid = fork();

        if(fpid ==0){
            printf("%d child %4d %4d %4d\n",i,getppid(),getpid(),fpid);
        } else {
            printf("%d parent %4d %4d %4d\n",i,getppid(),getpid(),fpid);
        }
    }
    return 0;
}
