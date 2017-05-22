#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define RRR  (S_IRUSR| S_IRGRP|S_IROTH)

off_t getCurOffset(int fd)
{
	return lseek(fd,0,SEEK_CUR);
}

void printCurOffset(int fd)
{
	printf("the current file offset is %d\n",(int)getCurOffset(fd));
}

int main(void)
{
	/*****************************************************************
	 *ssize_t pread(int fd,void *buf,size_t nbytes,off_t offset);
	 *pread will not update the current file offset,see the following examples
	 *ssize_t pwrite(int fd,const void * buf,size_t nbytes,off_t offset);
	 *******************************************************************/
	int fd = creat("/tmp/pread.txt",RRR);
    int writeBytes = write(fd,"abcdefghij",10);
	close(fd);

	fd = open("/tmp/pread.txt",O_RDONLY);	
	printCurOffset(fd);
	char *buf = (char*)malloc(5);
	ssize_t readBytes = pread(fd,buf,4,2);
	buf[4]='\0';
	printf("Read %d bytes:%s\n",(int)readBytes,buf);
	printCurOffset(fd);
    return 0;
}
