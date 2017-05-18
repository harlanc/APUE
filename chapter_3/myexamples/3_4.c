#include <stdio.h>
#include <fcntl.h>
#define RWRWRW  (S_IRUSR |S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#define RRR  (S_IRUSR| S_IRGRP|S_IROTH)
int main(void)
{   
	/********************************************
	 * int creat(const char *path,mode_t mode); 
	 * is equal to 
	 * open(path,O_WRONLY|OCREAT|O_TRUNC,mode)
	 * *****************************************/
	int fd = creat("/tmp/creat.txt",RRR);//-r--r--r-- 1 harlan harlan 0  5月 18 21:49 creat.txt
	printf("%d\n",fd);
	fd = creat("/tmp/creatRW.txt",RWRWRW);//umask 0002 -rw-rw-r-- 1 harlan harlan 0  5月 18 21:51 creatRW.txt
	printf("%d\n",fd);
	return 0;
}
