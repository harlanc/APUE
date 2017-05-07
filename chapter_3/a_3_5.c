#include "../apue.h"
#include <fcntl.h>
int main(void)
{
    int file = open("3_5.txt",O_RDWR|O_CREAT);
	int dd = fcntl(file,F_GETFD,0);
    printf("%d\n",dd);
	int fd = dup2(1,file);
    
	dd = fcntl(file,F_GETFD,0);
	
    printf("%d\n",dd);
	//int fd2 = dup2(1,2);
	//printf("test\n");
	//err_sys("err_test\n");
	exit(0);
}
