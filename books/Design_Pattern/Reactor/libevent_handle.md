/**
* Create Date:2016年02月28日 星期日 15时21分24秒
* 
* Author:Norman
* 
* Description: 
*/

####事件处理框架:
    event-internal.h内部头文件中 struct event_base结构体
    对应于Reactor框架组件

####初始化event_base:
    1.创建一个event_base对象也既是创建了一个新的libevent实例
    2.程序需要通过调用event_init() --->内部调用event_base_new函数来创建
    3.该函数还对新生成libevent实例进行了初始化:
        1.为event_base实例申请空间
        2.初始化timer mini-heap 
        3.选择并初始化合适的系统I/O的demultiplexer机制
        4.初始化各事件链表
        5.检测了系统时间设置

####接口函数:
    event_add 注册事件:
        注册成功,ev将被插入到已注册链表中
        event_queue_insert()负责将事件插入到对应链表中
        event_queue_remove()负责将事件从对应链表中删除
    event_del 删除事件:
        删除事件ev 
        对于I/O事件,从I/O的demultiplexer上将事件注销;
        对于signal事件,将从Signal事件链表中删除,
        对于定时事件,将从堆上删除.
    event_base_loop
    event_active
    event_process_active

    定时事件:函数调用timer heapp管理接口 执行插入和删除操作
    I/O和signal事件:调用eventopadd和delete接口函数执行插入和删除
