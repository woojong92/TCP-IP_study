#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <linus/cdrom.h>

int main(){
	int fd;
	size_t ret;
	char *str = (char*)malloc(sizeof(char)*256);

	//fd = open("./fd_test.c", O_RDWR);
	fd = open("/dev/sr0", O_RDWR|O_NDELAY);

	//printf("fd: %d\n", fd);
	sprintf(str, "fd: %d\n", fd);
	ret = write(1, str, strlen(str));

	ioctl(fd, CDROMEJECT, 0);
	
	close(fd);
}
