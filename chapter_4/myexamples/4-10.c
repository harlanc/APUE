#include <fcntl.h>
#include <stdio.h>

void main()
{
	struct stat statbuf;
	if(stat("dir",&statbuf))
	  printf("stat error!\n");

	if(statbuf.st_mode & S_ISVTX)
	{
		printf("sticky bit is set!\n");
	}

	if(statbuf.st_mode & S_IXOTH)
	{
		printf("other execute bit is set!\n");
	}
}
