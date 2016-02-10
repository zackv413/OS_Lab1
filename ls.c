#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
	pid_t pid;
	int f;
	f = fork();
	pid = getpid();

	
	if(f != 0)
	{
		wait(NULL);
 		//waitpid(f);	
	}
	else
	{
		//char *argv[] = {"/bin/ls", "-l", 0};
		//char *argv[] = {"ls", NULL, 0};
		char *argv[] = {"ls", NULL, "pwd", NULL};

		//execv(argv[0], argv);
		execvp(argv[2], argv);
		kill(pid,SIGTERM);
	}
	return 0;
}
