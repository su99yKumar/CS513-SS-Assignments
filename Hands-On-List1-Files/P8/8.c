#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    int n;
    int i;

    fd = open("input.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((n = read(fd, buffer, sizeof(buffer))) > 0)
    {
        for (i = 0; i < n; i++)
        {
            write(1, &buffer[i], 1);
        }
    }

    if (n == -1)
    {
        perror("Error reading file");
    }

    close(fd);

    return 0;
}
