#include "../apue.h"
#include <fcntl.h>

int main(void)
{
	int fd = open("a36.txt",O_RDWR|O_APPEND);
	char *text = "test";

    int dis = lseek(fd,5,SEEK_CUR);
	if(dis== -1)
	{
		err_sys("lseek error");
		exit(0);
	}
	char rd[10] = {0};
	int num = read(fd,rd,9);
	printf("%d:%s\n",num,rd);
	write(fd,text,strlen(text));
}
