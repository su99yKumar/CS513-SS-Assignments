#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing ls -Rl using execlp...\n");

    execlp("ls", "ls", "-Rl", NULL);

    perror("Error: execlp() failed");

    return 1;
}
