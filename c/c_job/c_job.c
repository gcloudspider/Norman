/*########################################################
##File Name: c_job.c
##Created Time:2015年12月08日 星期二 08时19分11秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>

void operation(){
    int x,y,z;
    x = 1;
    y = 1;
    z = 1;
    
    ++x || ++y && ++z;  
    //1.逻辑或具有从左向右的关联性。
    //2.在逻辑或表达式为true时，将消除对第二个操作数的不必要计算
    if((x>0)||(y<0)){
        printf("is true\n");
    } else {
        printf("is false\n");
    }
    
    if((x<0)||(y<0)){
        printf("is true\n");
    } else {
        printf("is false\n");
    }

    //3.逻辑或中任一操作数为true 返回布尔值true 否则返回false
    //4.操作数计算前隐式转换为类型bool

    printf("%d\n",x+y);
}

void foroperator(){
    int i,j;
    for(i=j=0;i<10&&j<8;i++,j+=3){
        printf("%d\t%d\n",i,j);
    }
}

void switchnobreak(){
    int a = 0,b=0,c=0,i;
    for(i=0;i<4;i++) { 
        switch(i){
            case 0:a=i++;   //由于没有break 则继续执行下面语句
            case 1:b=i++;
            case 2:c=i++;
            case 3:i++;
        } //遇到第二个for循环退出
        printf("%d,%d,%d,%d\n",a,b,c,i);
    }
}

void fornested(){
    int k,a;

    int fun1(){
        int k=20;
        return k;
    }
    int fun2(){
        int a = 15;
        return a;
    }
    printf("k=%d\ta=%d\n",k,a);
    
/*    func3(int a,int b){
        int k;
        k=(a-b)*(a+b);
        printf("%d\n",k);
    }*/

    func3(fun1(),fun2());
}


int main(){
    operation();
    foroperator();
    switchnobreak();
    fornested();
    return 0;
}
