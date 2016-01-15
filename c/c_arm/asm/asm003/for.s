	AREA test,CODE,READONLY
	ENTRY
	
	mov r0,#0x4000
	mov r2,#0x5000
	mov r3,#0			;i=0
	
loop
	cmp r3,#6			;if(i==6)
	ldrneb r1,[r0],#1	;
	strneb r1,[r2],#1
	addne r3,r3,#1     ;i++

	bne loop
	
stop
	b stop	
	
	END