/**
* Create Date:2016年02月28日 星期日 13时43分24秒
* 
* Author:Norman
* 
* Description: 
*/

####libevent核心(基于libevent2.0.22):
    1.event结构:
        Libevent基于事件驱动
        event是Reactor框架中事件处理程序组件;它提供了函数接口 供Reactor在事件发生时调用。以执行相应事件处理


    2.event管理:
####![libevent 事件管理图](./libevent management.JPG)
        2.1:当有事件event转变为就绪状态时,libevent将它移入active event list[priority]中
        2.2:libevent根据自己调度策略选择就绪事件,调用cb_callback()函数执行事件处理
        2.3:根据就绪的句柄和事件类型填充cb_callback函数的参数
