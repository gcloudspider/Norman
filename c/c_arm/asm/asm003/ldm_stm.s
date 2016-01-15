	export ldm_stm
	export callback
	AREA ldm,CODE,READONLY
	
ldm_stm
	mov r0,#0x4000
	ldmia r0!,{r1,r2,r3,r4,r5,r6}  ;!将最后地址回写到r0
	;ldmia r0!,{r1-r6,r8,r12}
	
	mov r0,#0x5000
	stmia r0,{r1-r6}
	
return
	mov pc,lr
	
callback
	stmfd sp!,{lr}   ;满递减压栈
	bl callback1
	ldmfd sp!,{lr}	 ;满递减出栈
	mov pc,lr
	
callback1	
	mov pc,lr
	
	END