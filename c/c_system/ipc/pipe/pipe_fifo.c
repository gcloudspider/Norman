/*########################################################
##File Name: pipe_fifo.c
##Created Time:2015年12月15日 星期二 11时25分16秒
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
#include"head.h"
char *filename = "FIFOBuffer";

int main(){
    int fd;
    int pid;
    int ret;
    char buffer[10];

    ret = mkfifo(filename,0666);
    if(-1 == ret){
        perror("mkfifo");
    }
    
    fd = open(filename,O_RDWR);
    pid=fork();
    if(pid > 0){
        write(fd,"123456\0",7);
        perror("write");
        sleep(2);
    } else if(pid ==0){
        read(fd,buffer,7);
        perror("read");
        printf("child read buffer=%s\n",buffer);
    } else {
        perror("fork");
    }
    close(fd);

    return 0;
}
