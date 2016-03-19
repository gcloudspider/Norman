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

#include <linux/types.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>

//static char beep_buf[1024] = "this beep module\n";


static struct cdev cdev_beep;
static struct class *beep_class;    //类
static struct device *beep_device;  //设备

int beep_open(struct inode *inode,struct file* file){
    *(volatile unsigned long*) ioremap(0x56000010,4)=0x1;
    printk("open beep && set beep mode=output in kernel!\n");
    return 0;
}

int beep_release(struct inode* inode,struct file* file){
    printk("beep release in kernel\n");
    return 0;
}

ssize_t beep_read(struct file* file,char __user *user,size_t count,loff_t* offset){
    return 0;
}

ssize_t beep_write(struct file *file,const char __user* user,size_t count,loff_t *offset){
    if(strncmp(user,"on",2)==0){
        *(volatile unsigned long*)ioremap(0x56000014,4)=0x1;
    }else if(strncmp(user,"off",3)==0){
        *(volatile unsigned long*)ioremap(0x56000014,4)=0x0;
    } else{
        printk("unknow operator!\n");
        return -1;
    }
    return 0;
}


//关联
static struct file_operations fops_beep = {
    .owner = THIS_MODULE,
    .read = beep_read,
    .write = beep_write,
    .open = beep_open,
    .release = beep_release
};

static dev_t beep;

static int __init
beep_init(void){
    int ret;

    ret = alloc_chrdev_region(&beep,0,1,"beep");
    if(ret < 0){
        printk("beep:register failed!\n don't get right device no!\n");
        return -1;
    }
    printk("beep major=%d,beep minor=%d\n",MAJOR(beep),MINOR(beep));

    beep_class = class_create(THIS_MODULE,"beep");
    beep_device = device_create(beep_class,NULL,beep,NULL,"beep");

    cdev_init(&cdev_beep,&fops_beep);
    cdev_beep.owner = THIS_MODULE;
    cdev_beep.ops = &fops_beep;

    ret = cdev_add(&cdev_beep,beep,1);
    if(ret < 0){
        printk("cdev_add failed!\n");
        return -1;
    }
    printk("beep driver successfuly!\n");
    return 0;
}

static void __exit
beep_cleanup(void){
    cdev_del(&cdev_beep);
    unregister_chrdev_region(beep,1);
    
    device_unregister(beep_device);
    class_destroy(beep_class);
    printk("beep unregist ok!\n");
}

module_init(beep_init);
module_exit(beep_cleanup);

MODULE_LICENSE("GPL");
