/*########################################################
##File Name: sysfile.c
##Created Time:2015年12月11日 星期五 14时19分50秒
##Author: Norman 
##Description: 
##
##Issue: 1.循环fork 产生子进程
         2.主进程创建文件
         3.子进程删除文件

##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 10

int main(){
    int fd;
    int i;
    int ret;
    int status = 0;
    char name[1024];

    fd=fork();
    if(fd>0){
        printf("pid=%d\n",getpid());
        for(i=1;i<MAXNUM;i++){
            sleep(1);
            sprintf(name,"file_%d",i);
            ret=creat(name,0666);
            if(-1==ret){
                perror("creat");
            }else {
                printf("create file %s success!\n",name);
            }
        }
        while(1){
            ret = waitpid(fd,&status,WNOHANG);
            if(ret == fd){
                printf("child process status=%d\n",status);
                exit(0);
            } else {
                sleep(1);
                printf(".\n");
            }
        }   
    } else if(fd ==0){
        for(i=1;i<MAXNUM;i++){
            printf("child pid=%d\n",getpid());
            sleep(2);
            sprintf(name,"file_%d",i);
            ret=remove(name);
            if(-1==ret){
                perror("remove");
            } else {
                printf("delete file %s success!\n",name);
            }
        }   
    } else {
        perror("fork");
        return -1;
    }
}

