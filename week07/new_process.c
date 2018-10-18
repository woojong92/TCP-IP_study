#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int global =10;

int main(){
	int local = 5;
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error\n");
		exit(-1);
	}else if(pid == 0) {
		global++;
		local++;
	}else sleep(2);

	printf("pid: %d, global: %d, local: %d\n", getpid(), global, local);
	return 0;
}

