/*########################################################
##File Name: semapha_wf.c
##Created Time:2015年12月15日 星期二 19时16分05秒
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

int main(int argc ,char * argv[]){
    int id;
    int ret;
    struct sembuf s;
    key_t key = 4000;
    int fd;
    int i;
    if(argc < 2){
        printf("Usage:cmd argv\n");
        return -1;
    }
    
    id = semget(key,1,IPC_CREAT|0666);
    if(-1==id){
        perror("semget");
        return -1;
    }

    s.sem_num = 0;
    s.sem_op = -1;
    s.sem_flg = 0;
    semop(id,&s,1);
    printf("申请成功,开始写文件!\n");

    fd = open("a.txt",O_RDWR|O_CREAT|O_APPEND,0666);
    if(-1 == fd){
        perror("open");
        return -1;
    }

    for(i=0;i<20;i++){
        write(fd,argv[1],strlen(argv[1]));
        usleep(1000*500);
    }
    close(fd);

    s.sem_num = 0;
    s.sem_op = 1;
    s.sem_flg = 0;
    semop(id,&s,1);
    printf("释放文件!\n");

    return 0;
}
