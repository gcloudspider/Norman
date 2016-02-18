/**
* Create Date:2016年02月18日 星期四 15时57分28秒
* 
* Author:Norman
* 
* Description: 
*/

####模块详解:
    module_init()此宏详解:
        include/linux/init.h
        #define module_init(x) __initcall(x);

        #define __initcall(fn) device_initcall(fn)

        #define device_instcall(fn) __define_initcall("6",fn,6)
        #define __define_initcall(level,fn,id) \
	              static initcall_t __initcall_##fn##id __used \
	    __attribute__((__section__(".initcall" level ".init"))) = fn

    module_exit():

    static int __init

    static void __exit

    MODULE_AUTHOR();
    MODULE_DESCRIPTION();
    MODULE_LICENSE();
    MODULE_ALIAS();




