	import Main
	AREA init,CODE,READONLY
	ENTRY
	
	
start
	mov sp,#4096 		;初始化sp 4K空间
	bl Main				;跳转到C语言Main函数
	
stop
	b stop
	
	END