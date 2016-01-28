/**
* Create Date:2016年01月28日 星期四 10时19分21秒
* 
* Author:Norman
* 
* Description: 
*/


####U-boot环境变量分析:
    传递给内核参数
    bootargs=noinitrd  root=/dev/mtdblock3  init=/linuxrc  console=ttySAC0,115200 mem=64M
    ------------------------------------------------
    |  U-boot|  env|    kernel    |   filsystem|  
    |        |     |              |            |
    |        |     |              |            |
    -------------------------------------------------
    4K 256K     128K        5M           5M
    bootcmd=nand read 0x30008000 0x60000 0x500000; bootm 0x30008000
    
    0x3000800:将内核读到该位置
    0x60000: 0x200000  = 128K 环境变量分析
    0x500000:读取5M
    bootm:引导位置0x30008000 从此开始读

####烧写U-boot:
    烧录准备步骤：
    1.把启动开关拨置nand flash启动;
    2.出现一个3-5秒的倒计时，按任意键进入uboot命令调式模式;
    3.配置uboot环境变量：
        3.1:set ipaddr 192.168.7.226    （设置开发板IP地址）
        3.2:set serverip 192.168.7.20    (PC机的IP地址)
        （此处设置后，可以运行ping 192.168.7.yyy，看是否能ping通pc机）

    4.安装TFTP服务器:
        4.1:安装tftp-server
        sudo apt-get install tftpd-hpa
        sudo apt-get install tftp-hpa(如果不需要客户端可以不安装)
        tftp-hpa是客户端
        tftpd-hpa是服务器端

        4.2:配置TFTP服务器
        sudo vim /etc/default/tftpd-hpa
        将原来的内容改为:
            TFTP_USERNAME=”tftp”
            TFTP_ADDRESS=”0.0.0.0:69″
            TFTP_DIRECTORY=”tftp根目录” #服务器目录,需要设置权限为777,chomd 777
            TFTP_OPTIONS=”-l -c -s”
        
        4.3:重新启动TFTP服务
            sudo service tftpd-hpa restart

####U-boot TFTP方式烧写内核:
    1:设置启动命令：
        setenv bootcmd "nand read 0x31000000 0x60000 0x500000;bootm 0x31000000"
        配置启动参数，从nand flash 启动：
    2:setenv bootargs "console=ttySAC0,115200  mem=64m   root=/dev/mtdblock3  rw rootfstype=ext2  init=/linuxrc"
    3:save (保存配置)

    4:下载内核并烧写
    tftp 0x31000000 uImage                      (从tftp服务端下载内核镜像烧写到内存0x31000000处)
    nand erase 0x60000   0x500000               (将nandflash格式化从环境变量后5M放置内核)
    nand write 0x31000000  0x60000   0x500000   (将内核从内存0x31000000处写到nandflash 0x60000后大小为5M)

    5,下载文件系统并烧写
    tftp 0x31000000 rootfs.ext2.img             (从tftp服务器上将文件系统镜像下载到0x31000000) 
    nand erase 0x560000   0x500000              (格式化0x560000后的5M大小用于存放文件系统)
    nand write 0x31000000  0x560000   0x500000  (写入文件系统到nandflash)
