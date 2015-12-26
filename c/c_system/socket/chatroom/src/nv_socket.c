/*########################################################
##File Name: nv_socket.c
##Created Time:2015年12月26日 星期六 19时25分47秒
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
#include "../include/chatserver.h"

int init_socket(SOCK* sock,const char* ip,int port,int connum){
    int ret;
    int len;
    
    sock->sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sock->sfd){
        perror("socket");
        return -1;
    }

    sock->sin.sin_family = AF_INET;
    sock->sin.sin_port = htons(port);

    if(inet_pton(AF_INET,ip,&sock->sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = bind(sock->sfd,(const struct sockaddr*)&sock->sin,(socklen_t)sizeof(sock->sin));
    if(-1 == ret){
        perror("bind");
        return -1;
    }

    ret = listen(sock->sfd,connum);
    if(-1 == ret){
        perror("listen");
        return -1;
    }
    return 0;
}


