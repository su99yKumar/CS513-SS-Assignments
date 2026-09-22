#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Hello program is running.\n");
    printf("PID: %d\n", getpid());

    return 0;
}
