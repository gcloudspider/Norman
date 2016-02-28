/**
* Create Date:2016年02月28日 星期日 09时58分58秒
* 
* Author:Norman
* 
* Description: 
*/

####[IO模型](../../../books/Design_Pattern/Reactor/Proactor.md)

####Kqueue与select poll区别:
    1.select() poll() 接收大量请求时问题:
        1.kernel <----> userspace 内存拷贝代价,一旦请求到来之后,无论其是否被处理,都会从kernel ---> userspace内存拷贝
        2.应用程序需扫描所有打开文件描述符,重复劳动(kernel直接把就绪的FD告诉app)
        3.内核内部保存所有文件描述符链表,一个连接到来,kernel需要遍历这个列表找到空闲文件描述符
    
    2.epoll()/kqueue/IOCP解决以上3个问题:
        epoll()两种工作方式:
            LT:文件描述符就绪了,内核通知,如果不做任何操作,内核还是会继续通知
            ET:文件描述符变为就绪时,内核通知.不会再为已经就绪文件描述再发通知
####[kqueue:FreeBSD 4.x引入](./freeBSD_kqueue.md):
    1.注册一堆描述符到kqueue后
    2.当其中描述符状态发生变化时,kqueue将一次性通知应用程序哪些描述符可读 可写或出错

####[IOCP:windows2000引入](./windows_iocp.md)

