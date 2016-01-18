@cpu_mode
.text
.global _start
_start:
    /** set the cpu to SVC32 mode*/
    mrs r0,cpsr 
    bic r0,r0,#0x1f
    orr r0,r0,#0xd3
    msr cpsr,r0
    and r1,r0,#0b10011
    cmp r1,#0b10011
    bleq led_on

main_loop:
    b main_loop

led_on:
    ldr r0,=0x56000010
    mov r1,#0x15400
    str r1,[r0]
    ldr r0,=0x56000014
    mov r1,#0x100
    str r1,[r0]
    mov pc,lr
    
