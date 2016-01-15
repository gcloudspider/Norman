	extern load
	extern ldm_stm
	extern callback
	AREA init,CODE,READONLY
	ENTRY
	
	;bl ldm_stm
	
	mov sp,#0x4000
	bl callback
	
stop
	b stop
	
	END