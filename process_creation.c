#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int f;
	int f2;

	f = fork();
	if(f != 0)
	{	
		pid = getpid();
 		waitpid(f,NULL,NULL);
		printf("Parent process with process ID %i has completed\n",pid);
	}
	else
	{
		f2 = fork();
		if(f2 != 0)
		{
			pid = getpid();
			waitpid(f2,NULL,NULL);
			printf("Child process with process ID %i has completed\n",pid);			
			kill(pid,SIGTERM);
		}
		else
		{
			pid = getpid();
			sleep(10);
			printf("Grandchild process with process id %i has completed\n",pid);
			kill(pid,SIGTERM);
		}
	}
	return 0;
}
