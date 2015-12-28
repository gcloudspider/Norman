/*########################################################
##File Name: socket_udp_server.c
##Created Time:2015年12月28日 星期一 15时08分21秒
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
#include <netinet/in.h>
#include <arpa/inet.h>
const char* ip = "127.0.0.1";

int main(){
        int sfd, ret,cfd;
        struct sockaddr_in sin;
        struct sockaddr_in cin;
        int len;
        char buf[1024]={0};
        char client[1024] = {0};
        char bufip[15] = {0};

        sfd = socket(AF_INET,SOCK_DGRAM,0);
        if(-1 == sfd){
            perror("socket");
            return -1;
        }

        sin.sin_family = AF_INET;
        sin.sin_port = htons(5002);

        if(inet_pton(AF_INET,"0.0.0.0",&sin.sin_addr.s_addr)<=0){
            perror("inet_pton");
            return -1;
        }

        ret = bind(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
        if(ret == -1){
            perror("bind");
            return -1;
        }

        while(1){
            len = sizeof(cin);
            ret = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&cin,(socklen_t*)&len);
            printf("ip=%s port=%d client connected!\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port));
            write(1,client,strlen(client));
            write(1,buf,ret);
            write(1,"\n",1);
        }
failed:
    close(cfd);
    close(sfd);

    return 0;
}
