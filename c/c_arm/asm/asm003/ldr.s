	area test,code,readonly
	entry
	;立即数寻址 (值就在寄存器中无需寻址)
	;mov r0,#2
	;寄存器直接寻址
	;mov r0,r1
	
	
	;寄存器间接寻址
	mov r1,#0x5000 ;地址要求是4的整数倍
	;ldr r0,[r1]

	;ldrh r0,[r1]
	ldrb r0,[r1]
	
	;寄存器基址变址寻址
	;loader
	ldr r0,[r1,#4]	;r0=r1+4 相当于++i  #也可以是负数 --i
	
	ldr r0,[r1,#4]!  ;r0=r1+4 
	
	ldr r0,[r1],#4	;相当于i++
	
	;store
	mov r0,#0xFF
	str r0,[r1]
	end