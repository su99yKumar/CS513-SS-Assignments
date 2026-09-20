#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int position;

    char data1[] = "ABCDEFGHIJ";
    char data2[] = "KLMNOPQRST";

    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, data1, 10) == -1)
    {
        perror("Error writing first 10 bytes");
        close(fd);
        return 1;
    }

    position = lseek(fd, 10, SEEK_CUR);

    if (position == -1)
    {
        perror("Error seeking file");
        close(fd);
        return 1;
    }

    printf("New file offset: %d\n", position);

    if (write(fd, data2, 10) == -1)
    {
        perror("Error writing second 10 bytes");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
