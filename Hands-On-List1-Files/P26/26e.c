#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-Rl", NULL};

    printf("Executing ls -Rl using execvp...\n");

    execvp("ls", args);

    perror("Error: execvp() failed");

    return 1;
}
