###################################################
#### Create Date:2016年01月14日 星期四 08时17分57秒
####
####Author:Norman
####
####Description: 
###################################################

####C编译器的任务是把C语言转化成计算机能够识别的内容。
    UNIX平台 目标文件后缀为.o
    Windows平台 目标文件后缀为.obj

####目标文件包含:
    1.代码:对应C文件中函数的定义
    2.数据:对应C文件中全局变量的定义(已初始化的全局变量,它的初值也存在于目标文件中)

####目标代码:
    C代码经过编码生成对应机器码序列,所有这些指令都用于处理某些信息,而这些信息得有地方存放---变量
    编译器只允许已经声明过的变量和函数

####链接器:
    确保变量和函数都已经在程序中定义过