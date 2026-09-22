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
        printf("Child process created successfully.\n");
        printf("Child PID: %d\n", getpid());
        printf("Child's Parent PID: %d\n", getppid());
    }
    else
    {
        printf("Parent process.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}
