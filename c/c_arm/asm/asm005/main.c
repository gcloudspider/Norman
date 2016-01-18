
char* my_strcpy(char* dst,const char* src){
	char* t = dst;
	__asm{
	loop:
		ldrb r2,[r1],#1
		strb r2,[r0],#1
		cmp r2,#0
		bne loop
	};
	return t;
}

char s[8]="abcde";
char d[8];


int Main(){	
	my_strcpy(d,s);
	
	return 0;	
}