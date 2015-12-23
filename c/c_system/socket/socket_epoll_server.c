/*########################################################
##File Name: socket_epoll_server.c
##Created Time:2015年12月23日 星期三 15时22分21秒
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
    int eh,nfound,max=10;
    int len,i;
    struct epoll_event ev,evs[10];
    char buf[1024] = {0};

    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(5002);
    if(inet_pton(AF_INET,"127.0.0.1",&sin.sin_addr.s_addr) <= 0){
        perror("inet_pton");
        return -1;
    }

    ret = bind(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(ret == -1){
        perror("bind");
        return -1;
    }

    ret = listen(sfd,30);
    if(-1 == ret){
        perror("listen");
        return -1;
    }

    eh = epoll_create(8000);            //创建一个poll 实例,
                                        //这个文件描述符用于后面所有的调用
    if(-1 == eh){
        perror("epoll_create");
        return -1;
    }

    len=sizeof(sin);
    printf("socket file discript id:%d\n",sfd);
    ev.data.fd = sfd;
    ev.events = EPOLLIN|EPOLLET;            //EPoll 事件 read 读操作
    epoll_ctl(eh,EPOLL_CTL_ADD,sfd,&ev);    //注册文件描述符sfd 到poll实例

    while(1){
        //轮循I/O事件返回evs 数组要处理的
        //nfound 事件总数
        printf("epoll waiting!!\n");
        nfound = epoll_wait(eh,evs,10,-1);  
        if(nfound < 0){
            perror("epoll_wait");
            continue;
        } else if(nfound ==0 ){
            printf("time out!\n");
            continue;
        } else {
            printf("get event evs[%d]\n",nfound);
            for(i=0;i<nfound;i++){
                //判断队列中是事有sfd该文件描述符的事件
                printf("event fd:%d\n",evs[i].data.fd);
                if(evs[i].data.fd == sfd){
                    printf("begin accept!!\n");
                    cfd = accept(sfd,(struct sockaddr*)&cin,(socklen_t*)&len);
                    if(-1 == cfd){
                        perror("accept");
                        continue;
                    }else {
                        ev.data.fd = cfd;
                        ev.events  = EPOLLIN|EPOLLET;
                        epoll_ctl(eh,EPOLL_CTL_ADD,cfd,&ev);
                        continue;
                    }
                } else {
                    ret = read(evs[i].data.fd,buf,1024);
                    if(ret <=0){
                        printf("cfd=%d close!\n",evs[i].data.fd);
                        close(evs[i].data.fd);
                        ev.data.fd = evs[i].data.fd;
                        epoll_ctl(eh,EPOLL_CTL_DEL,evs[i].data.fd,&ev);
                    } else {
                        write(1,buf,ret);
                        write(1,"\n",1);
                    }
                }
            }
        }
    }
failed:
    close(sfd);
    return 0;
}
