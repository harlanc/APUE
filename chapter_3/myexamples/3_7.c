#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define RRR  (S_IRUSR| S_IRGRP|S_IROTH)
int main(void)
{
	/***************************************************
	 * POSIX.1
	 * ssize_t read(int fd,void *buf,size_t nbytes)
	 * ISO_C
	 * int read(int fd,char *buf,unsigned nbytes);
	 **************************************************/
	int fd = creat("/tmp/read.txt",RRR);
	int byteNumWrite = write(fd,"abcdefg",7);
	printf("The string \"abcdefg\" is write to read.txt,the real string length wrote to the file is %d\n",byteNumWrite);//result is 7
	close(fd);
	fd = open("/tmp/read.txt",O_RDONLY);
	char *buf = (char*)malloc(sizeof(char)*8);
	ssize_t byteNumRead = read(fd,buf,8);
	printf("The bytes read from read.txt is %d\n",(int)byteNumRead);//print result is 7
	close(fd);
    return 0;
}
