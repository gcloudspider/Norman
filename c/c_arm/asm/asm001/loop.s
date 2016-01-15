	AREA test,CODE,READONLY
	
	ENTRY
	
	mov r0,#1
	mov r1,#8
loop
	cmp r0,r1
	ADD r0,r0,#1
	bne loop
stop
	b stop
		
		
	END