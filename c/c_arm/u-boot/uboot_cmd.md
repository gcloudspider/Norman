/**
* Create Date:2016年01月28日 星期四 16时07分59秒
* 
* Author:Norman
* 
* Description: 
*/

####在U-boot中添加自己的命令:
    1.所有uboot命令放在源码包中commond目录下
    2.按照该目录下文件格式添加自己的命令
    3.将添加的文件添加到Makefile中进行编译
    4.make 编译生成u-boot.bin文件
    5.将u-boot.bin烧写到板子上
    6.重新进入板子下载模式。执行命令


####U-boot命令详解:
    1.以U-boot源码下的common目录下cmd_help.c为例:
    2.U_BOOT_CMD(_name/*名字*/,_maxargs/*最大参数个数*/,_req/*重复*/,_cmd/*命令*/,_usage/*使用方法*/,_help/*帮助文档*/)
    3.u-boot.lds中 .u_boot_cmd:{*(.u_boot_cmd)}
