#include <fcntl.h>
#include <stdio.h>
int main(void)
{   /*****************************************************************
    /*int open(const char*path,int oflag,.../*mode_t mode*/);
    /*int openat(int fd,const char*path,int oflag,.../*mode_t mode*/)
	/****************************************************************/
	/*FLAGS
    /*  O_RDONLY read-only 
    /*  O_WRONLY write-only
    /*  O_RDWR  read and write
    /*   most implementations define O_RDONLY as 0,O_WRONLY as 1,
    /*   O_RDWR as 2.
    /*  O_EXEC execute-only
    /*  O_SEARCH  search-onlyad\
    /****************************************************************/
    
    
    int fd = open("test.txt",O_RDONLY);
	printf("%d\n",fd);
	int rv = write(fd,"test",4);//return -1 
	printf("%d\n",rv);
}
