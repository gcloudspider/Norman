.text
.global _start
_start:
	mov sp,#4096
    bl main

stop:
	b .	@=>b stop

