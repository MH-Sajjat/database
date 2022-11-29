#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
    id_t childPid;
    childPid = fork();

    if(childPid == 0)
    {
        system("ls");
        for(int i=1 ; i<=20 ; i++)
        {
            printf("I'm child\n");
            sleep(1);
        }
    }
    else
    {
        int returnStatus;
        waitpid(childPid, &returnStatus, 0);

        if (returnStatus == 0)
        {
        for(int i=1 ; i<=20 ; i++)
        {
            printf("I'm parent\n");

        }

            printf("The child process terminated normally.");
        }

        if (returnStatus == 1)
        {
            printf("The child process terminated with an error!.");
        }
    }
}

