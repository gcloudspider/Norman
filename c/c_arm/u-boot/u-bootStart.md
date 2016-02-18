/**
* Create Date:2016年02月18日 星期四 12时21分58秒
* 
* Author:Norman
* 
* Description: 
*/

####U-boot启动流程图:(u-boot-2016.01版本分析)
    1.第一阶段:
        硬件设备初始化-----> 加载U-boot第二阶段代码到RAM空间  ---->设置好栈 -----> 跳到第二阶段代码入口
    2.第二阶段:
        初始化本阶段使用的硬件设备 -----> 检测系统内存映射 ------>将内核从Falsh读到RAM中 ----->为内核设置启动参数 ----->调用内核

####U-boot第一阶段代码分析:
    顶层目录下u-boot.lds指定:
        对应文件:arch/arm/cpu/arm920t/start.o(由start.S生成.o文件)
        1.做重要的初始化 bl cpu_init_crit
        2.拷贝arm boot到ram中 lowlevel_init.S文件中 bl lowlevel_init
           board/samsung/mini2440/lowlevel_init.S
        3.设置堆栈
        4.跳到第二阶段代码处 bl _main



