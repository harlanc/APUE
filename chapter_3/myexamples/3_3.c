#include <fcntl.h>
#include <stdio.h>
#define RWRWRW  (S_IRUSR |S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{   /*****************************************************************/
    //int open(const char*path,int oflag,.../*mode_t mode*/);
    //int openat(int fd,const char*path,int oflag,.../*mode_t mode*/)
	/****************************************************************/
	/*One of the following five flags must be specified:
    //  O_RDONLY read only
    //  O_WRONLY write only
    //  O_RDWR  read and write
    //   most implementations define O_RDONLY as 0,O_WRONLY as 1,
    //   O_RDWR as 2.
    //  O_EXEC execute-only
    //  O_SEARCH  search-only\
    ****************************************************************/
	/*The following ones are optional:
	 *  O_APPEND 
	 *  O_CLOEXEC
	 *  O_CREAT
	 *  O_DIRECTORY
	 *  O_EXEL
	 *  O_NOCTTY
	 *  O_NOFOLLOW
	 *  O_NONBLOCK
	 *  O_SYNC
	 *  O_TRUNC
	 *  O_TTY_INIT
	 *  O_DSYNC
	 *  O_RSYNC
	 * */
	int fd = openat(0,"/tmp/test.txt",O_WRONLY|O_CREAT,RWRWRW);//0 is ignored if path is absolute path.
    close(fd);    
    int dir_fd = open("/tmp",O_RDONLY);
	printf("%d\n",dir_fd);
	fd = openat(dir_fd,"test.txt",O_RDONLY);
	printf("%d\n",fd);
    
	fd = open("/tmp/test.txt",O_RDWR);
	printf("%d\n",fd);
	int rv = write(fd,"test",4); 
	printf("%d\n",rv);


    /*
	 *Test if a file exists
	 */

    fd = open("/tmp/test.txt",O_CREAT|O_EXCL);
	printf("The file exists,so the open result is %d\n",fd);





}
