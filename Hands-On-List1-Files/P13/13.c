#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set readfds;
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    result = select(1, &readfds, NULL, NULL, &timeout);

    if (result == -1)
    {
        perror("select");
    }
    else if (result == 0)
    {
        printf("No input received within 10 seconds\n");
    }
    else
    {
        printf("Input is available on STDIN\n");
    }

    return 0;
}
