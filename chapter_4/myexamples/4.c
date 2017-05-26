#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
/***************************************************************/
 /*struct stat {*/                                                                    
 /* unsigned long   st_dev; */    /* Device.  */                                   
 /* unsigned long   st_ino;*/     /* File serial number.  */                       
 /* unsigned int    st_mode;  */  /* File mode.  */                                
 /* unsigned int    st_nlink;  */ /* Link count.  */                               
 /* unsigned int    st_uid;    */ /* User ID of the file's owner.  */              
 /* unsigned int    st_gid;    */ /* Group ID of the file's group. */              
 /* unsigned long   st_rdev;    *//* Device number, if device.  */                 
 /* unsigned long   __pad1;   */                                                   
 /* long        st_size;    *//* Size of file, in bytes.  */                       
 /* int     st_blksize; *//* Optimal block size for I/O.  */                       
 /* int     __pad2;         */                                                     
 /* long        st_blocks;*/  /* Number 512-byte blocks allocated. */              
 /* long        st_atime;  */ /* Time of last access.  */                          
 /* unsigned long   st_atime_nsec; */                                              
 /* long        st_mtime;  */ /* Time of last modification.  */                    
 /* unsigned long   st_mtime_nsec;*/                                               
 /* long        st_ctime;  */ /* Time of last status change.  */                   
 /* unsigned long   st_ctime_nsec;  */                                             
 /* unsigned int    __unused4;     */                                              
 /* unsigned int    __unused5;                                                   
					};                                                                               
 * */

void printMode(unsigned int st_mode,int indent)
{
	int num = 0;
	for(;num<indent;num++)
	{
		printf("  ");
	}
	printf(S_ISDIR(st_mode)?"d":"-");
	printf(st_mode&S_IRUSR?"r":"-");
	printf(st_mode&S_IWUSR?"w":"-");
	printf(st_mode&S_IXUSR?"x":"-");
	printf(st_mode&S_IRGRP?"r":"-");
	printf(st_mode&S_IRGRP?"w":"-");
	printf(st_mode&S_IRGRP?"x":"-");
	printf(st_mode&S_IROTH?"r":"-");
	printf(st_mode&S_IROTH?"w":"-");
	printf(st_mode&S_IROTH?"x":"-");
}

void printFileName(char *name)
{
	printf(" %s\n",name);
}

void printUserName(unsigned int userId)
{
	struct passwd *pwd = getpwuid(userId);
    printf(" %s", pwd->pw_name);
}
void printGroupName(unsigned int grpId)
{
	struct  group *grp = getgrgid(grpId);
    printf(" %s" ,grp->gr_name);
}
void printSize(long size)
{
	printf(" %lu",size);
}
void printModifyTime(long mtime)
{
	/*char buf[100]={0};
	ctime_s(buf,26,mtime);
	printf(" %s",buf);*/
	printf(" %lu",mtime);
}
int ls(char *path,int depth,int indent)
{
    DIR *dhandle;
    struct dirent *file;
    struct stat st;

    if(!(dhandle=opendir(path)))
    {
        printf("error opendir %s\n",path);
		return -1;
    }
	while((file = readdir(dhandle))!=NULL)
	{
	    int fullPathLen = strlen(path)+strlen(file->d_name)+1;
       	    if(strncmp(file->d_name,".",1)==0)
		  continue;
	    char *fullpath = (char*)malloc(fullPathLen+1);
	    memset(fullpath,0,fullPathLen+1);
	    strcpy(fullpath,path);
	    strcat(fullpath,"/");
	    strcat(fullpath,file->d_name);
	    int rv = stat(fullpath,&st);
	    if(rv<0)
	    {
            return -1;
	    }
	    printMode(st.st_mode,indent);
    	printUserName(st.st_uid);
		printGroupName(st.st_gid);
		printSize(st.st_size);
		printModifyTime(st.st_mtime);
	    printFileName(file->d_name);
		
        if(S_ISDIR(st.st_mode)&& (depth-1>0))
	    {
		ls(fullpath,depth-1,indent+1);
	    }
	    free(fullpath);
	}
	closedir(dhandle);
	return 0;

}


void printStat(struct stat *st)
{
    printf("st_dev:%lu\n",st->st_dev);
    printf("st_ino:%lu\n",st->st_ino);
    printf("st_mode:%u\n",st->st_mode);
    printf("st_nlink:%lu\n",st->st_nlink);
    printf("st_uid:%u\n",st->st_uid);
    printf("st_gid:%u\n",st->st_gid);
    printf("st_rdev:%lu\n",st->st_rdev);
    printf("st_size:%lu\n",st->st_size);
    printf("st_blksize:%lu\n",st->st_blksize);
    printf("st_blocks:%lu\n",st->st_blocks);
    printf("st_atime:%lu\n",st->st_atime);
   // printf("st_atime_nsec:%lu\n",st->st_atime_nsec);
    printf("st_mtime:%lu\n",st->st_mtime);
   // printf("st_mtime_nsec:%lu\n",st->st_mtime_nsec);
    printf("st_ctime:%lu\n",st->st_ctime);
    //printf("st_ctime_nsec:%lu\n",st->st_ctime_nsec);
}


int main(int argc,char *argv[])
{
//	struct stat st;
//    int rv =stat("/home/harlan",&st);
//	printStat(&st);
    int dep = atoi(argv[2]);
    ls(argv[1],dep,0);
    return 0;
}

