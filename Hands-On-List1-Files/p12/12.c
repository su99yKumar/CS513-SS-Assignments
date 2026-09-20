#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int flags;

    /*
     * Change O_RDWR to O_RDONLY or O_WRONLY
     * to test the different opening modes.
     */
    fd = open("test.txt", O_RDWR);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    if ((flags & O_ACCMODE) == O_RDONLY)
    {
        printf("File is opened in Read Only mode\n");
    }
    else if ((flags & O_ACCMODE) == O_WRONLY)
    {
        printf("File is opened in Write Only mode\n");
    }
    else if ((flags & O_ACCMODE) == O_RDWR)
    {
        printf("File is opened in Read Write mode\n");
    }

    close(fd);

    return 0;
}
