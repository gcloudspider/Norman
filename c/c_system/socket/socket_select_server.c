/*########################################################
##File Name: socket_select_server.c
##Created Time:2015年12月23日 星期三 11时11分23秒
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
   int sfd,ret,cfd;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    fd_set set,rset;    //1.定义结构体
    char buf[1024] = {0};

    sfd=socket(AF_INET,SOCK_STREAM,0);
    if(sfd == -1){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(5000);
    if(inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr.s_addr)<=0){
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

    FD_ZERO(&set);      //2.初始化集合置0
    FD_SET(sfd,&set);   //3.将sfd文件描述符添加到集合中
    rset = set;         //4.备份集合
    int max = sfd+1;
    int nfound,len,i;
    len = sizeof(sin);
    while(1){
        set = rset;
        nfound = select(max,&set,NULL,NULL,NULL);  //5.监控集合中要处理个数
        if(nfound <0){
            perror("select");
            continue;
        } else if(nfound == 0){
            printf("timeout!\n");
            continue;
        } else {
            if(FD_ISSET(sfd,&set)){  //6.判断该文件描述符是否在集合中
                cfd = accept(sfd,(struct sockaddr*)&cin,(socklen_t*)&len);
                if(-1 == cfd){
                    perror("accept");
                    continue;
                }
                FD_SET(cfd,&rset);
                max = cfd+1;
            }
            for(i=sfd+1;i<max;i++){
                if(FD_ISSET(i,&set)){
                    ret = read(cfd,buf,1024);
                    if(ret <=0){
                        printf("client disconnect!\n");
                        goto failed;
                    }
                    write(1,buf,ret);
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
