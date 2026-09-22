#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./hello <name>\n");
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);
    printf("Hello program PID: %d\n", getpid());

    return 0;
}
