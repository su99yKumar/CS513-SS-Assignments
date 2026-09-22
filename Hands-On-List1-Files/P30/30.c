#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>

int main()
{
    pid_t pid;
    time_t current_time;
    struct tm *current;

    int target_hour = 14;
    int target_minute = 50;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        printf("Parent exiting. Daemon PID: %d\n", pid);
        return 0;
    }

    if (setsid() == -1)
    {
        perror("setsid");
        return 1;
    }

    while (1)
    {
        current_time = time(NULL);
        current = localtime(&current_time);

        if (current == NULL)
        {
            perror("localtime");
            return 1;
        }

        if (current->tm_hour == target_hour &&
            current->tm_min == target_minute)
        {
            int fd;

            fd = open("task_done.txt",
                      O_WRONLY | O_CREAT | O_TRUNC, 0644);

            if (fd == -1)
            {
                perror("open");
                return 1;
            }

            dprintf(fd, "Task executed by daemon.\n");

            close(fd);

            break;
        }

        sleep(1);
    }

    return 0;
}
