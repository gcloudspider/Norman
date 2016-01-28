/**
* Create Date:2016年01月28日 星期四 09时58分55秒
* 
* Author:Norman
* 
* Description: 
*/

####u-boot启动模式:
    
               ----按下按键进入下载模式 
    u-boot ----|
               ----启动模式----->加载内核---->驱动---->文件系统等

####编译u-boot:
    make mini2440_config
    make 编译出.bin烧写文件

####u-boot常用命令:
    printenv (pri 简写)         打印环境变量
    set bootdelay 5             设置延时
    save                        保存
    reset                       重启
    set ipaddr 192.168.1.***
    set serverip 192.168.1.***



