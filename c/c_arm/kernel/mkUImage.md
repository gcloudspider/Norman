/**
* Create Date:2016年02月16日 星期二 11时07分47秒
* 
* Author:Norman
* 
* Description: 
*/

####编译内核步骤:
    1.将linux-2.6.38.mini2440.wei.tar.bz2解压到当前目录
    2.进入解压后的目录
    3.将config_mini2440_wei 改为.config
    4.执行make uImage 编译生成内核镜像
    5.生成uImage目录为arch/arm/boot/uImage
    6.将uImage拷贝到tftp里
    7.确保开发板ping通tftp服务器
    8.执行tftp 下载UImage到开发板内存中
    9.tftp 0x31000000 uImage                      (从tftp服务端下载内核镜像烧写到内存0x31000000处)
    10.nand erase 0x60000   0x500000               (将nandflash格式化从环境变量后5M放置内核)
    11.nand write 0x31000000  0x60000   0x500000   (将内核从内存0x31000000处写到nandflash 0x60000后大小为5M)


注意:
    在make uImage的最后一个步骤可能会出现如下错误：
    "mkimage" command not found - U-Boot images will not be built
    make[1]: *** [arch/arm/boot/uImage] 错误 1
    make: *** [uImage] 错误 2

    这是因为直接生成的镜像需要使用mkimage工具转换成u-boot可以识别的格式;
    mkimage工具存在于u-boot源码包的tools目录下，使用sudo cp mkimage /bin把mkimage拷贝到bin下即可;
