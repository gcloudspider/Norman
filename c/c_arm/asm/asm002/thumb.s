	AREA text,CODE,READONLY
	ENTRY

	mov r0,#0
	mov r1,#8
loop
	add r0,r0,#1
	cmp r0,r1
	;moveq pc,pc
	bne loop

stop
	b stop
	
	END