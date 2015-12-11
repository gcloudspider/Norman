/*########################################################
##File Name: sysvfork.c
##Created Time:2015年12月11日 星期五 09时50分43秒
##Author: Norman  
##Description: 保证子进程先运行
##  fork与vfork区别:
##    1.vfork不能使用return
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
#include<stdlib.h>


int main(){
    int fd;
    int i=0;
    fd = vfork();
    if(fd == 0){
        printf("f pid = %d, ppid=%d\n",getpid(),getppid());
    } else if(fd >0){
        printf("c pid=%d,ppid=%d\n",getpid(),getppid());
        exit(0);
    } else {
        perror("vfork");
    }
    return 0;
}


