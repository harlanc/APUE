#include <unistd.h>
#include <fcntl.h>
#define RWRWRW  (S_IRUSR |S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
//#define  _POSIX_CHOWN_RESTRICTED -1

int main(void)
{
	umask(0);//remove the mask
    int rv = creat("source.txt",RWRWRW);//creat a file whose mode is -rw-rw-rw-
	system("ln -s source.txt source_l.txt");//create a soft link to "source.txt" whose mode is lrwxrwxrwx
	rv = chown("source.txt",-1,0);
	return 0;
}
