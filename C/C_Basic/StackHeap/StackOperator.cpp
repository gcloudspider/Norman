#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20


struct SqStack {
	int *data;
	int memnum;
	int size;
};


void InitStack(SqStack &s,int size) {
	s.data = new int[size];
	if(s.data == NULL)
		return;
	s.memnum = 0;
	s.size = size;
}

void ClearStack(SqStack &s) {
	delete[]s.data;
}
/*
int StackEmpty(SqStack &s) {
	return (s->data);
}
*/
void DispStack(SqStack &s) {
	int i;
	for(i=0;i<10;i++) {
		printf("%p\t%d\t%d\n",&s.data[i],s.memnum,s.size);
	}
}

int PushStack(SqStack &s,int mem) {
	if(s.memnum == s.size)
		return 0;

	s.data[s.memnum++]=mem;
	return 1;
}

int PopStack(SqStack &s,int &num) {
	if(s.memnum == 0)
		return 0;
	num = s.data[--s.memnum];
	return 1;
}

int main() {
	int i,num;
	SqStack S;
	char ch;
	InitStack(S,10);
	printf("Stack Inited In Memory Size:%d\n",sizeof(&S));
	for(i=0;i<10;i++) {
		PushStack(S,i);
	}
	DispStack(S);
	
	for(i=0;i<10;i++) {
		if(PopStack(S,num));
	}
	return 0;
}
