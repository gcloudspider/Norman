/**
* Create Date:2016年02月18日 星期四 09时32分54秒
* 
* Author:Norman
* 
* Description: 
*/

####ARM开发流程:
    1.布署环境:
        ubuntu 安装ckermit
    2.安装烧录软件:
        sudo chmod 777 dnw2
        sudo cp dnw2 /bin
    3.启动kermit
        ls /dev/ttyUSB*
        vi ~/.mykermrc 确保配置文件与/dev/ttyUSB* 一样
        sudo kermit
        按a 开始烧录

    4.启动终端:
        sudo dnw2 u-boot.bin
        烧录u-boot.bin

    5.安装交叉编译环境:
        sudo tar -zxvf arm-linux-gcc-4.3.2.tgz -c /root/
        vi ~/.bashrc
        export PATH=$PATH:/root/usr/local/arm/4.3.2/bin/
