/**
* Create Date:2016年02月28日 星期日 13时23分49秒
* 
* Author:Norman
* 
* Description: 
*/

####libevent源码分布:
    1.头文件:
        主要event.h 宏定义 接口函数声明 主要结构体event声明

    2.内部使用的头文件
        xxx-internal.h 内部数据结构和函数

    3.辅助功能函数
        evutil.h evutil.c 包括创建socket pair和时间操作函数

    4.日志
        log.h 和log.c日志函数

    5.libevent框架
        event.c event整体框架

    6.对系统I/O多路复用机制的封装
        epoll.c 对epoll封装
        select.c 对select封装
        devpoll.c 对dev/poll封装
        kqueue.c 对kqueue封装

    7.信号管理
        signal.c 对信号事件处理;

    8.定时事件管理
        min-heap.h 以时间作为key小根堆结构

    9.缓冲区管理
        evbuffer.c buffer.c libevent对缓冲区封装

    10.基本数据结构
        compat/sys两个源文件 queue.h libevent基本数据结构实现。链表 双向链表 队列等 
        _libevent_time.h 用于时间操作的结构体定义,函数和宏定义

    11.libevent实用库等
        http和evdns:基于libevent实现http服务器和异步dns查询库

