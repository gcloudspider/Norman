	AREA test,CODE,READONLY
	ENTRY
reset
	bl enable_irq	;bl 跳转并r14
	mov r1,#100
	
	bl disable_irq
	mov r1,#200
	
stop
	b stop
	
enable_irq
	mrs r0,cpsr		;将cpsr 读到r0
	bic r0,r0,#0x80  ;位清零(取反 与)
	msr cpsr_c,r0	;将r0 cpsr_c 写入到低8位
	mov pc,lr		;跳转
	
disable_irq
	mrs r0,cpsr
	orr r0,r0,#0x80	;逻辑或操作
	msr cpsr_c,r0
	mov pc,lr
	
	
	END