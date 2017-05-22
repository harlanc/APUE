#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#define RRR  (S_IRUSR| S_IRGRP|S_IROTH)
#define RWRWRW  (S_IRUSR|S_IWUSR| S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

void printfdInfo(int fd)
{
	printf("fd num %d\n",fd);
	printf("get FL of /etc/passwd %d\n",fcntl(fd,F_GETFL));
	printf("get FD of /etc/passwd %d\n",fcntl(fd,F_GETFD));
}

void execRead(int fd)
{
    char fdString[4]={0};
    sprintf(fdString,"%d",fd);

    int pid = 0;
    int status = 0;

    if((pid=fork()) != 0)//father process
    {
        //wait for child process finish
        waitpid(pid,&status,0);
    }
    else//child process
    {
        if(execl("read",fdString,NULL)<0)//fd is open in child process
            perror("issue read failed.");
    }
}

void test_FD_CLOEXEC()
{
    //open success
    int fd = open("/etc/passwd",O_RDONLY);
    printfdInfo(fd);//fd is 0

    execRead(fd);//read success

    fcntl(fd,F_SETFD,FD_CLOEXEC);
    printfdInfo(fd);//fd is 1,the fd is closed in child process.

    execRead(fd);//read failed

    close(fd);
}

void test_dup()
{
    int fd = open("/etc/passwd",O_RDONLY);
    int dupfd = dup(fd);
    //FD and FL are all the same.
    printfdInfo(fd);
    printfdInfo(dupfd);
}
void test_dup2()
{
    int fd = open("/etc/passwd",O_RDONLY);
    fcntl(fd,F_SETFD,FD_CLOEXEC);
    int newfd = dup2(fd,13);
    execRead(fd);//read failed,fd is closed.
    execRead(newfd);//the FD_CLOEXEC is cleared.
    close(fd);
    close(newfd);
}

int main(void)
{
    printf("test_FD_CLOEXEC.....................\n");
    test_FD_CLOEXEC();
    printf("test_dup.....................\n");
    test_dup();
    printf("test_dup2.....................\n");
    test_dup2();
    return 0;
}

