#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#define RWRWRW  (S_IRUSR |S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int main(void)
{
	int fd = creat("test4-7.txt",RWRWRW);
	printf("uid = %d,gid=%d,euid=%d,egid=%d\n",getuid(),getgid(),geteuid(),getegid());
}
