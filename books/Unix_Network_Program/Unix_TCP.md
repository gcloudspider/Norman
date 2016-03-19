/**
* Create Date:2016年03月 9日星期三 13:37:03
* 
* Author:Norman
* 
* Description: 
*/

####Tcp原理:
    服务器Socket创建:
        1.调用Socket返回一个套接字描述符
        2.调用bind
        3.listen
        4.accept

    客户端Socket创建:
        1.调用Socket 返回一个套接字描述符
        2.调用Connect函数

####connect函数:
    1.处理面向连接网络服务器Tcp客户端调用函数connect来建立与TCP服务器的一个连接
    2.客户端connect不必调用bind函数,内核会确定源IP地址,并选择一个临时端口作为源端口

####bind函数:
    1.bind将套接字绑定到一个地址

####listen函数:
    监听端口
