#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proc_stat.h"
int main(int argc, char **argv) {
	pid_t pid = 4260;
	float cpu, mem;
	unsigned long long uptime;
	get_process_usage(pid,cpu,mem,uptime);
    return 0;    
}
