@关闭看门狗
.text
.global _start
_start:
    bl watchclose

    bl watchopen

loop:
    b loop                          @死循环



watchclose:
    ldr r0,=0x53000000              @WTCON寄存器地址加载到r0
    mov r1,#0                       @r1 = 0
    str r1,[r0]                     @将r1里的值存到r0里地址里

watchopen:
    ldr r0,=0x53000000              @加载WTCON寄存器地址
    @0x4a21=[15:8]=74,[5]=1,[0]=1

    ldr r1,=0x4a21                  @将0x4a21保存到r1里

    str r1,[r0]                     @将r1里的值存入r0指向的地址

    @设置看门狗计数寄存器,该寄存器的值在上电后被加载,1秒超时

    ldr r2,=0x53000008              @加载WTCNT寄存器地址

    ldr r3,=0x2710                  @将0x2710保存到r1里

    str r3,[r2]                     @将r3里的值存入r2指向的地址

    bl led_on                        @调用led_on代码

led_on:
    ldr r0,=0x56000010
    mov r1,#0x15400
    str r1,[r0]

    ldr r0,=0x56000014
    mov r1,#0x100
    str r1,[r0]
    mov pc,lr
