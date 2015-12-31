/*########################################################
##File Name: test_daemon.c
##Created Time:2015年12月31日 星期四 14时27分47秒
##Author: Norman 
##Description: 
##
##Issue:  守护进程 
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
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void mydaemon(int ischdir,int isclose){
    pid_t pid;
    pid = fork();
    //父进程退出
    if(pid != 0)
        exit(-1);

    setsid();  //创建新会话

    //子进程成为新会话期领导和新进程组长
    pid = fork();

    if(pid !=0)
        exit(-1);

    //切换目录
    if(ischdir == 0){
        chdir("/");
    }

    if(isclose == 0){
        close(0);   //关闭输入流
        close(1);   //关闭输出流
        close(2);   //关闭错误输出
    }
    //去掩码位
    umask((mode_t)0);
}

int main(int argc,char** argv){
    mydaemon(1,1);

    while(1){
        sleep(1);
        printf("sleep...");
    }
    exit(EXIT_SUCCESS);
    return 0;
}
