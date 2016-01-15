	AREA test,CODE,READONLY
	ENTRY
reset
	bl enable_irq	;bl ��ת��r14
	mov r1,#100
	
	bl disable_irq
	mov r1,#200
	
stop
	b stop
	
enable_irq
	mrs r0,cpsr		;��cpsr ����r0
	bic r0,r0,#0x80  ;λ����(ȡ�� ��)
	msr cpsr_c,r0	;��r0 cpsr_c д�뵽��8λ
	mov pc,lr		;��ת
	
disable_irq
	mrs r0,cpsr
	orr r0,r0,#0x80	;�߼������
	msr cpsr_c,r0
	mov pc,lr
	
	
	END