/*########################################################
##File Name: thread_multi.c
##Created Time:2015年12月17日 星期四 16时08分59秒
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
#define THREADNUM 3

struct timeval tv;
struct timezone tz;

void useage(const char* proname){
    fprintf(stderr,"Usage:%s <filename> [-i Init] [-s single] [-m multi]\n",proname);
    exit(2);
}

void* gen_rand_file(void* filename){
    FILE* fd;
    fd = fopen((char*)filename,"w");
    int i,r;
    time_t t;
    srand(0xffffffff);
    for(i=0;i<3000000;i++){
        r = rand();
        fprintf(fd,"%d\n",r);
    }
    fclose(fd);
}

void create_file(const char* filename){
    int i;
    char name[1024];
    pthread_t thread_id[THREADNUM];
    void *rret;

    for(i=0;i<THREADNUM;i++){
        sprintf(name,"%s_%d",filename,i);
        pthread_create(&thread_id[i],NULL,gen_rand_file,name);    
        //printf("begin create thread %d\n",i);
        //pthread_join(thread_id,&rret);  //设用pthread_join线程没有运行结束,调用者会被阻塞
        //pthread_detach(thread_id[i]);  //调用者不阻塞
        //printf("after create thread %d\n",i);
    }

    for(i=0;i<THREADNUM;i++){
        pthread_join(thread_id[i],&rret);
    }   
}

void readfile_single_thread(){
    //TODO:
}

void readfile_multi_thread(){
    //TODO
}

int main(int argc,char * argv[]){

    int ch;
    if(argc <2){
        useage(argv[0]);
    }

    while((ch=getopt(argc,argv,"ism"))!=EOF){
        switch(ch){
            case 'i':
                create_file(argv[1]);
                break;
            case 's':
                readfile_single_thread();
                break;
            case 'm':
                readfile_multi_thread();
                break;
            default:
                break;
        }
    }
}



