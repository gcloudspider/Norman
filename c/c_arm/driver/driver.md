/**
* Create Date:2016年02月18日 星期四 15时24分18秒
* 
* Author:Norman
* 
* Description: 
*/

####基本操作:
    make 生成模块
    make clean 清除模块
    insmod we2000.ko 加载模块
    rmmod we2000 卸载模块
    (提示rmmod: chdir(/lib/modules): No such file or directory)
    卸载模块之前，确保/lib/下有 module/`uname -r`这个目录;如果没有，先建立之:mkdir -p /lib/modules/`uname -r`)
    lsmod 查看模块

####新增驱动流程:
    方式一:添加到内核与内核一起编译(添加WE2000网卡为例)
        1.将源文件放到drivers/net/we2000.c目录下
        2.编写drivers/net/Makefile 添加到内核参与编译
            在obj-$(CONFIG_DM9000) += dm9000.o下增加
            obj-$(CONFIG_WE2000) += we2000.o

        3.修改drivers/net/Kconfig 添加模块选项
            在config DM9000上面添加config WE2000选项
            (此做法在make menuconfig ---->
             Device Drivers------>
              Network device support ---->
                Ethernet(10 or 100Mbit)----->)
                <*> WE2000 support

        4.重新make menuconfig 添加该驱动模块参与编译写入.config宏为y

        5.make uImage重新生成kernel镜像

    方式二:将驱动编译成模块
        1.步骤与方式一 1 2 3 一样
        2.make menuconfig 时 将WE2000 support 编译成
        Device Drivers ---->
         Network device support ---->
         Ethernet(10 or 100Mbit)---->
         <M> WE2000 support
        3.重新make uImage 编译生成kernel镜像

    方式三:在已运行的linux上将编译成模块:
        1.在任意目录下创建we2000.c源文件
        2.编写Makefile 
        3.编译make 生成we2000.ko
        4.将we2000.ko放于NFS文件服务器的rootfs目录中
        5.到开发板上进行insmod we2000.ko
        6.查看lsmod
        7.卸载rmmod we2000

