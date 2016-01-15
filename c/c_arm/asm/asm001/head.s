	AREA test,CODE,READONLY
	ENTRY
	
	;mov r0,#10
	;mov r1,#20
	;add r2,r0,r1
	
	;subs r2,r0,r1
	
	mov r0,#0
	mov r1,#8

loop
	subs r2,r0,r1		;r2=r0-r1
	;if(s)
	;	if(r0==r1) cpsr_z =1
	
	beq stop 			;if(cpsr_z == 1) goto stop
	add r0,r0,#1
	b loop				;goto loop
	
	
stop
	b stop
	END