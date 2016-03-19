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

/*协议*/
typedef unsigned char u8;
typedef unsigned char u16;
typedef unsigned char u32;

enum msgtype{
    LOGINTYPE = 1,
    TEXTTYPE = 2,
    FILETYPE = 3,
    IMAGETYPE = 4
};

struct msghead{
    u8  msgtype;
    u8  version;
    u16 length;
};

struct chat{
    char msgbody[1024];
};

struct login{
    char name[64];
    char passwd[128];
};

struct file{
    char filename[64];
    char filemd5[128];
};

struct image{
    char imagename[64];
    char imagemd5[128];
};

union body{
    struct login login;
    struct chat wchat;
    struct file file;
    struct image image;
};

struct package{
    struct msghead msghead;
    union body body;
};

/////////////////////////////

void* thread_read(void* argv){
    int sfd = (int)argv;
    int ret;
    char buf[1024] = {0};
    struct package p;
    while(1){
        ret = read(sfd,&p.msghead,sizeof(p.msghead));
        if(p.msghead.msgtype == 1){
            ret = read(sfd,buf,p.msghead.length);
            write(1,"server:",strlen("server:"));
            write(1,buf,p.msghead.length);
        } else {
            printf("error format!\n");
        }
    }
    return argv;
}

void* thread_write(void* argv){
    int sfd = (int) argv;
    int ret;
    char buf[1024] = {0};
    struct package p;
    while(1){
        ret = read(0,buf,1024);
        buf[ret] =0;
        p.msghead.msgtype = buf[0]-'0';
        p.msghead.version=1;
        p.msghead.length = strlen(buf)-1;
        write(sfd,&p.msghead,sizeof(p.msghead));
        write(sfd,&buf[1],p.msghead.length);
    }
    return argv;
}

//客户端发送心跳包

void* thread_heart(void* argv){
    int sfd = (int)argv;

    struct msghead head;
    
    head.msgtype = 6;
    head.length = 0;
    while(1){
        sleep(1);
        write(sfd,&head,sizeof(head));
    }
    
    return argv;
}

int main(int argc,char* argv[]){
    int sfd,ret;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    int len;
    char buf[1024]= {0};
    struct package p;
    pthread_t tid01,tid02,tid03; //heartbeat线程id
    void* rret;

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

    pthread_create(&tid01,NULL,thread_read,(void*)sfd);
    pthread_create(&tid02,NULL,thread_write,(void*)sfd);
    pthread_create(&tid03,NULL,thread_heart,(void*)sfd);  //新增线程监控心跳包

    pthread_join(tid01,&rret);
    pthread_join(tid02,&rret);
    pthread_join(tid03,&rret); //等待线程

    close(sfd);

    return 0;
}
