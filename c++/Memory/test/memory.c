/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

int bss_var;
int data_var0 = 1;

int main(){
    printf("below are address of type of process's mem\n");
    printf("Text location代码段:\n");
    printf("\tAddress of main(Code Segment):%p\n",main);
    printf("__________________________________\n");
    int stack_var0 = 2;
    printf("Stack Location栈段:\n");
    printf("\tInitial end of stack:%p\n",&stack_var0);
    int stack_var1 = 3;
    printf("\t new end of stack:%p\n",&stack_var1);
    printf("__________________________________\n");
    printf("Data Location:数据段\n");
    printf("\tAddress of data_var(Data Segment):%p\n",&data_var0);
    static int data_var1= 4;
    printf("\t NEW ned of data_var(Data Segment):%p\n",&data_var1);
    printf("__________________________________\n");
    printf("BSS Location:bss段\n");
    printf("\tAddress of bss_var:%p\n",&bss_var);
    printf("__________________________________\n");
    char *b = sbrk((ptrdiff_t)0);
    printf("Heap Location:\n");
    printf("\t Initial end of heap:%p\n",b);
    brk(b+4);
    b=sbrk((ptrdiff_t)0);
    printf("\tNew end of heap:%p\n",b);
    return 0;
}
