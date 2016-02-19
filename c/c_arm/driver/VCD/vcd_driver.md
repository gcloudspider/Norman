/**
* Create Date:2016年02月19日 星期五 10时08分31秒
* 
* Author:Norman
* 
* Description: 
*/

####字符设备框架:
    APP上层应用程序 Open("/dev/vcd",...)          UserSpace
    ------------------------------------------------------
                          |
                          V
                        Kernel
    ______________________________________________________
    |          主设备号    次设备号                        |
    |          dev_no                                     |
    |            |                                        |
    |            |                                        |
    |            V                                        |
    |链表    C_dev 字符设备结构体                          |
    |    -----------------------------                    |
    |    |dev_no  | file_ope函数指针 | ---->对应的模块驱动 | ---->驱动中Open函数或其他函数
    |    -----------------------------                    |
    |    |dev_no  | file_operatinons |                    |
    |    -----------------------------                    |
    |    |dev_no  | file_operatinons |                    |
    |    -----------------------------                    |
    |    |dev_no  | file_operatinons |                    |
    |    -----------------------------                    |
    |    |dev_no  | file_operatinons |                    |
    |    -----------------------------                    |
    |_____________________________________________________|

####注册流程:
    1.注册或申请一个设备号(主设备号和次设备号)
        1.1:register_chrdev_region
    2.注册一个字符设备结构体,需要该结构体绑定其驱动操作函数
        2.1:cdev_init() 初始化结构体
        2.2:将设备ID与函数指针绑定
        2.3：cdev_add 添加到结构体中形成表格

####卸载流程:
    1.删除设备号/释放 cdev_del()
    2.反注册 unregister_chrdev_region


####关联结构体:
    1.编写file_operations结构体中需实现的read write函数
    2.模块中实现read write函数
    3.file_operations 将结构体中函数指针与模块中实现函数关联

####编译生成:
    1.生成vcd_driver.ko模块文件
    2.arm-linux-gcc -o vcd_read vcd_read.c 生成vcd_read程序运行于ARM板上
      arm-linux-gcc -o vcd_write vcd_write.c 生成vcd_write
    3.将模块vcd_driver.ko与vcd_read vcd_write 拷贝到nfs (/root/rootfs)
    4.在开发板上插入模块
    5.mknod vcd c 200 0
    6.运行app

