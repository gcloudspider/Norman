/*########################################################
##File Name: thread_whcat.c
##Created Time:2015年12月16日 星期三 19时55分12秒
##Author: Norman 
##Description: 
##          1.创建多线程
##          2.
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
#include"head.h"

#define FIFO1 "FIFOfile1"
#define FIFO2 "FIFOfile2"

int fifo1;
int fifo2;

void create_fifo(){
    int ret;
    ret = mkfifo(FIFO1,0666);
    if(-1 == ret){
        perror("mkfifo1");
    }

    ret = mkfifo(FIFO2,0666);
    if(-1 == ret){
        perror("mkfifo2");
    }
    
    fifo1=open(FIFO1,O_RDWR);
    fifo2=open(FIFO2,O_RDWR);

}

void* func_thread(void *v){
    int ret;
    while(1){
        char buffer[1024];
        ret = read(fifo2,buffer,1024);
        if(-1 == ret){
            perror("read");
        }
            printf("peer say:%s\n",buffer);
    }

}

void write_to_fifo(){
    int ret;
    while(1){
        char buffer[1024];
        scanf("%s",buffer);
        ret = write(fifo1,buffer,1024);
        if(-1 == ret){
            perror("write");
        }
    }
}

int main(){
    void *rret;
    pthread_t threadid;
    
    create_fifo();

    pthread_create(&threadid,NULL,func_thread,NULL);

    write_to_fifo();
    
    return 0;
}

