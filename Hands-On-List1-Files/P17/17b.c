#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int ticket;
    char buffer[20];
    int n;
    struct flock lock;

    fd = open("ticket.txt", O_RDWR);

    if (fd == -1)
    {
        perror("Error opening ticket file");
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

    n = read(fd, buffer, sizeof(buffer) - 1);

    if (n == -1)
    {
        perror("Error reading ticket number");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    if (sscanf(buffer, "%d", &ticket) != 1)
    {
        printf("Error: Invalid ticket number.\n");
        close(fd);
        return 1;
    }

    ticket++;

    printf("New ticket number: %d\n", ticket);

    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        perror("Error seeking file");
        close(fd);
        return 1;
    }

    if (ftruncate(fd, 0) == -1)
    {
        perror("Error truncating file");
        close(fd);
        return 1;
    }

    if (dprintf(fd, "%d\n", ticket) == -1)
    {
        perror("Error writing ticket number");
        close(fd);
        return 1;
    }

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
