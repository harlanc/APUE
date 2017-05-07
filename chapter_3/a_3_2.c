#include "../apue.h"
int mydup(int fd,int fd2)
{
	if(fd == fd2)
	  return fd2;

    close(fd2);
	int *fdArray = (int*)malloc(fd2*sizeof(int));
	int index = 0;
	for(;index<=fd2;index++)
	{
		fdArray[index] = dup(fd);
		if(fdArray[index]<0)
		  err_sys("dup failed");
		else if(fdArray[index] == fd2)
		  break;
	}
	if(index > fd2)
	{
		err_sys("cannot dup2");
		return -1;
	}
	//index value is the file descriptor index,close the fds before index 
	for(int i=0;i<index;i++)
	{
		  close(fdArray[i]);

	}
	return fd2;
}
int main(void)
{
	mydup(0,3);
	exit(0);
}



