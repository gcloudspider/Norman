/*########################################################
##File Name: thread_create.c
##Created Time:2015年12月16日 星期三 14时31分03秒
##Author: Norman 
##Description: 
##          1.主线程创建文件
##          2.子线程删除文件
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
#include<pthread.h>

void* thread_del_file(void* v){
    int i;
    char name[20];
    int ret;

    for(i=0;i<30;i++){
        sprintf(name,"file_%d",i);
        if(access(name,F_OK)==0){
            ret = remove(name);
            if(-1 == ret){
                perror("remove");
            }
            printf("delete %s success!\n",name);
        }
    }
    return ;
}

int main(){
    pthread_t threadid;
    int i;
    int f,ret;
    void *value;
    char name[20];

    pthread_create(&threadid,NULL,thread_del_file,&i);

    for(i=0;i<30;i++){
        sprintf(name,"file_%d",i);
        f=access(name,F_OK);
        if(-1==f){
            ret = creat(name,O_RDWR);   
            if(-1 == ret){
                perror("creat");
            }
            printf("create %s success!\n",name);
        }   
    }
    
    return 0;
}
