/*########################################################
##File Name: socket_client.c
##Created Time:2015年12月21日 星期一 15时49分12秒
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

int main(){
    int sfd,ret;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    int len;
    char buf[1024]= {0};

    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(sfd == -1){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(5000);

    if(inet_pton(AF_INET,"192.168.1.15",&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = connect(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(ret == -1){
        perror("connect");
        return -1;
    }

    printf("intput anykey to send\"1234567890\" to server....\n");
    getchar();
    write(sfd,"1234567890",10);

    close(sfd);

    return 0;
}
