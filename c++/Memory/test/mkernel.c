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
#include <linux/slab.h>
#include <linux/vmalloc.h>

unsigned char* pagamem;
unsigned char* kmallocmem;
unsigned char* vmallocmem;

int init_module(void){
    pagemem = get_free_page(0);
    printk("<1> pagemem=%s",pagemem);
    kmallocmem = kmalloc(100,0);
    printk("<1> kmallocmem=%s",kmallocmem);
    vmallocmem = vmalloc(1000000);
    printk("<1> vmallocmem=%s",vmallocmem);
}


void cleanup_module(void){
    free_page(pagemem);
    kfree(kmallocmem);
    vfree(vmallocmem);
}
