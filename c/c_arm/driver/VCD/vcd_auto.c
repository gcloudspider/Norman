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

static char vcd_buf[1024] = "this vce module\n";


static struct cdev cdev_vcd;
static struct class *vcd_class;    //类
static struct device *vcd_device;  //设备

int vcd_open(struct inode *inode,struct file* file){
    printk("open vcd in kernel!\n");
    return 0;
}

int vcd_release(struct inode* inode,struct file* file){
    printk("vcd release in kernel\n");
    return 0;
}

ssize_t vcd_read(struct file* file,char __user *user,size_t count,loff_t* offset){
    //把buf内容从内核拷贝到用户区
    return copy_to_user(user,vcd_buf,count);
}

ssize_t vcd_write(struct file *file,const char __user* user,size_t count,loff_t *offset){
    //从用户区拷贝到buf
    return copy_from_user(vcd_buf,user,count);
}


//关联
static struct file_operations fops_vcd = {
    .owner = THIS_MODULE,
    .read = vcd_read,
    .write = vcd_write,
    .open = vcd_open,
    .release = vcd_release
};

static dev_t vcd;

static int __init
vcd_init(void){
    int ret;

    ret = alloc_chrdev_region(&vcd,0,1,"vcd");
    if(ret < 0){
        printk("vcd:register failed!\n don't get right device no!\n");
        return -1;
    }
    printk("vcd major=%d,vcd minor=%d\n",MAJOR(vcd),MINOR(vcd));

    vcd_class = class_create(THIS_MODULE,"vcd");
    vcd_device = device_create(vcd_class,NULL,vcd,NULL,"vcd");

    cdev_init(&cdev_vcd,&fops_vcd);
    cdev_vcd.owner = THIS_MODULE;
    cdev_vcd.ops = &fops_vcd;

    ret = cdev_add(&cdev_vcd,vcd,1);
    if(ret < 0){
        printk("cdev_add failed!\n");
        return -1;
    }
    printk("vcd driver successfuly!\n");
    return 0;
}

static void __exit
vcd_cleanup(void){
    cdev_del(&cdev_vcd);
    unregister_chrdev_region(vcd,1);

    device_unregister(vcd_device);
    class_destroy(vcd_class);
    printk("vcd unregist ok!\n");
}

module_init(vcd_init);
module_exit(vcd_cleanup);

MODULE_LICENSE("GPL");
