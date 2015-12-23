/*########################################################
##File Name: socket_thread_pool.c
##Created Time:2015年12月22日 星期二 17时28分42秒
##Author: Norman 
##Description:  
##              1.初始化 创建线程池并线程处于阻塞状态，等待条件变量激活线程
##              2.任务添加到队列，发出一个信号，激活线程
##              3.线程取出队列中任务
##              4.将函数地址传给线程，让线程执行该函数
##
##Issue: 
##              1.释放问题
##              2.不同任务处理问题
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

typedef void*(*THING)(void* argv);
//任务队列
typedef struct work{
    THING thing;
    void* argv;
    struct work *next;
}QWORK;

//
typedef struct{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int max_thread_num;
    pthread_t thread_id[MAXTHREAD];
    QWORK* qhead;
    QWORK* qtail;
}TD;

TD td;

void* do_something(void* argv){
    QWORK* pwork = NULL;
    while(1){
        pwork = NULL;
        //2.线程阻塞等待任务
        pthread_mutex_lock(&td.mutex);
        pthread_cond_wait(&td.cond,&td.mutex);
        printf("thread %ld actived!\n",gettid());
        
        //队列先进先出(从头取,尾插入)
        if(td.qhead){
            pwork = td.qhead;
            if(td.qhead == td.qtail){
                td.qhead = td.qtail = NULL;
            } else {
                td.qhead = td.qhead->next;
            }
        }
        pthread_mutex_unlock(&td.mutex);
        //从队列中取出后执行函数
        if(pwork)
            pwork->thing(pwork->argv);

        //任务完成后!释放任务!
        printf("thread %ld release work address:%p !\n",gettid(),pwork);
        free(pwork);
        //pthread_pool_release(pwork);
    }
    return argv;
}

void pthread_pool_init(){
    //初始化锁和条件变量
    pthread_mutex_init(&td.mutex,NULL);
    pthread_cond_init(&td.cond,NULL);
    td.max_thread_num = MAXTHREAD;
    td.qhead = NULL;
    td.qtail = NULL;
    int i;
    //1.创建线程池(将线程创建好)
    for(i=0;i<td.max_thread_num;i++){
        pthread_create(&td.thread_id[i],NULL,do_something,NULL);
        pthread_detach(td.thread_id[i]);
    }
}

void pthread_pool_release(QWORK* work){
    printf("thread %ld release!\n",gettid());
    free(work);
}

//添加任务到队列中
void pool_add_work(THING thing,void* argv){
    QWORK* pwork = malloc(sizeof(QWORK));
    printf("malloc wrok address:%p \n",pwork);
    pwork->thing = thing;
    pwork->argv = argv;
    pthread_mutex_lock(&td.mutex);
    //添加到队列中
    if(td.qhead){
        td.qtail->next = pwork;
        td.qtail = pwork;
    } else {
        td.qtail = pwork;
        td.qhead = td.qtail;
    }
    pthread_mutex_unlock(&td.mutex);
    pthread_cond_signal(&td.cond);
}

void *thread(void *argv){
    struct sockaddr_in tcin;
    int cfd = (int) argv;
    char buf[1024] = {0};
    int ret;
    int len = sizeof(tcin);
    
    getpeername(cfd,(struct sockaddr*)&tcin,(socklen_t*)&len);
    printf("client ip=%s,port=%d\n",inet_ntop(AF_INET,&tcin.sin_addr.s_addr,buf,15),ntohs(tcin.sin_port));
    while(1){
        ret = read(cfd,buf,1024);
        if(ret <=0){
            printf("client ip=%s,port=%d disconnect\n",inet_ntop(AF_INET,&tcin.sin_addr.s_addr,buf,15),ntohs(tcin.sin_port));
            goto failed;
        }
        write(1,buf,ret);
        write(1,"\n",1);
    }
failed:
    close(cfd);
    return argv;
}

int main(int argc ,char *argv[]) {
    int sfd,ret,cfd;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
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
    sin.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY 宏等价于0.0.0.0


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
    
    pthread_pool_init();

    while(1){
        cfd = accept(sfd,(struct sockaddr*)&cin,(socklen_t*)&len);
        if(cfd == -1){
            perror("accept");
            return -1;
        } else {
            //3.添加任务到队列中
            pool_add_work(thread,(void*)cfd);  
        }
    }
    
    close(sfd);

    return 0;
}
