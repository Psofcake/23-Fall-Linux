#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define MAX_SIZE 1

int main(void) {
	int fd;
	char buf[MAX_SIZE];
	
	fd = open("/dev/my_virt_dev", O_RDWR);
	
	if (fd < 0) {
		printf("Fail: %s\n", strerror(errno));
		return 0;
	}

	char data = 6;

	write(fd, &data, 1);
	read(fd, buf, 1);
	printf("%d\n", buf[0]);

	close(fd);
	return 0;
}
