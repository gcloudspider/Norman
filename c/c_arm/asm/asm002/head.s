	AREA test,CODE,READONLY
	ENTRY
	
	;������ˮ�ߴ�ʱpc�Ĵ�����ֵΪ0x8008
	
	mov pc,pc   ;��pc�Ĵ�����ֵ��pc ����func��ִ��
	bl func
	
	mov r0,#1
	mov r2,#2 	;ȡַ--->����--->ִ��

stop
	b stop

func
	mov pc,lr
	END