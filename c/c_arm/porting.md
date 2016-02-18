/**
* Create Date:2016年02月17日 星期三 14时38分11秒
* 
* Author:Norman
* 
* Description: 
*/

####Linux系统移植步骤:
    1.移植u-boot:(选用u-boot-2016.01.tar.bz2):
        1.1:配置要编译的uboot生成.config
            make menuconfig
        1.2:生成uboot.bin文件

    2.移植kernel:(选用kernel-4.1.18.tar.xz稳定版)
    3.移植rootfs:
        3.1:制作rootfs目录
        3.2:移植busyBox(选用busybox-1.24.1.tar.bz2)
        3.3:制作控制台设备
        3.4:生成文件系统镜像(yaffs2文件系统)
    4.移植App应用程序:
