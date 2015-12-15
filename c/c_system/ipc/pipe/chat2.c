/*########################################################
##File Name: WchatServer.c
##Created Time:2015年12月15日 星期二 13时59分54秒
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
char *receive = "fifo1";
char *send = "fifo2";

int main(){
    int pid;
    int ret;
    int fdr,fds;
    char revbuffer[1024];
    char sendbuf[1024];

    ret = mkfifo(receive,0666);
    if(-1 == ret){
        perror("receive");
    }

    ret = mkfifo(send,0666);
    if(-1 == ret){
        perror("send");
    }

    fdr=open(receive,O_RDWR);
    fds=open(send,O_RDWR);
    pid = fork();
    if(pid > 0){
        while(1){
            //scanf("%s",revbuffer);
            ret=write(fds,"chat2",1024);
            if(-1 == ret){
                perror("write");
            }
            sleep(2);
        }
    } else if(pid ==0){
        while(1){
            printf("help?");
            ret = read(fdr,sendbuf,1024);
            if(-1 == ret){
                perror("read");
            }
            printf("chat1 say:%s\n",sendbuf);
            if(strcmp(sendbuf,"bye")==0)break;
        }
    } else {
        perror("fork");
    }
    return 0;
}
