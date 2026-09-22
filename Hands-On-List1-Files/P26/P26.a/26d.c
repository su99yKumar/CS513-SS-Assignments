#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-Rl", NULL};

    printf("Executing ls -Rl using execv...\n");

    execv("/bin/ls", args);

    perror("Error: execv() failed");

    return 1;
}
