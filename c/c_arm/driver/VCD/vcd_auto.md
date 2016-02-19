/**
* Create Date:2016年02月19日 星期五 13时52分53秒
* 
* Author:Norman
* 
* Description: 
*/

####自动生成设备文件:
    1.定义一个设备号变量
    2.alloc_chrdev_region申请一个设备号
    3.MAJOR() MINOR() 得到主次设备号
    4.在内核中创建类别 class_crete();
    5.在内核中创建设备节点 device_create();

####编译生成:
    1.编译vcd_atuo.c  make
      arm-linux-gcc -o vcd_read vcd_read.c
      arm-linux-gcc -o vcd_write vcd_write.c

    2.将vcd_read vcd_write和vcd_auto.ko 拷贝到nfs (/root/rootfs/)
    3.在开发板上运行insmod vcd_auto.ko 
    4.在开发板上运行vcd_write后使用vcd_read读
