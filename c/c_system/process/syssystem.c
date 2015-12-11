/*########################################################
##File Name: syssystem.c
##Created Time:2015年12月11日 星期五 16时22分06秒
##Author: Norman 
##Description: system(const char* command)
##             1.解释括号得到括号中字符串
##             2.fork子进程 父进程等待执行完继续执行
##             3.子进程调用exec执行命令
##             4.waitpid 获取子进程状态
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
#include<unistd.h>

int main(int argc, char * argv){
    int fd;
    int status = 0;
    int ret;

    fd = fork();
    if(fd>0){
        while(1){
            ret = waitpid(fd,&status,WNOHANG);
            if(ret == fd){
                printf("child process exit status=%d\n",status);
                execlp("ls","ls",NULL);
                exit(0);
            }else {
                sleep(5);
                printf(".\n");
            }
        }
        
    } else if(fd ==0){
        //ret = execlp("ls","-l",NULL);

        ret = execl("/home/zhimeng/Norman/c/aa.sh","aa.sh",NULL);
        if(-1 == ret){
            perror("execlp");
        }
        exit(0);
    } else {
        perror("fork");
        return -1;
    }

    return 0;
}

