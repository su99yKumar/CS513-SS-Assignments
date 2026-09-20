#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int fd2;

    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

   // fd2 = dup(fd);
  // fd2= dup2(fd ,10);
     fd2 = fcntl(fd, F_DUPFD, 10);

    if (fd2 == -1)
    {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    printf("Original FD: %d\n", fd);
    printf("Duplicate FD: %d\n", fd2);

    write(fd, "Hello from FD 1\n", 16);
    write(fd2, "Hello from FD 2\n", 16);

    close(fd);
    close(fd2);

    return 0;
}
