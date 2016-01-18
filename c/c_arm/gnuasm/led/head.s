.text
.global _start

_start:
    mov sp,#4096
    ldr r0,=0x56000010  
    
    @r0设为GPBCON寄存器
    @此寄存器用于选择端口B各引脚的功能:输出/输入还是其他

    mov r1,#0x15400
    str r1,[r0]         @设置GPB5为输出口
    ldr r0,=0x56000040  
    @r0设为GPBDAT寄存器---此寄存器用于读写端口B各引脚的数据

    mov r1,#0x00000000  @此值改为0x00000020 让LED1熄来
    str r1,[r0]         @GPB5输出0
    
    @GPB5输出0 LED1点亮首先将GPB5  GPB6 GPB7 GPB8引脚都设置成输出模式，所以bit17到bit10设置成01010101
    @即0x15400=b1010101000000000

stop:
    b . @=> b stop

