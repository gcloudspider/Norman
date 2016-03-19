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
char *p = "This Module WE2000 Ethernet Drivers\n";

module_param(p,charp,S_IRUGO);
EXPORT_SYMBOL(p);

static int __init
Resource_init(void){
    printk("loading Resource module\n");
    return 0;
}

static void __exit
Resource_cleanup(void){
    printk("rmmod Resource module\n");
}

module_init(Resource_init);
module_exit(Resource_cleanup);

MODULE_LICENSE("GPL");
