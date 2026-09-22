#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t child1, child2, child3;
    int status;

    child1 = fork();

    if (child1 == -1)
    {
        perror("Error: fork() failed for child 1");
        return 1;
    }

    if (child1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        printf("Child 1 exiting.\n");
        exit(1);
    }

    child2 = fork();

    if (child2 == -1)
    {
        perror("Error: fork() failed for child 2");
        return 1;
    }

    if (child2 == 0)
    {
        printf("Child 2: PID = %d\n", getpid());
        sleep(5);
        printf("Child 2 exiting.\n");
        exit(2);
    }

    child3 = fork();

    if (child3 == -1)
    {
        perror("Error: fork() failed for child 3");
        return 1;
    }

    if (child3 == 0)
    {
        printf("Child 3: PID = %d\n", getpid());
        sleep(3);
        printf("Child 3 exiting.\n");
        exit(3);
    }

    printf("Parent PID: %d\n", getpid());
    printf("Child 1 PID: %d\n", child1);
    printf("Child 2 PID: %d\n", child2);
    printf("Child 3 PID: %d\n", child3);

    printf("Parent waiting specifically for Child 2...\n");

    if (waitpid(child2, &status, 0) == -1)
    {
        perror("Error: waitpid() failed");
        return 1;
    }

    if (WIFEXITED(status))
    {
        printf("Child 2 terminated with exit status: %d\n",
               WEXITSTATUS(status));
    }

    printf("Parent finished waiting for Child 2.\n");

    sleep(2);

    return 0;
}

