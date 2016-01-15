	AREA test,CODE,READONLY
	ENTRY
	
	;由于流水线此时pc寄存器的值为0x8008
	
	mov pc,pc   ;将pc寄存器的值给pc 所以func不执行
	bl func
	
	mov r0,#1
	mov r2,#2 	;取址--->译码--->执行

stop
	b stop

func
	mov pc,lr
	END