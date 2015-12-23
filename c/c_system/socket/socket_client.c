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
    sin.sin_port = htons(5002);

    if(inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = connect(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(ret == -1){
        perror("connect");
        return -1;
    }

    printf("connect OK!\n");
    while(1){
        printf("input:\n");
        ret = read(0,buf,1024);
        buf[ret] = 0;
        printf("send to \n");
        write(sfd,buf,ret);
    }
    close(sfd);

    return 0;
}
