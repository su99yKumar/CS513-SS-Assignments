#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        perror("Error: fork() failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process started.\n");
        printf("Child PID: %d\n", getpid());
        printf("Initial Parent PID: %d\n", getppid());

        sleep(10);

        printf("After parent exits, Child PID: %d\n", getpid());
        printf("New Parent PID: %d\n", getppid());

        sleep(10);
    }
    else
    {
        printf("Parent process started.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        sleep(3);

        printf("Parent process exiting now.\n");
        exit(0);
    }

    return 0;
}

