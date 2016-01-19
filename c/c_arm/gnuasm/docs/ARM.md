/**
* Create Date:2016年01月18日 星期一 20时42分11秒
* 
* Author:Norman
* 
* Description: 
*/

####ARM介绍:
    ARM启动方式:
        norfalsh启动
        nandflash启动
        SD卡启动
        USB启动

####概念:
    SDRAM:同步动态随机存取存储器,指Memory需要同步时钟,内部命令发送与数据传输都以它为基准.(即内存条)
    SRAM:高速缓冲存储器(cache)
    norflash:外部存储介质,它有地址总线,cpu可以直接从norflash中取指。
             NOR传输效率高,写入数据时需要指定命令才能写入,每次写入前都擦除

    nandflash:有数据总线,无地址总线,所以Cpu不能直接从Nandflash取指运行(硬盘类似)


