#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    struct flock lock;

    fd = open("test.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Attempting to acquire write lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("Error acquiring write lock");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");
    printf("File is locked. Press Enter to release the lock...\n");

    getchar();

    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("Error releasing write lock");
        close(fd);
        return 1;
    }

    printf("Write lock released.\n");

    close(fd);

    return 0;
}
