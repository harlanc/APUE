#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	/*
	 *off_t lseek(int fd,off_t offset,int whence);
	 * */
	int fd = open("/etc/passwd",O_RDONLY);
	int len = lseek(fd,0,SEEK_END);
	printf("The file /etc/passwd 's length is %d\n",len);
    //back to the beginning of the file
	int zero = lseek(fd,0,SEEK_SET);
	printf("The offset of the beginning of the file is %d\n",zero);
	int mid = lseek(fd,len/2,SEEK_CUR);
	printf("Move to the middle of the file %d\n",mid);
}
