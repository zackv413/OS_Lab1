#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	char* input = malloc(sizeof(char)*256);
	char* sgl_str = malloc(sizeof(char)*256);
	char* array[256];
	int exit = 0;
	while(exit == 0)
	{
	fgets(input, 256, stdin);
	
	int i = 0;	
	sgl_str = strtok(input," \n\r");
	
	while(sgl_str != NULL)
	{
		array[i] = sgl_str;
		sgl_str = strtok(NULL," \n\r");
		i++;
	}
	//i is the number of commands
	int child_status;
    
 	int number_of_commands = i;
	int x;	
	for(x = 0; x < number_of_commands; x++ )
	{       
		if(strcmp(array[x],"exit") == 0)
		{
			exit = 1;
			break;
		}
		char *cmd[] = { array[x] , NULL }; 
	      	pid_t pid;
       		int f = fork();
        	
       		if( f != 0 )
       		{  
	       		waitpid(f, &child_status, 0);   
       		}
       		else
       		{	
    			pid = getpid();
       			execvp(cmd[0], cmd);
	       		kill( pid, SIGKILL );
	       	}	
    	}
	}
	
	return 0;
}
