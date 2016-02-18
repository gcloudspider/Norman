/**
* Create Date:2016年02月18日 星期四 15时57分28秒
* 
* Author:Norman
* 
* Description: 
*/

####模块详解:
    module_init(WE2000_init)宏:
        include/linux/init.h
        #define module_init(x) __initcall(x);

        #define __initcall(fn) device_initcall(fn)

        #define device_instcall(fn) __define_initcall("6",fn,6)
        定义的宏
        #define __define_initcall(level,fn,id) \
	    static initcall_t __initcall_##fn##id __used \
	    __attribute__((__section__(".initcall" level ".init"))) = fn (初始化---传递进来的函数指针)

        分解为:
        #define __define_initcall(level,static initcall_t __initcall_WE2000_init6__used)
        
        initcall_t 这是个函数指针
        typedef int (*initcall_t)(void);

        此为GNU 扩展将函数指针存放于连续的数组内
        __attribute__((__section__(".initcall" level ".init")))

        /arch/arm/kernel/vmlinux.lds
        __initcall_start = .;

    module_exit():

    static int __init

    static void __exit

    MODULE_AUTHOR();
    MODULE_DESCRIPTION();
    MODULE_LICENSE();
    MODULE_ALIAS();




