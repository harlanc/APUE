#include <fcntl.h>
#include <stdio.h>
int main(void)
{   /**************************

	  *************************/
	int fd = open("test.txt",O_RDONLY);
	printf("%d\n",fd);
	int rv = write(fd,"test",4);//return -1 
	printf("%d\n",rv);
}
