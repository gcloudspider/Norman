/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(){
    int fd,ret;
    char buf[1024] = {0};
    fd = open("/dev/vcd",O_RDONLY);
    if(fd < 0){
        perror("open vcd");
        return -1;
    }
    read(fd,buf,10);
    printf("read buf=%s\n",buf);
    close(fd);
    return 0;
}
