#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
    printf("Executing ls -Rl using execle...\n");

    execle("/bin/ls", "ls", "-Rl", NULL, environ);

    perror("Error: execle() failed");

    return 1;
}
