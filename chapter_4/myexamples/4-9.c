#include <fcntl.h>
#include <stdio.h>


void PrintSetUserID(unsigned int st_mode)
{
	if(st_mode&S_ISUID)
	{
	    printf("set-user-ID is 1.\n");
	}
	else
	{
	    printf("set-user-ID is 0.\n");
	}
}

void PrintSetGroupID(unsigned int st_mode)
{
	if(st_mode&S_ISGID)
	{
	    printf("set-group-ID is 1.\n");
	}
	else
	{
	    printf("set-group-ID is 0.\n");
	}
}
void ClearSetUserID_SetGroupID()
{

	struct stat statbuf;
	if(stat("chmod.txt",&statbuf)<0)
	  printf("stat error!-");
	else
	{
		PrintSetUserID(statbuf.st_mode);
		PrintSetGroupID(statbuf.st_mode);
	}
	int fd = open("chmod.txt",O_RDWR);
	ssize_t num = write(fd,"test",4);
	printf("write num:%d\n",(int)num);
	if(stat("chmod.txt",&statbuf)<0)
	  printf("stat error!--\n");
	else
	{
		PrintSetUserID(statbuf.st_mode);
		PrintSetGroupID(statbuf.st_mode);
	}
	printf("set user ID is");

}

void test()
{
    struct stat statbuf;
    if(stat("chmod.txt",&statbuf)<0)
	    printf("stat error!\n");
    int rv = chmod("chmod.txt",statbuf.st_mode & ~S_IRWXO);//remove the other's read write and execute
	if(rv < 0)
	{
	    printf("chmod error!\n");
	}
}


int main(void)
{
	ClearSetUserID_SetGroupID();
	return 0;
}

