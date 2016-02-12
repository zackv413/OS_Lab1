#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   
    int child_status;
    
    /* Change this, MIKE */     
    int number_of_commands = 3;

    /* Testing */

    char* commands_from_input[] =  {"ls","pwd","uname"};


    for( int x = 0; x < number_of_commands; x++ )
    {
       
       char *cmd[] = { commands_from_input[x] , NULL }; 
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

    return 0;

}
