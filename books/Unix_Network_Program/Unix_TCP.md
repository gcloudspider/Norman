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
