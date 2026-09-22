#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Main program started.\n");
    printf("Main program PID: %d\n", getpid());

    printf("Now executing hello program...\n");

    execl("./hello", "hello", NULL);

    perror("Error: execl() failed");

    return 1;
}

