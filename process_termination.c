#include <signal.h>
#include <stdio.h>
#include <errno.h>
int main()
{

    int process_id;

    printf("Please enter a process id: ");

    //store the user input into process_id
    scanf("%d",&process_id);

    //use the kill function and store it's return value into kill_return_value
    int kill_return_value = kill( process_id, SIGKILL );


    // 0 indicates a valid kill
    if( kill_return_value == 0 )
    {
        /* Succesfully terminated application */
        printf("Successfully killed process: %d\n", process_id);
    }
    else 
    {
        // If there was an error, it will be stored in errno automatically by kill.
        // ESRCH indicates that there was no process with the user inputted pID.
        // EPERM indicates that the user tried to kill a process it did not have permission to kill.
        
        if( errno == ESRCH )
        {
            printf("Unable to find the specefied pID\n");
        }
        else if( errno == EPERM )
        {

            printf("You do not have permission to kill this pID\n");
        }
    }

}
