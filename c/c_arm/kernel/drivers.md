/**
* Create Date:2016年02月17日 星期三 10时19分33秒
* 
* Author:Norman
* 
* Description: 
*/

####往内核添加自定义驱动模块:
    1.将源文件放到drivers/net/my_net.c目录下
    2.编写drivers/net/Makefile 添加到内核参与编译
    3.修改drivers/net/Kconfig 添加模块选项
    4.重新makemenuconfig 添加该驱动模块参与编译写入.config宏为y
