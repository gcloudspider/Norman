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
#include <event.h>
#include <stdlib.h>
#include <stdio.h>

struct event ev;
struct timeval tv;

void time_cb(int fd,short event,void *argc){
    printf("timer wakeup\n");
    event_add(&ev,&tv);
}

int main(){
    //1.初始化libevent库
    struct event_base *base = event_init();
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    //初始化事件event
    evtimer_set(&ev,time_cb,NULL);
    //添加事件
    event_add(&ev,&tv);
    //进入无限循环,等待就绪事件并执行事件处理
    event_base_dispatch(base);
}
