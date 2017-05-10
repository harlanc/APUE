#include <fcntl.h>
#include "apue.h"
int main(int args,char *argv[])
{
	if(args!=2)
	  err_sys("the parameter number is not correct!");
	int num = atoi(argv[1]);
	char path[100] = "/github/APUE/chapter_";
	strcat(path,argv[1]);
	int fd = open(path,O_RDONLY);
	if(fchdir(fd)<0)
	{
		err_sys("change dir failed");
	}
	//int len = strlen(path);
	//strcat(path,argv[1]);
	//system(path);
    exit(0);
}
