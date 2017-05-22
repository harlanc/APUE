#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#define RRR  (S_IRUSR| S_IRGRP|S_IROTH)
#define RWRWRW  (S_IRUSR|S_IWUSR| S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

void printfdInfo(int fd)
{
	printf("fd num %d\n",fd);
	printf("get FL of dup.txt %d\n",fcntl(fd,F_GETFL));
	printf("get FD of dup.txt %d\n",fcntl(fd,F_GETFD));
}

int main(void)
{
	remove("/tmp/dup.txt");
	//write success
    int fd = creat("/tmp/dup.txt",RRR);
	printfdInfo(fd);//3 1
	int numWrite = write(fd,"abcd",4);
    close(fd);
    //open success
	fd = open("/tmp/dup.txt",O_RDONLY);
	printfdInfo(fd);// 3 0
	close(fd);
    //open failed
	fd = open("/tmp/dup.txt",O_WRONLY);
	printfdInfo(fd); //-1 -1
	close(fd);
    //open failed
	fd = open("/tmp/dup.txt",O_RDWR);
	printfdInfo(fd);//-1 -1
	close(fd);
    
	remove("/tmp/dup.txt");
    //write success
    fd = creat("/tmp/dup.txt",RWRWRW);
    printfdInfo(fd);//3 1
    numWrite = write(fd,"abcd",4);
    close(fd);
    //open success
    fd = open("/tmp/dup.txt",O_RDONLY);
    printfdInfo(fd);// 3 0
    close(fd);
    //open success
    fd = open("/tmp/dup.txt",O_WRONLY);
    printfdInfo(fd); //3 1
    close(fd);
    //open success
    fd = open("/tmp/dup.txt",O_RDWR);
    printfdInfo(fd);//3 2
    close(fd);


	//numWrite = write(fd,"bbbbb");
	//printf("write number %d\n",numWrite);

	//int flNum = fcntl(fd,F_GETFL);
	//printf("get FL of dupa.txt %d\n",flNum);
}
