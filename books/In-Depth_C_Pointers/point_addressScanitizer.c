/*########################################################
##File Name: point_addressScanitizer.c
##Created Time:2015年11月23日 星期一 09时16分32秒
##Author: Norman 
##Description: 
##gcc 4.8的一个很酷的新特性是内建的“地址消毒剂”：C/C++的内存错误检测器
##
##在编译器调用中添加-fsanitize=address -fno-omit-frame-pointer
##在链接器调用中添加-fsanitize=address
##
##AddressSanitizer     , a fast memory error detector, 
##has been added and can be     enabled via -fsanitize=address. 
##Memory access     instructions will be instrumented to detect heap-, ##stack-, and     global-buffer overflow as well as use-after-free bugs. 
##To get     nicer stacktraces, use -fno-omit-frame-pointer.
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

