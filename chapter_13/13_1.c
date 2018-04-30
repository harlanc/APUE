#include "../apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
void daemonize(const char *cmd)
{
	int i,fd0,fd1,fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;
	/*
	 *Clear file creation mask.
	 */

	umask(0);

	/*
	 *Get maximum number of file descriptors.
	 */

	if(getrlimit(RLIMIT_NOFILE,&rl)<0)
		err_quit("%s:can't get file limit",cmd);

	/*
	 *Become a session leader to lose controlling TTY.
	 */
	if((pid=fork())<0)
		err_quit("%s:can't fork",cmd);
	else if(pid != 0)
		exit(0);
	setsid();

	/*
	 *Ensure future opens won't allocate controlling TTYs.
	 */
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if(sigaction(SIGHUP,&sa,NULL)<0)
		err_quit("%s:can't ignore SIGHUP",cmd);
	if((pid = fork())<0)
		err_quit("%s:can't fork",cmd);
	else if(pid != 0)
		exit(0);
}
