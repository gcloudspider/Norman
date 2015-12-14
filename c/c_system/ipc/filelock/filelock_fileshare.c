/*########################################################
##File Name: filelock_fileshare.c
##Created Time:2015年12月14日 星期一 11时26分39秒
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

int main(int argc,char* argv[]){
    int pid;
    int fd,ret;
    int i=500,j=500;
    struct flock fl;

    if(argc <2) return -1;


    fd = open(argv[1],O_RDWR);
    if(-1 == fd){
        perror("open");
        return fd;
    }

    pid=fork();

    if(pid>0){
        fcntl(fd,F_GETLKW,&fl);
        //加锁
        fl.l_type = F_WRLCK;
        fl.l_whence = SEEK_END;
        fl.l_start = 0;
        fl.l_len = 0;
        //fl.l_pid = pid;

        fcntl(fd,F_SETLKW,&fl);
        while(i--){
            ret = write(fd,"12345",5);
            if(-1 == ret){
                perror("write");
                return ret;
            }
            usleep(1000*10);
        }
        //解锁
        fl.l_type = F_UNLCK;
        fl.l_whence = SEEK_END;
        fl.l_start = 0;
        fl.l_len = 0;
        //fl.l_pid = pid;
        fcntl(fd,F_SETLKW,&fl);

    } else if(pid ==0){
        //加锁
        fl.l_type = F_WRLCK;
        fl.l_whence = SEEK_END;
        fl.l_start = 0;
        fl.l_len = 0;
        //fl.l_pid = pid;

        fcntl(fd,F_SETLKW,&fl);
        while(j--){
            ret = write(fd,"67890",5);
            if(-1 == ret){
                perror("write");
                return ret;
            }
            usleep(1000*10);
        }
        //解锁
        fl.l_type = F_UNLCK;
        fl.l_whence = SEEK_END;
        fl.l_start = 0;
        fl.l_len = 0;
        //fl.l_pid = pid;
        fcntl(fd,F_SETLKW,&fl);
    } else {
        perror("fork");
        return pid;
    }

    close(fd);

    return 0;
}

