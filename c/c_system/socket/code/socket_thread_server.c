/*########################################################
##File Name: socket_thread_server.c
##Created Time:2015年12月21日 星期一 19时28分42秒
##Author: Norman 
##Description:
##
##Issue: 
##              1.互斥锁问题
##              2.链表的添加删除锁问题(保证数据不出错)
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
#define MAXTHREAD 100
//TODO:互斥锁问题 正在couttpid--时或couttpid++时上锁
int couttpid=0;
pthread_t threadid[MAXTHREAD];  //TODO:结构体创建链表
struct sockaddr_in cin;
pthread_mutex_t mutex;

void* func_read(void *v){
    int ret;
    char buf[1024] = {0};
    char bufip[15] = {0};
    struct sockaddr_in tin;
    int len = sizeof(tin);

    //加锁    
    /*
    thread_mutex_lock(&mutex);
    struct sockaddr_in tcin;
    tcin = cin;
    pthread_mutex_unlock(&mutex); //解锁
    */

    while(1){
        ret = read((int)v,buf,1024);
        if(ret <= 0){
            //TODO:客户端断开,线程结束,将消息通知watch
            //pthread_pool_delete(gettid());  //清理线程池
            //printf("disconnected! client ip=%s port=%d\n",inet_ntop(AF_INET,&tcin.sin_addr.s_addr,bufip,15),ntohs(tcin.sin_port));
            ret = getpeername((int)v,(struct sockaddr*)&tin,(socklen_t*)&len);
            if(-1 == ret){
                perror("getpeername");
                break;
            }
            printf("disconnect! client ip=%s port=%d\n",inet_ntop(AF_INET,&tin.sin_addr.s_addr,bufip,15),ntohs(tin.sin_port));
            break;
        }
        write(1,buf,1024);
        write(1,"\n",1);
    }
    return v;
}

int main(int argc ,char *argv[]) {
    int sfd,ret,cfd;
    struct sockaddr_in sin;
    int len;
    char bufip[15] = {0};

    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    //设置结构体的信息
    sin.sin_family = AF_INET;
    sin.sin_port = htons(5002);
    //sin.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY 宏等价于0.0.0.0

    if(inet_pton(AF_INET,"0.0.0.0",&sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    //将结构体与套接字绑定
    ret = bind(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
    if(ret == -1){
        perror("bind");
        return -1;
    }

    //设置监听套接字
    ret = listen(sfd,MAXTHREAD);
    if(ret == -1){
        perror("listen");
        return -1;
    }

    printf("accept...\n");
    pid_t tpid;
    len = sizeof(cin);
    
    pthread_mutex_init(&mutex,NULL);        //初始化锁

    while(1){
        cfd = accept(sfd,(struct sockaddr*)&cin,(socklen_t*)&len);
        if(cfd == -1){
            perror("accept");
            return -1;
        } else {
            printf("connected! client ip=%s port=%d\n",inet_ntop(AF_INET,&cin.sin_addr.s_addr,bufip,15),ntohs(cin.sin_port));
            pthread_create(&threadid[couttpid++],NULL,func_read,(void*)cfd);  //子线程读SOCKET buf
            pthread_detach(threadid[couttpid++]);
            if(couttpid == MAXTHREAD){
                printf("Max Thread! please waitting for release something\n");
            }
        }
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
