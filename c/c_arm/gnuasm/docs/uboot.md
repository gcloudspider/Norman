/**
* Create Date:2016年01月18日 星期一 21时00分10秒
* 
* Author:Norman
* 
* Description: 
*/

####uboot 上电启动内核流程:
    Reset --->进入管理模式   --->关闭看门狗 ---->屏蔽中断 ---->设置时钟分频

    ---->跳转到cpu_init_crit --->关闭mmu和caches  --->跳转到lowlevel_input

    ---->设置SDRAM ----> 初始化SDRAM  ---->跳转到main  --->设置C环境  ---->

    申请一个内存 ---->跳转到board_init_f ----> 清除bss -->跳转到board_init_r

    ---->确定启动的设置 ---->确定从什么地址加载uimage到ram ---->确定加载u-boot还是linux

    ---->加载完后跳转到main --->代码重定义 ----> __image_copy_start ---->__image_copy_end

    --->_rel_dyn_start ----> _rel_dyn_end

    --->bss初始化 ---->然后跳转到start --->定义中断 ---->定义不同的定义触发时怎么保存数据 

    ---->u-boot.lds
