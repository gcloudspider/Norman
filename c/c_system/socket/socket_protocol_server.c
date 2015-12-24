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
#define MAXTHREAD 10
#define gettid() syscall(__NR_gettid)
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

///////////////////////////////////////
typedef void*(*FUNC_POINT)(void* argv);
typedef struct tasklist{
    FUNC_POINT function;
    void* argv;
    struct tasklist *next;
}QTASKLIST;

typedef struct{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int max_thread_num;
    pthread_t thread_id[MAXTHREAD];
    QTASKLIST* qhead;
    QTASKLIST* qtail;
}TD;

TD td;


//线程等待着wakeup
void* wait_wakeup(void* argv){
    QTASKLIST* ptask = NULL;
    while(1){
        ptask = NULL;
        pthread_mutex_lock(&td.mutex);
        pthread_cond_wait(&td.cond,&td.mutex);

        //线程监控队列,若有任务未处理,自己处理。没有任务回到等待唤醒状态
        while(1){
            printf("thread id:%ld actived!\n",gettid());
            if(td.qhead){
                ptask = td.qhead;
                if(td.qhead == td.qtail){
                    td.qhead = td.qtail = NULL;
                } else {
                    td.qhead = td.qhead->next;
                }
            } else {
                break;
            }
            pthread_mutex_unlock(&td.mutex);
            if(ptask){
                ptask->function(ptask->argv);
                printf("thread id:%ld release work address:%p!\n",gettid(),ptask);
                free(ptask);
            }
        }   
    }
    return argv;
}

void pthread_pool_init(){
    int i;
    pthread_mutex_init(&td.mutex,NULL);
    pthread_cond_init(&td.cond,NULL);
    td.max_thread_num = MAXTHREAD;
    td.qhead = NULL;
    td.qtail = NULL;
    for(i=0;i<td.max_thread_num;i++){
        pthread_create(&td.thread_id[i],NULL,wait_wakeup,NULL);
        pthread_detach(td.thread_id[i]);
    }
}

void pool_add_work(FUNC_POINT function,void* argv){
    QTASKLIST* ptask = malloc(sizeof(QTASKLIST));
    printf("malloc task address:%p\n",ptask);
    ptask->function = function;
    ptask->argv = argv;
    pthread_mutex_lock(&td.mutex);
    if(td.qhead){
        td.qtail->next = ptask;
        td.qtail = ptask;
    } else {
        td.qtail = ptask;
        td.qhead = td.qtail;
    }
    pthread_mutex_unlock(&td.mutex);
    pthread_cond_signal(&td.cond);
}

void *wchat_robot(void* argv){
    struct sockaddr_in tcin;
    int cfd = (int) argv;
    int ret;
    char buf[1024] = {0};
    int len = sizeof(tcin);

    getpeername(cfd,(struct sockaddr*)&tcin,(socklen_t*)&len);
    printf("client ip=%s,port=%d connected!\n",inet_ntop(AF_INET,&tcin.sin_addr.s_addr,buf,15),ntohs(tcin.sin_port));
    while(1){
        ret = read(cfd,buf,1024);
        if(ret <= 0){
            printf("client ip=%s,port=%d\n disconnect",inet_ntop(AF_INET,&tcin.sin_addr.s_addr,buf,15),ntohs(tcin.sin_port));
            goto failed;
        }
        write(1,buf,ret);
        write(1,"\n",1);
    }
failed:
    close(cfd);
    return argv;
}

void* upload_file(void* argv){
    printf("starting upload file...!\n");
    return argv;
}

void* download_file(void* argv){
    printf("starting download file...!\n");
    return argv;
}

void parse_buf(const char* buf,char* buffer){
    int i=1,j;
    j=strlen(buf) -1;
    while(isspace(buf[i])&&(i<=j)){
        i++;
        if(0<i)
            strcpy(buffer,&buf[i]);
    }
    return ;
}

void handle_buf(const char* buf,int cfd){
    char ch;
    ch = buf[0];
    int ret;
    char* buffer;

    switch(ch){
        case '1':{
            parse_buf(buf,buffer);
            ret = strlen(buffer);
            write(1,buffer,ret);
            write(1,"\n",1);
            break;
        }
        case '2':
            pool_add_work(wchat_robot,(void*)cfd);
            break;
        case '3':
            pool_add_work(upload_file,(void*)cfd);
            break;
        case '4':
            pool_add_work(download_file,(void*)cfd);
            break;
        default:
            printf("Unknow data!\n");
            break;
    }
}


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

    eh = epoll_create(8000);            //创建一个poll 实例
    if(-1 == eh){
        perror("epoll_create");
        return -1;
    }

    len=sizeof(sin);
    ev.data.fd = sfd;
    ev.events = EPOLLIN|EPOLLET;            //EPoll 事件 read 读操作
    epoll_ctl(eh,EPOLL_CTL_ADD,sfd,&ev);    //注册文件描述符sfd 到poll实例

    pthread_pool_init();

    while(1){
        nfound = epoll_wait(eh,evs,10,-1);  
        if(nfound < 0){
            perror("epoll_wait");
            continue;
        } else if(nfound ==0 ){
            printf("time out!\n");
            continue;
        } else {
            for(i=0;i<nfound;i++){
                if(evs[i].data.fd == sfd){
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
                        handle_buf(buf,cfd);
                    }
                }
            }
        }
    }
failed:
    close(sfd);
    return 0;
}
