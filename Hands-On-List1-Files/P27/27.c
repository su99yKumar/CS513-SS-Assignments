 #include <stdio.h>
#include <sched.h>

int main()
{
    int max_priority;
    int min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);

    if (max_priority == -1)
    {
        perror("Error getting maximum priority");
        return 1;
    }

    min_priority = sched_get_priority_min(SCHED_FIFO);

    if (min_priority == -1)
    {
        perror("Error getting minimum priority");
        return 1;
    }

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    return 0;
}
