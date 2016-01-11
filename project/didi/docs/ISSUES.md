###################################################
## Create Date:2016年01月11日 星期一 17时10分05秒
##
##Author:Norman
##
##Description: 
###################################################

####Issues
    1.write() 客户端掉线后如果服务器还往socket中写入信息会产生SIGPIPE信号
        解决方法:signal(SIGPIPE,SIG_IGN); 忽略SIGPIPE信号
    2.read ()  死循环中返回0 退出死循环
    3.全局变量链表,尾插法问题: 使用锁保证链表正常
    4.scanf(); 返回值
    buf = "hello,shenzhen2016,nihao";
    5.sscanf(buf,"%[^,],%[^,],%[^,],");
