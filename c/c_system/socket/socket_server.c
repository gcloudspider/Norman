/*########################################################
##File Name: socket_server.c
##Created Time:2015年12月21日 星期一 15时08分21秒
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

int main(){
        int sfd, ret,cfd;
        struct sockaddr_in sin;
        struct sockaddr_in cin;
        int len;
        char buf[1024]={0};
        char bufip[15] = {0};

        sfd = socket(AF_INET,SOCK_STREAM,0);
        if(-1 == sfd){
            perror("socket");
            return -1;
        }

        sin.sin_family = AF_INET;
        sin.sin_port = htons(5000);

        if(inet_pton(AF_INET,"192.168.1.15",&sin.sin_addr.s_addr)<=0){
            perror("inet_pton");
            return -1;
        }

        ret = bind(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
        if(ret == -1){
            perror("bind");
            return -1;
        }

        ret = listen(sfd,30);
        if(ret == -1){
            perror("listen");
            return -1;
        }

        printf("accept...\n");
        pid_t pid;
        len = sizeof(cin);

        while(1){
            cfd = accept(sfd,(struct sockaddr*)&cin,(socklen_t*)&len);
            if(cfd == -1){
                perror("accept");
                return -1;
            } else {
                pid = fork();
                if(pid>0) continue;
                else if(pid == -1){
                    perror("fork");
                    continue;
                } else {
                    printf("client IP = %s\n",inet_ntop(AF_INET,&cin.sin_addr.s_addr,bufip,15));
                    printf("client port = %d\n",ntohs(cin.sin_port));
                    while(1){
                        ret = read(cfd,buf,1024);
                        if(ret <=0){
                            printf("ip=%s port=%d client disconnect!\n",inet_ntop(AF_INET,&cin.sin_addr.s_addr,bufip,15),ntohs(cin.sin_port));
                            goto failed;
                        }
                        write(1,buf,1024);
                        write(1,"\n",1);
                    }
                }
            }
        }
failed:
    close(cfd);
    close(sfd);

    return 0;
}
