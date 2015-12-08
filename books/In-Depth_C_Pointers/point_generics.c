/*########################################################
##File Name: point_generics.c
##Created Time:2015年12月07日 星期一 21时16分19秒
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
#include<string.h>
//泛型
void swap(void* bp1,void*bp2,int size){
    void buffer[size];
    memcpy(buffer,bp1,size);
    memcpy(bp1,bp2,size);
    memcpy(bp2,buffer,size);
}

int main(){
    int a = 10;
    int b = 12;
    printf("a=%d\tb=%d\n",a,b);
    swap(&a,&b,sizeof(int));
    printf("a=%d\tb=%d\n",a,b);
    return 0;
}
