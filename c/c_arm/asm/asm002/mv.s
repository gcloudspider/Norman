	AREA text,CODE,READONLY
	ENTRY
	
arm
	ldr r9,=arm_32		;����ַ����r9
	mov r0,#0
	mov r1,#1
	mov r2,#2
	ldr r8,=thumb+1		;
	bx r8
	;bl��תָ��,��ת֮ǰ���ڼĴ���R14����PC��ǰ����
	;bx ��ת��ָ������ָ��Ŀ��,Ŀ���ַ������Arm��Thumbָ��

	
thumb
	CODE16
	mov r3,#3
	mov r4,#4
	mov r5,#5
	;bx r9
	blx r9
	;1.blx ָ���Arm ָ���ת��ָ������ָ��Ŀ���ַ,
	;2.��������������״̬��arm״̬��Ϊthumb״̬
	;3.ͬʱpc ��ǰ���ݱ��浽�Ĵ���R14��
	
	b arm_32
	CODE32		;αָ��
	
arm_32
	mov r6,#6
	mov r7,#7
	
stop
	b stop
	
	
	END