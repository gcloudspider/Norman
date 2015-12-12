/*########################################################
##File Name: sysprintcolor.c
##Created Time:2015年12月12日 星期六 13时27分17秒
##Author: Norman 
##Description:  打印出颜色
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
#include<stdlib.h>
#include<stdarg.h>

#define RESET 0
#define BRIGHT 1
#define DIM 2
#define UNDERLINE 4
#define BLINK 5
#define REVERSE 7
#define HIDDEN 8

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7



int main(){
    int i=0;
    int color = 31;
    for(i=0;i<7;i++){
        printf("\033[40;%dmHello, world.\033[0m\n", color);
    }
    return 0;
}

