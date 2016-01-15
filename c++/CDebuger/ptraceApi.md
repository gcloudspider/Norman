#############################################
####Create Date:2016.1.15 20:10:23
####Author:Norman
####
####Descript:调试器工作原理
#############################################

####Linux Ptrace API
	1.Linux Ptrace API允许一个(调试器)进程来获取低等级的其他(被调试)进程信息。
	2.读写被调试进程的内存:
		2.1:PTRACE_PEEKTEXT
		2.2:PTRACE_PEEKUSER
		2.3:PTARCE_POKE....
	3.读写被调试进程的CPU寄器
		3.1:PTRACE_GETREGSET
		3.2:PTRACE_SETREGS
	4.因系统活动而被提醒:
		4.1:PTRACE_O_TRACEEXEC		--EXEC执行
		4.2:PTRACE_O_TRACECLONE		--克隆
		4.3:PTRACE_O_EXITKILL 		--退出
		4.4:PTRACE_SYSCALL
		(可以通过这些标识区分exec syscall clone exit以及其他系统调用)
	5.控制它的执行:
		5.1:PTRACE_SINGLESTEP     ---单步
		5.2:PTRACE_KILL
		5.3:PTRACE_INTERRUPT
		5.4:PTRACE_CONT
		(单步执行)
	6.修改它的信号处理:
		6.1:PTRACE_GETSIGNINFO
		6.2:PTRACE_SETSIGNINFO