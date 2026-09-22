#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./p25b <name>\n");
        return 1;
    }

    printf("Main program started.\n");
    printf("Main program PID: %d\n", getpid());

    printf("Now executing hello program with name: %s\n", argv[1]);

    execl("./hello", "hello", argv[1], NULL);

    perror("Error: execl() failed");

    return 1;
}

