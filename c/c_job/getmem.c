#include<stdio.h>
#include <sys/sysinfo.h>

int main(){
	struct sysinfo si;
	sysinfo(&si);
	printf("Load1:		%ld\n",si.loads[0]);
	printf("Load5:		%ld\n",si.loads[1]);
	printf("Load10:		%ld\n",si.loads[2]);
	printf("Totalram:	%ld\n",si.totalram);
	printf("Available:	%ld\n",si.freeram);
	printf("Bufferram:	%ld\n",si.bufferram);
	printf("Totalswap:	%ld\n",si.freeswap);
	printf("Totalhigh:	%ld\n",si.totalhigh);
	printf("Freehigh:	%ld\n",si.freehigh);
	
}
