#include "../apue.h"
#include <fcntl.h>
int main(int argc,char *argv[])
{
	if(argc != 2)
	  err_quit("usage: a.out <pathname>");
	int rv = access(argv[1],W_OK);
	if(rv<0)
	  err_ret("access error for %s",argv[1]);
	else
	  printf("read access OK\n");
	if(open(argv[1],O_RDWR)<0)
	  err_ret("open error for %s",argv[1]);
	else
	  printf("open for reading OK\n");
	exit(0);

}

