	import Main
	AREA init,CODE,READONLY
	ENTRY
	
	mov sp,#4096
	bl Main
	
stop
	b stop	
	
	END
	