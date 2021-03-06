/*########################################################
##File Name: CfileCompiler.c
##Created Time:2016年01月13日 星期三 08时48分58秒
##Author: Norman 
##Description: 示例程序:更简便的记忆方法
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

int main(){

/*未初始化的全局变量的定义*/
int x_global_uninit;

/*初始化的全局变量的定义*/
int x_global_init = 1;

/*静态未初始化全局变量,只能在当前C文件中访问*/
static int y_global_uninit;
/*已初始化的全局变量,只能在当前C文件中访问*/
static int y_global_init = 2;

/*存在于程序别处的某个全局变量的声明*/
extern int z_global;

/*这是一个在别处定义的函数(可以加extern关键字,但没有必要)*/
int fn_a(int x,int y);

/*函数前加static 限定只能在该C文件中访问*/
static int fn_b(int x){
    return x+1;
}

}
