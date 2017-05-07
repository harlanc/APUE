#include "../apue.h"
#include <fcntl.h>
int main(void)
{
	int fd1 = open("test.txt",O_RDONLY);
	int fd2 = dup(fd1);
	int fd3 = open("test.txt",O_RDONLY);
	printf("%d %d %d\n",fd1,fd2,fd3);
	struct stat buf;
	stat("test.txt",&buf);

	if(fcntl(fd1,F_SETFL,O_ASYNC)==-1)
	{
		err_sys("F_SETFL error");
	}
	int off_1 = lseek(fd1,0,SEEK_CUR);
	int off_2 = lseek(fd2,0,SEEK_CUR);
	int off_3 = lseek(fd3,0,SEEK_CUR);
	//printStat(buf);
	printf("file descriptor flag(fd1):%d\n",fcntl(fd1,F_GETFD));
	printf("file descriptor flag(fd2):%d\n",fcntl(fd2,F_GETFD));
	printf("file descriptor flag(fd3):%d\n",fcntl(fd3,F_GETFD));
	printf("file status (fd1):%d\n",fcntl(fd1,F_GETFL,0));
	printf("file status (fd2):%d\n",fcntl(fd2,F_GETFL,0));
	printf("file status (fd3):%d\n",fcntl(fd3,F_GETFL,0));
	printf("file offset(fd1):%d\n",off_1);
	printf("file offset(fd2):%d\n",off_2);
	printf("file offset(fd3):%d\n",off_3);
	if(fcntl(fd1,F_SETFD,FD_CLOEXEC)==-1)
	{
		err_sys("F_SETFD error");
	}
	if(fcntl(fd1,F_SETFL,O_NONBLOCK)==-1)
	{
		err_sys("F_SETFL error");
	}
	lseek(fd1,5,SEEK_CUR);

	off_1 = lseek(fd1,0,SEEK_CUR);
	off_2 = lseek(fd2,0,SEEK_CUR);
	off_3 = lseek(fd3,0,SEEK_CUR);
	//printStat(buf);
	printf("file descriptor flag(fd1):%d\n",fcntl(fd1,F_GETFD));
	printf("file descriptor flag(fd2):%d\n",fcntl(fd2,F_GETFD));
	printf("file descriptor flag(fd3):%d\n",fcntl(fd3,F_GETFD));

	printf("file status flag(fd1):%d\n",fcntl(fd1,F_GETFL,0));
	printf("file status flag(fd2):%d\n",fcntl(fd2,F_GETFL,0));
	printf("file status flag(fd3):%d\n",fcntl(fd3,F_GETFL,0));
	
	printf("file offset(fd1):%d\n",off_1);
	printf("file offset(fd2):%d\n",off_2);
	printf("file offset(fd3):%d\n",off_3);
	exit(0);
}
