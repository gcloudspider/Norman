/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/


#include <linux/module.h>
#include <linux/init.h>
extern char* p;

static int __init
WE2000_init(void){
    printk("/####################/\n");
    printk(p);
    printk("/####################/\n");
    return 0;
}

static void __exit
WE2000_cleanup(void){
    printk("Uninstall WE2000 module\n");
}

module_init(WE2000_init);
module_exit(WE2000_cleanup);

MODULE_LICENSE("GPL");
