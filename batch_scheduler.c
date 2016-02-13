#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

int main()
{
	char* input = malloc(sizeof(char)*256);
	char* sgl_str = malloc(sizeof(char)*256);
	fgets(input, 256, stdin);
	char* array[256];

	int i = 0;	
	sgl_str = strtok(input," ");

	while(sgl_str != NULL)
	{
		array[i] = sgl_str;
		sgl_str = strtok(NULL," ");
		i++;
	}
	//test
	int j = 0;
	for(j = 0;  j < i; j++)
	{
		printf("%s\n",array[j]);
		fflush(stdout);
	}
	//end test
/*
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
*/
	return 0;
}
