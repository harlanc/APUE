#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>
int main(void)
{
	/*****************************
	 * print file descriptors for 
	 * standard input
	 * standard output
	 * standard err
	 * *************************/
	printf("%d\n",STDIN_FILENO);
	printf("%d\n",STDOUT_FILENO);
	printf("%d\n",STDERR_FILENO);
    //printf("%d\n",OPEN_MAX); OPEN_MAX is removed from 
    /*************************************
    * how to get the OPEN_MAX value
    ************************************/
	struct rlimit limit;
	if(getrlimit(RLIMIT_NOFILE,&limit)==-1)
	  perror("getrlimit");
	printf("getrlimit=%d\n",(int)limit.rlim_cur);
	
	return 0;
}
