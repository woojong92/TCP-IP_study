#include <stdio.h>
#include <stdlib.h>
#include <stat.h>
#include <string.h>
#include <unistd.h>

int main() {
	int ret;
	char *buf = (char*)malloc(sizeof(char)*80);
	pid_t pid;
	int pfd[2];
	pipe(pfd);

	if((pid = fork()) == 0) {
		dup2(STDIN_FILENO, pid[0]);
	}else {
		dup2(STDOUT_FILENO, pfd[1]);
	
		while (1) {
			bzero(buf, sizeof(buf)); //
			ret = read(STDIN_FILENO, buf, sizeof(buf));
			if ( ret > 0 ) {
				ret = write(STDOUT_FILENO, buf, ret);
			}
		}
	}
	free(buf);
}

