/**
* Create Date:2016年02月18日 星期四 17时43分29秒
* 
* Author:Norman
* 
* Description: 
*/

####模块依赖:(we2000.ko和resource.ko模块)
    1.模块依赖步骤:
        1.1:在we2000.c文件中extern char* p;
        1.2:在resource.c文件中 EXPORT_SYMBOL(p);

    2.加载模块顺序:
        insmod resource.ko
        insmod we2000.ko

    3.卸载模块顺序:
        rmmod we2000.ko
        rmmod resource.ko

    4.自动识别依赖顺序:
        4.1:depmod 建立依赖关系文件
            a.将.ko文件拷贝到/lib/modules/`uname -r`目录下
            b.在该目录下运行depmod
            c.运行后产生一个关系描述文件(给modprobe文件识别)
        4.2:modprobe
            运行modprobe my_module 系统会根据依赖文件,自动加载resource和my_module模块
        

