#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#define RWRWRW  (S_IRUSR |S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
//#define  _POSIX_CHOWN_RESTRICTED -1

void test_lchown()
{
	 umask(0);//remove the mask
	 int rv = creat("source.txt",RWRWRW);//creat a file whose mode is -rw-rw-rw-
     system("ln -s source.txt source_l.txt");//create a soft link to "source.txt" whose mode is lrwxrwxrwx
     rv = lchown("source_l.txt",0,0);
     printf("rv:%d\n",rv);
     printf("errno:%d\n",errno);
}
void test_chownGID()
{
	int rv = creat("testGID.txt",RWRWRW);
	if(rv<0)
	{
		printf("create file error!\n");
	}
	struct stat statbuf;
	if(stat("testGID.txt",&statbuf)<0)
	{
		printf("stat error!\n");
	}
	else
	{
		printf("The current user's group ID is %d\n",statbuf.st_gid);
	}
	rv = chown("testGID.txt",-1,1001);
    printf("rv:%d\n",rv);
	if(stat("testGID.txt",&statbuf)<0)
	{
		printf("stat error!\n");
	}
	else
    {
		printf("After chown,the user's group ID is %d\n",statbuf.st_gid);
	}
}

void printGroups()
{
	gid_t list[20];
	int x,i;
	x =getgroups(0,list);
	getgroups(x,list);
	for(i=0;i<x;i++)
	{
		printf("%d:%d\n",i,list[i]);
	}
}

int main(void)
{
	//printGroups();
    test_chownGID();
	return 0;
}
