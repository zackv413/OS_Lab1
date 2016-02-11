#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

int main()
{
	pid_t pid;
	int f;
	f = fork();
	pid = getpid();
	
	//char* input = NULL;
	//char* sgl_str = NULL;
	//scanf("%s", input);
	//sgl_str = strtok(input," ");
	
	
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
		pid = getpid();
		//execv(argv[0], argv);
		execvp(argv[0], argv);
		kill(pid,SIGKILL);
	}
	printf(":D\n");
	return 0;
}
