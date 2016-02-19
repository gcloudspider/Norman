/**
* Create Date:2016年02月17日 星期三 15时31分43秒
* 
* Author:Norman
* 
* Description: 
*/

####制作rootfs:
    1.创建存放目录:(以下都是root权限下进行,如普通用户可能需要权限加sudo)
        mkdir /root/rootfs
    2.进入目录:(目录自定义)
        cd /root/rootfs
    3.创建文件系统目录:
        mkdir dev home mnt proc root sys tmp var sbin bin usr
    4.解压etc目录:
        tar -zxvf rootfs_etc.tar.gz /root/rootfs/
        mv /root/rootfs/rootfs_etc /root/rootfs/etc
    5.创建控制台设备文件:
        cd /root/rootfs/dev/
        mknod console c 5 1
    6.安装busybox依赖文件:
        6.1:拷贝所有动态库文件(拷贝的文件是ARM命令目录下的)
            cp -r /root/usr/local/arm/4.3.2/arm-none-linux-gnueabi/libc/armv4t/lib /root/rootfs/lib/
            6.2:清理调试信息(用strip处理过后,将去掉其中的调试信息,执行文件大小也将小很多)
            arm-linux-strip -g -s ./*
        6.3:删除静态库文件
            rm *.a

####编译busyBox:
    1.解压busybox
        tar -zxvf busybox-1.19.0.mini2440.tar.gz
    2.进入busybox目录后执行:
        make menuconfig
    3.选择以下选项:
        3.1:编译BusyBox为动态库程序:
        去掉Busy Settings --->Build Options--->
        []Build BusyBox as a static binary(no shared libs)
        3.2:不使用 /usr
        BusyBox Settings ----> General Configuration --->
        [*]Don't use /usr
        3.3:安装选项:安装到目录
        BusyBox Settings ---->Installation Options("make install" behavior) ----->BusyBox installation prefix 填写/root/rootfs
        3.4:Linux 系统实用程序:
        Linux System Utilities --->
        [*] mdev
        [*] Support /etc/mdev.conf
        [*] Support command execution at device addition/removal

    4.编译安装:
        make && make install

####生成文件系统镜像:
    1.创建5M的镜像文件(此时为空)
        dd if=/dev/zero of=rootfs.ext2.img bs=1M count=5
    2.将文件格式化为ext2格式:
        mkfs.ext2 -m0 rootfs.ext2.img
    3.挂载rootfs文件系统:
        mount -o loop rootfs.ext2.img  /mnt/
    4.拷贝制作好的rootfs目录下所有文件拷贝到rootfs.ext2.img这个镜像文件中
        cd /mnt/
        cp -a /root/rootfs/* .
    5.取消挂载:
        umount /mnt
    6.ext2格式镜像文件系统做好烧到ARM板上既可
