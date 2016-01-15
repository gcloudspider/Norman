#############################################
####Create Date:2016.1.15 20:10:23
####Author:Norman
####
####Descript:ptrace工作原理
#############################################

####ptrace工作原理:
	Ptrace是Linux内核的一部分,所以它能够获取进程所有内核级信息
	
	*读写数据: 			copy_to /from_user
	*获取CPU寄存器: 	copy_regset_to/from_user  CPU寄存器在进程未被调度时保存在Linux的struct task_struct*调度结构中
	*修改信号处理:		更新域last_siginfo
	*单步执行:			在处理器出发执行前,设置进程task结构的right flag(ARM,x86)
	*ptrace 在很多计划中被Hooked (ptrace_event函数)
	PTRACE_O_TRACEEXEC选项和与它相关,向调试器发出一个SIGTRAP信号
	
