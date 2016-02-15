#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	// variables for pid, and fork1 and fork2
	pid_t pid;
	int f;
	int f2;


	//start with an initial fork
	f = fork();

	//The parent process, which waits until the children are done
	if(f != 0)
	{	
		pid = getpid();
 		waitpid(f,NULL,NULL);
		printf("Parent process with process ID %i has completed\n",pid);
	}
	else
	{
		//At this point, this is the first child. We want to fork again.
		f2 = fork();

		//The child process waits for the grindchild, and kills itself when it's done waiting.
		if(f2 != 0)
		{
			pid = getpid();
			waitpid(f2,NULL,NULL);
			printf("Child process with process ID %i has completed\n",pid);			
			kill(pid,SIGTERM);
		}
		else
		{
			//This is the grand child. It will sleep for 10 seconds, then kill itself.
			pid = getpid();
			sleep(10);
			printf("Grandchild process with process id %i has completed\n",pid);
			kill(pid,SIGTERM);
		}
	}
	return 0;
}
