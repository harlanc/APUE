#include "../apue.h"
#include <fcntl.h>
int main(void)
{
	int fd1 = open("test.txt",O_RDONLY);
	int fd2 = dup(fd1);
	int fd3 = open("test.txt",O_RDONLY);
	printf("%d %d %d",fd1,fd2,fd3);
	struct stat buf;
	stat("test.txt",&buf);
	
	exit(0);
}
