#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	//allocate storage for the user input
	char* input = malloc(sizeof(char)*256);
	char* sgl_str = malloc(sizeof(char)*256);
	char* array[256];

	//hold reference to finding an "exit" command
	int exit = 0;

	//loop while we haven't been told to exit
	while(exit == 0)
	{

	//use fgets to get the user input
	printf("batch-shell> ");
	fgets(input, 256, stdin);
	
	//use strtok to split on spaces [" "] and count the number of commands into i
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
	//loop for each command so we can have a child for each command
	for(x = 0; x < number_of_commands; x++ )
	{   
		//immediatly break if we have reciecved an exit command
		if(strcmp(array[x],"exit") == 0)
		{
			exit = 1;
			break;
		}

			//otherwise, set up the char* for the command, array[x] holds the command
			char *cmd[] = { array[x] , NULL }; 
	      	pid_t pid;
       		//fork a child process
       		int f = fork();
        	

        	//If we forked, wait for the child.	
       		if( f != 0 )
       		{  
	       		waitpid(f, &child_status, 0);   
       		}
       		else
       		{	
       			//get the child PID, execute the command with execvp, then kill itself so looping continues.
    			pid = getpid();
       			execvp(cmd[0], cmd);
	       		kill( pid, SIGKILL );
	       	}	
    	}
	}
	
	return 0;
}
