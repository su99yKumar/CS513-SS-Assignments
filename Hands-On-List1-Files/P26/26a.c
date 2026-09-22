#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing ls -Rl using execl...\n");

    execl("/bin/ls", "ls", "-Rl", NULL);

    perror("Error: execl() failed");

    return 1;
}
