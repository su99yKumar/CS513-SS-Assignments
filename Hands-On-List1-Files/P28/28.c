#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Program PID: %d\n", getpid());

    while (1)
    {
        sleep(5);
    }

    return 0;
}
