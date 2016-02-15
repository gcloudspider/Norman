/**
* Create Date:2016年02月15日 星期一 11时16分24秒
* 
* Author:Norman
* 
* Description: 
*/

####Uboot添加USB设备:
    1.修改Uboot源代码打开支持usb和fat文件系统
    /Uboot-2010.03/include/configs/mini2440.h中添加
    /*
    *usb host driver and fat support
    * */
    #define CONFIG_USB_OHCI
    #define CONFIG_USB_STORAGE
    #define CONFIG_CMD_USB
    #define CONFIG_CMD_FAT
    #define CONFIG_DOS_PARTITION

    2.重新执行make编译u-boot源码生成.bin

    3.重新烧写u-boot
    将开关打至norflash 启动kermit 按a 
    使用dnw2 uboot.bin烧写

    4.检验:启动u-boot后按下help查看帮助支持usb命令和fat命令和

    5.usbinfo查看:
        usb设备:
            1.configuare配置
            2.interface接口
            3.setting设置
            4.endpoint端点

####使用u盘进行烧写kernel和filesystem:
    1.将内核image拷贝到U盘,插入到开发板的usb接口
    2.usb start 扫描usb总线设备
    3.fatload usb 0:1 0x31000000 uImage
    4.bootm 0x31000000

    usb start扫描usb总线设备
    usb info显示usb总线上设备详细信息
    fatls 显示storage设备上的文件信息  fatls usb 0
