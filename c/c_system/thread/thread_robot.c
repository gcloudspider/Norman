/*########################################################
##File Name: thread_robot.c
##Created Time:2015年12月17日 星期四 21时41分09秒
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

enum{
    SERVER = 1
    CLIENT = 2
};


#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
pthread_rwlock_t rwmutex1;
pthread_rwlock_t rwmutex2;

void usage(const char* proname){
    fprintf(stderr,"Usage:%s [-s server] [-c client]\n",proname);
    exit(2);
}

//创建监听收到的数据
void create_pipe_file(const char* name){
    int ret;
    ret = mkfifo(name,0666);
    if(-1 == ret){
        perror("mkfifo");
    }
}

void* func_readfile(void *v){
    printf("%d\n",(int*)v);
    if((int*)v == SERVER?SERVER:CLIENT){
        while(1){
            sleep(1);
            printf("server mode read file!\n");
            //pthread_rwlock_rdlock()
        }
    } else {
        while(1){
            sleep(1);
            printf("client mode read file!\n");
            //pthread_rwlock_rdlock()
        }
    }

}

void* func_writefile(void *v){
    if((int*)v == SERVER?SERVER:CLIENT){
        while(1){
            sleep(1);
            printf("sever mode write file!\n");
            //pthread_rwlock_rdlock()
        }
    }else {
        while(1){
            sleep(1);
            printf("client mode write file!\n");
            //pthread_rwlock_rdlock()
        }
    }
}


//服务端模式
void server_mode(){
    pthread_t ptid1;
    pthread_t ptid2;
    int ret;
    void *rret;     //2.返回数据类型为void*

    if(access(FIFO1,F_OK)!=0){
        create_pipe_file(FIFO1);
    }
    if(access(FIFO2,F_OK)!=0){
        create_pipe_file(FIFO2);
    } 

    pthread_rwlock_init(&rwmutex1,NULL);
    pthread_rwlock_init(&rwmutex2,NULL);

    ret = pthread_create(&ptid1,NULL,func_readfile,(void*)SERVER);
    ret = pthread_create(&ptid2,NULL,func_writefile,(void*)SERVER);

    pthread_join(ptid1,&rret);
    pthread_join(ptid2,&rret);

    pthread_rwlock_destroy(&rwmutex1);
    pthread_rwlock_destroy(&rwmutex2);

    return ;
}

//客户端模式
void client_mode(){
    pthread_t ptid1;
    pthread_t ptid2;
    int ret;
    void *rret;

    if(access(FIFO1,F_OK)!=0){
        create_pipe_file(FIFO1);
    }
    
    if(access(FIFO2,F_OK)!=0){
        create_pipe_file(FIFO2);
    } 

    pthread_rwlock_init(&rwmutex1,NULL);        //1.初始化& 指针类型
    pthread_rwlock_init(&rwmutex2,NULL);  

    ret = pthread_create(&ptid1,NULL,func_readfile,(void*)CLIENT);
    ret = pthread_create(&ptid2,NULL,func_writefile,(void*)CLIENT);

    pthread_join(ptid1,&rret);
    pthread_join(ptid2,&rret);

    pthread_rwlock_destroy(&rwmutex1);
    pthread_rwlock_destroy(&rwmutex2);

    return ;
}


int main(int argc,char* argv[]){
    char ch;
    if(argc<2){
        usage(argv[0]);
    }

    while((ch=getopt(argc,argv,"sc"))!=EOF){
        switch(ch){
            case 's':
                server_mode();
                break;
            case 'c':
                client_mode();
                break;
            default:
                break;
        }

    }
    return 0;
}
