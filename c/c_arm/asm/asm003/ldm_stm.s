	export ldm_stm
	export callback
	AREA ldm,CODE,READONLY
	
ldm_stm
	mov r0,#0x4000
	ldmia r0!,{r1,r2,r3,r4,r5,r6}  ;!������ַ��д��r0
	;ldmia r0!,{r1-r6,r8,r12}
	
	mov r0,#0x5000
	stmia r0,{r1-r6}
	
return
	mov pc,lr
	
callback
	stmfd sp!,{lr}   ;���ݼ�ѹջ
	bl callback1
	ldmfd sp!,{lr}	 ;���ݼ���ջ
	mov pc,lr
	
callback1	
	mov pc,lr
	
	END