#include <sys/types.h>
#include <fcntl.h>
#include <linux/cdrom.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int ret;
	char *buf = (char*)malloc(sizeof(char)*80);
	//int fd = open("/dev/sr0", O_RDWR); // sr0 : cd-rom 
	int fd = open("/dev/sr0", O_RDWR|O_NONBLOCK); //
	printf("fd: %d\n", fd);

	while(1) {
		ret = read(fd, buf, 80);
		if( ret ) {
			write(STDOUT_FILENO, buf, ret);
		} else {
			write(STDOUT_FILENO, "No DATA", 7);
		}
		usleep(500000);
	}

	close(fd);
	return 0;
}
