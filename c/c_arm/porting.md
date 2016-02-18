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
            make smdk2410_config
            make menuconfig
        1.2:生成uboot.bin文件系统
            make (error:bad value(armv4))
            修改Makefile添加上交叉编译或(make CROSS_COMPILE=arm-none-linux-gnueabi-)
        1.3:修改uboot-2016 支持mini2440:
            (详见u-boot启动流程:./u-boot/u-boot.md)
            vim arch/arm/cpu/arm920t/start.S 
            vim include/configs/smdk2410.h 
            vim board/samsung/smdk2410/smdk2410.c 
            
    2.移植kernel:(选用kernel-4.1.18.tar.xz稳定版):
        2.1:配置kernel生成.config
            make menuconfig
        2.2:生成uImage
            make uImage
    3.移植rootfs:
        3.1:制作rootfs目录
        3.2:移植busyBox(选用busybox-1.24.1.tar.bz2)
        3.3:制作控制台设备
        3.4:生成文件系统镜像(yaffs2文件系统)
    4.移植App应用程序:
