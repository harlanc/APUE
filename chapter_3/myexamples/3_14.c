#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
void printFD(int fd)
{
    printf("The fd num is %d\n",fd);
}

void printFDFlags(int fd,int fdflags)
{
    printf("The file description flags of  %d is %d\n",fd,fdflags);
}

void printFLFlags(int fd,int flflags)
{
    printf("The file status flags of  %d is %d\n",fd,flflags);
}


void F_DUPFD_fcntl()
{
    printf("F_DUPFD_fcntl()..........\n");
    int fd = open("/etc/passwd",O_RDONLY);
    int newfd = fcntl(fd,F_DUPFD,0);//equal to dup(fd)
    printFD(fd);
    printFD(newfd);
    close(fd);
    close(newfd);
}

/*void F_DUPFD_CLOEXEC_fcntl()
{
    int fd = open("/etc/passwd",O_RDONLY);
    int newfd = fcntl(fd,F_DUPFD_CLOEXEC,0);
    int fdI = fcntl(fd,F_GETFD,0);
    printFDI(fd,fdI);
    int newfdI = fcntl(newfd,F_GETFD,0);
    printFDI(newfd,newfdI);

}*/
void F_SET_FD_GET_FD_fcntl()
{
    printf("F_SETFD_GETFD_fcntl()..........\n");
    int fd = open("/etc/passwd",O_RDONLY);
    int fdflag = fcntl(fd,F_GETFD,0);
    printFDFlags(fd,fdflag);
    fcntl(fd,F_SETFD,1);
    fdflag = fcntl(fd,F_GETFD,0);
    printFDFlags(fd,fdflag);
}
/*********************************************************
* note  this command can change only the O_APPEND,
* O_ASYNC, O_DIRECT, O_NOATIME, and O_NONBLOCK flags
*******************************************************/
#define RWRWRW  (S_IRUSR|S_IWUSR| S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
void F_SETFL_GETFL_fcntl()
{
    printf("F_SETFL_GETFL_fcntl()..........\n");
    int fd = open("/etc/passwd",O_RDONLY);
    int flflag = fcntl(fd,F_GETFL);
    printFLFlags(fd,flflag);
    fcntl(fd,F_SETFL,O_APPEND);
    flflag = fcntl(fd,F_GETFL);
    printFLFlags(fd,flflag);
}
int main(void)
{
    /**********************************************/
    /* int fcntl(int fd,int cmd,...*//* int arg*///)
    /**********************************************/
    F_DUPFD_fcntl();

    //F_DUPFD_CLOEXEC_fcntl();
    F_SET_FD_GET_FD_fcntl();
    F_SETFL_GETFL_fcntl();
    return 0;


}
