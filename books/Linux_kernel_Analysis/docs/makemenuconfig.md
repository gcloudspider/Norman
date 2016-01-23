/**
* Create Date:2016年01月23日 星期六 10时51分07秒
* 
* Author:Norman
* 
* Description: 
*/

####编译内核步骤:
    1.下载内核源码:4.3
    2.解压:
        tar -zxvf linux-4.3.tar.gz
    3.配置内核:
        3.1:为了得到内核配置文件.config
        3.2:sudo apt-get install libncurses5-dev 安装图形界面
        3.3:sudo make menuconfig
        3.4:执行上面命令就可以对模块添加减少
    4.编译(两部分工作):
        4.1:编译内核形成bzImage镜像文件  make bzImage
        4.2:编译内核模块,形成.ko结尾内核模块目标文件 make modules
        4.3:使用make -jn 参数提高编译效率 n取值cpu个数二倍
    5.安装(两部分):
        5.1:对内核模块进行安装  sudo make modules_install
        5.2:安装编译好内核 sudo make install
    6.将编译内核生成镜像bzImage拷贝到/boot目录下:
        6.1:命名镜像文件vmlinuz-4.3 (x86该镜像位于arch/x86/boot)
        6.2:将～/linux-4.3/目录下system.map拷贝到/boot/目录下 重新命名为System.map-4.3 该文件存放了内核符号表
        6.3:将~/linux-4.3/目录下.config拷贝到/boot/目录下 重新命名为config-4.3
    7.创建initrd.img文件:
        7.1:initrd.img即为初始化ramdisk文件(镜像文件,最基本驱动程序和命令工具打包到镜像文件里)
        sudo mkinitramfs 4.3 -o /boot/initrd.img-4.3
    8.更新grub:
        8.1:sudo update-grub2 
        8.2:修改默认系统启动顺序:/boot/grub/grub.cfg set default=
