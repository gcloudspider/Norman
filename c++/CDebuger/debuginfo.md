#############################################
####Create Date:2016.1.15 21:10:23
####Author:Norman
####
####Descript:处理符号与调试信息
#############################################

####信号和调试信息处理:
	1.可以不使用调试信息和信号地址来调试.
	所以低级指令是对CPU寄存器和内存地址来操作.不是源程序层面的信息。
	二进制汇编指令和内存字节 GDB不需要进一步把信息来把二进制信息翻译成CPU指令
	
	(gdb) x/10x $pc#heXadecimal representation
	
	(gdb) x/10i $pc#Instruction representation
	
	(gdb)$pc
	$1 = (void(*)())0x402c60<main>
	
	GDB 能够展示堆栈跟踪信息
	(gdb) where