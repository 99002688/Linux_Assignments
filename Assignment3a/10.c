#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void){

    pid_t retVal;

    retVal = fork();

    if(retVal > 0){
        int i = 0;
        while(i++ < 5){
            printf("in the parent process.\n");
            sleep(1);
        }
        //kill the child process
        kill(retVal, SIGKILL);
        printf("The child process has been killed :(\n");

    } else if (retVal == 0){
        int i = 0;
  
        while(i++ < 15){
            printf("In the child process.\n");
            sleep(1);
        }
    } else {
        
        printf("Something bad happened.");
        exit(EXIT_FAILURE);
    }

    return 0;

}
