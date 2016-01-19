/**
* Create Date:2016年01月18日 星期一 20时49分58秒
* 
* Author:Norman
* 
* Description: 
*/
####Nandflash启动过程:
    1.开发板上电,将0x00地址映射到stepping stone 自动复制Nandflash前4K数据到stepping stone  (硬件自动实例内存映射)
    2.把bootload烧写到nandflash最低位置,即从0x000开始烧写
    3.CPU从内部RAM的0x00000000位置开始启动
    4.将nandflash前4K内容拷贝到stepping stone中,然后从stepping stone第一条指令开始执行。


#### 前4K指令完成动作:
    1.硬件初始化
    2.加载U-Boot第二阶段代码到SDRAM空间
    3.设置好栈
    4.跳到第二阶段代码入口

####第二阶段步骤:
    1.设置cpu运行模式
    2.关看门狗
    3.设置时钟
    4.关中断
    5.初始化内存
    6.初始化nandflash
    7.设置堆栈
    8.将整个bootload搬运到SDRAM中 并跳转到SDRAM中执行
