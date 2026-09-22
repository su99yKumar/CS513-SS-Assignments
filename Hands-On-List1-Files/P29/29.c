#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("Error getting scheduling policy");
        return 1;
    }

    if (policy == SCHED_OTHER)
    {
        printf("Current policy: SCHED_OTHER\n");
    }
    else if (policy == SCHED_FIFO)
    {
        printf("Current policy: SCHED_FIFO\n");
    }
    else if (policy == SCHED_RR)
    {
        printf("Current policy: SCHED_RR\n");
    }

    param.sched_priority = 10;

    printf("Attempting to change policy to SCHED_FIFO...\n");

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1)
    {
        perror("Error changing scheduling policy");
        return 1;
    }

    policy = sched_getscheduler(0);

    if (policy == SCHED_FIFO)
    {
        printf("New policy: SCHED_FIFO\n");
    }

    return 0;
}
