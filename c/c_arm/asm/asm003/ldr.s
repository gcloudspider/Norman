	area test,code,readonly
	entry
	;������Ѱַ (ֵ���ڼĴ���������Ѱַ)
	;mov r0,#2
	;�Ĵ���ֱ��Ѱַ
	;mov r0,r1
	
	
	;�Ĵ������Ѱַ
	mov r1,#0x5000 ;��ַҪ����4��������
	;ldr r0,[r1]

	;ldrh r0,[r1]
	ldrb r0,[r1]
	
	;�Ĵ�����ַ��ַѰַ
	;loader
	ldr r0,[r1,#4]	;r0=r1+4 �൱��++i  #Ҳ�����Ǹ��� --i
	
	ldr r0,[r1,#4]!  ;r0=r1+4 
	
	ldr r0,[r1],#4	;�൱��i++
	
	;store
	mov r0,#0xFF
	str r0,[r1]
	end