

int add(int a,int b){
	int c;
	c = a+b;
	return c;
}

int main(){
	//	r0 	 r1
	int a=10,b=20;
	int c; //r2
	c=add(a,b);
}

stm sp!,{r0-r3}  //��r0-r3ѹջ
add r2,r0,r1	
mov r0,r2		//return
mov pc,lr 		//���ص�ǰһ��ָ��
ldm sp!,{r0-r3} 	//��ջ
mov r2,r0