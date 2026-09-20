#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    struct flock lock;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Attempting to acquire read lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("Error acquiring read lock");
        close(fd);
        return 1;
    }

    printf("Read lock acquired.\n");
    printf("File is locked for reading. Press Enter to release the lock...\n");

    getchar();

    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("Error releasing read lock");
        close(fd);
        return 1;
    }

    printf("Read lock released.\n");

    close(fd);

    return 0;
}
