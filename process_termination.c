#include <signal.h>
#include <stdio.h>
#include <errno.h>
int main()
{

    int process_id;

    printf("Please enter a process id: \n");
    scanf("%d",&process_id);

    //printf("You entered: %d\n",process_id);

    int kill_return_value = kill( process_id, SIGKILL );

    if( kill_return_value == 0 )
    {
        /* Succesfully terminated application */
        printf("Successfully killed process: %d\n", process_id);
    }
    else
    {
        switch( errno )
        {
            case ESRCH:
                printf("Unable to find the specefied pID\n");
                break;
            case EPERM:
                printf("You do not have permission to kill this pID\n");
                break;
        }
    }

}
