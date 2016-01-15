	AREA text,CODE,READONLY
	ENTRY
	
arm
	ldr r9,=arm_32		;将地址放入r9
	mov r0,#0
	mov r1,#1
	mov r2,#2
	ldr r8,=thumb+1		;
	bx r8
	;bl跳转指令,跳转之前会在寄存器R14保存PC当前内容
	;bx 跳转到指令中所指定目标,目标地址可以是Arm或Thumb指令

	
thumb
	CODE16
	mov r3,#3
	mov r4,#4
	mov r5,#5
	;bx r9
	blx r9
	;1.blx 指令从Arm 指令集跳转到指令中所指定目标地址,
	;2.并将处理器工作状态从arm状态改为thumb状态
	;3.同时pc 当前内容保存到寄存器R14中
	
	b arm_32
	CODE32		;伪指令
	
arm_32
	mov r6,#6
	mov r7,#7
	
stop
	b stop
	
	
	END