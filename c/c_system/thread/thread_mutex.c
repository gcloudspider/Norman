/*########################################################
##File Name: thread_mutex.c
##Created Time:2015年12月17日 星期四 14时44分07秒
##Author: Norman 
##Description: 
##
##Issue: 当单资源时用此加锁没有问题。当有多个资源仅用此可能造成死锁
##          提供pthread_trymutex
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include"head.h"

pthread_mutex_t mutex;   //互斥锁
char share_buf[1024];

void* func_thread1(void* v){
    int i=0,j=0,k;
    void *p = v;
    char *str[2] = {
        "hello","world"
    };
    
    while(++j){
        pthread_mutex_lock(&mutex);   //对资源进行加锁
        if(j%2) k=1;
        else k =0;
        for(i=0;str[k][i];i++,v++){
            if(str[k][i] != ' '){
                share_buf[i] = str[k][i];
            }   
        }
        pthread_mutex_unlock(&mutex);  //解锁
    }
    return v;
}

void* func_thread2(void* v){
    int i=0;
    while(1){
        pthread_mutex_lock(&mutex);     //读加锁
        for(i=0;share_buf[i];i++){
            putchar(share_buf[i]);
        }
        pthread_mutex_unlock(&mutex);       //读解锁
    }
    return v;
}

int main(){
    void *rret;
    pthread_t thread_id1;
    pthread_t thread_id2;
    int ret;

    pthread_mutex_init(&mutex,NULL);

    ret = pthread_create(&thread_id1,NULL,func_thread1,NULL);
    ret = pthread_create(&thread_id2,NULL,func_thread2,NULL);

    pthread_join(thread_id1,&rret);
    pthread_join(thread_id2,&rret);

    pthread_mutex_destroy(&mutex);
    return 0;
}

