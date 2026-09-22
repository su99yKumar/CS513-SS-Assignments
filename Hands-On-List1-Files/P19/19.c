#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process started. PID: %d\n", getpid());

    while (1)
    {
        /* CPU-intensive loop keeps the process running */
    }

    return 0;
}
