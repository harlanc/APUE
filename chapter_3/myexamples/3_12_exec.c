#include <stdio.h>

int main(int argc,char *argv[])
{
	if(1!=argc)
	{
		printf("The parameter number is not correct!");
        return -1;
	}
    //get the file descriptor
	int fd = atoi(argv[0]);
    char buf[100]={0};
	int NumReadBytes = read(fd,buf,5);
	printf("The number of byte %d: %s\n",NumReadBytes,buf);

}
