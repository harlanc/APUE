#include <fcntl.h>
#include <stdio.h>

void printFD(int fd)
{
    printf("The fd num is %d\n",fd);
}

void printFDI(int fd,int fdI)

{
    printf("The file description identifer of %d is %d\n",fd,fdI);
}

void F_DUPFD_fcntl()
{
    int fd = open("/etc/passwd",O_RDONLY);
    int newfd = fcntl(fd,F_DUPFD,0);//equal to dup(fd)
    printFD(fd);
    printFD(newfd);
    close(fd);
    close(newfd);
}

void F_DUPFD_CLOEXEC_fcntl()
{
    int fd = open("/etc/passwd",O_RDONLY);
    int newfd = fcntl(fd,F_DUPFD_CLOEXEC,0);
    int fdI = fcntl(fd,F_GETFD,0);
    printFDI(fd,fdI);
    int newfdI = fcntl(newfd,F_GETFD,0);
    printFDI(newfd,newfdI);

}

int main(void)
{
    /**********************************************/
    /* int fcntl(int fd,int cmd,...*//* int arg*///)
    /**********************************************/
    //F_DUPFD_fcntl();

    F_DUPFD_CLOEXEC_fcntl();
    return 0;


}
