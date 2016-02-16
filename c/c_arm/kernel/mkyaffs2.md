/**
* Create Date:2016年02月16日 星期二 16时08分00秒
* 
* Author:Norman
* 
* Description: 
*/

####编译2.6.32版本的内核（支持yaffs2文件系统）:
    1.解压源码包:
        tar xzvf linux-2.6.32.2-yaffs2-sound.tar.gz
    2.配置文件:
        cp config_mini2440_x35 .config
    3.生成内核镜像:
        make uImage
    4,下载内核并烧写
    tftp 0x31000000 uImage-yaffs2
    nand erase 0x60000   0x500000
    nand write 0x31000000  0x60000   0x500000

    5.下载文件系统并烧写
    tftp 0x32000000 yaffs2.mp3.img
    nand erase 0x560000   0x18400000
    nand write.yaffs2 0x32000000  0x560000   0x182fa00

    6.设置启动yaffs2文件系统
    setenv bootargs "console=ttySAC0,115200  mem=64m   root=/dev/mtdblock3  rw rootfstype=yaffs2  init=/linuxrc
