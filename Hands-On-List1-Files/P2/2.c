#include <stdio.h>
#include <unistd.h>

int main()
{
    while (1)
    {
        printf("Running process with PID: %d\n", getpid());
        sleep(5);
    }

    return 0;
}
