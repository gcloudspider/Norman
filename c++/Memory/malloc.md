/**
* Create Date:2016年01月23日 星期六 10时39分32秒
* 
* Author:Norman
* 
* Description: 
*/

####malloc 内核:
    1.用户进程调用malloc()动态分配一块内存空间
    2.malloc库函数中封装了系统调用brk
    3.brk()在内核中对应的系统调用服务例程(SYSCALL_DEFINE1(brk,unsigned long,brk))
