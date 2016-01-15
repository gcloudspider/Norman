	area test,code,readonly
	ENTRY
	
	mov r0,#0xff
	
	bic r0,r0,#0xff
	
	mov r1,#0xFF
	mov r2,#0xFF0
	
	mov r3,#0xF000000F
	mov r5,#0x1f8
	
	mov r0,#0xF0000000
	mov r1,#0x00000001
	
	mov r2,#0x10000000
	mov r3,#0x00000001
	
	adds r4,r0,r2
	adc r5,r1,r3
	
	END