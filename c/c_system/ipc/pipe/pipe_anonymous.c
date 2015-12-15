/*########################################################
##File Name: pipe_anonymous.c
##Created Time:2015年12月15日 星期二 10时33分59秒
##Author: Norman 
##Description:  无名管道 
#
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


int main(){
    int fd;
    char buffer[10] = {0};
    int fds[2];
    char buf[7] = {0};
    int fds_cr_fw[2];
    int fds_fr_cw[2];
    
    int ret = pipe(fds);
    if(-1 == ret){
        perror("pipe");
        return ret;
    }

    pipe(fds_cr_fw);
    pipe(fds_fr_cw);


    fd = fork();
    if(fd >0){
        //单管道
        //close(fds[0]);             管道关闭.
        write(fds[1],"12345",5);
        sleep(2);
        read(fds[0],buffer,5);
        printf("f read=%s\n",buffer);
        
        //双管道
        close(fds_cr_fw[0]);
        write(fds_cr_fw[1],"abcdefg",7);

        close(fds_fr_cw[1]);
        read(fds_fr_cw[0],buf,7);
        printf("double f read=%s\n",buf);

    } else if (fd ==0){
        //close(fds[1]);
        read(fds[0],buffer,5);
        printf("c read=%s\n",buffer);
        sleep(1);
        write(fds[1],"67890",5);
        //双管道 
        close(fds_fr_cw[0]);
        write(fds_fr_cw[1],"hijklmn",7);
        
        close(fds_cr_fw[1]);
        read(fds_cr_fw[0],buf,7);
        printf("double c read=%s\n",buf);
    }else {
        perror("fork");
        return fd;
    }

    return 0;
}

