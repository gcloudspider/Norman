/**
* Create Date:2016年02月28日 星期日 10时27分05秒
* 
* Author:Norman
* 
* Description: 
*/

####Kqueue支持文件描述符类型:
    1.socket
    2.信号
    3.定时器
    4.AIO
    5.VNODE
    6.PIPE

####Kqueue APIs:
    通过kevent()提供三个主要行为功能:
        1.注册/反注册
            kevent中的neventlist输入参数,设为0 并且传入合法changelist和nchangelist就会将changelist中事件注册到kqueue中
            当关闭某文件描述符时,与之关联事件就会自动从kqueue移除
        2.允许/禁止过滤器事件
            通过flags EV_ENABLE和EV_DISABLE使过滤器事件有效或无效
            这个功能利用EVFILT_WRITE发送数据时非常有用
        3.等待事件通知:
            将nchangelist设为0 传入其它合法参数,当kevent非错误和超时返回时,在eventlist和neventlist中就保存可用事件集合

    kqueue():
        生成一个内核事件队列,返回该队列的文件描述索
        其他API通过该描述符操作这个kqueue生成多个kqueue
