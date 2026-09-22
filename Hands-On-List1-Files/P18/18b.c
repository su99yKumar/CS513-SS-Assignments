#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int record_number;
    int offset;
    char buffer[9];
    struct flock lock;

    fd = open("records.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening records file");
        return 1;
    }

    printf("Enter record number (1-3): ");
    scanf("%d", &record_number);

    if (record_number < 1 || record_number > 3)
    {
        printf("Invalid record number.\n");
        close(fd);
        return 1;
    }

    /*
     * Each record occupies 9 bytes:
     * Record 1\n
     * Record 2\n
     * Record 3\n
     */
    offset = (record_number - 1) * 9;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = 9;

    printf("Attempting to acquire read lock on record %d...\n",
           record_number);

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("Error acquiring read lock");
        close(fd);
        return 1;
    }

    printf("Read lock acquired on record %d.\n", record_number);

    if (lseek(fd, offset, SEEK_SET) == -1)
    {
        perror("Error seeking to record");
        close(fd);
        return 1;
    }

    if (read(fd, buffer, 9) != 9)
    {
        perror("Error reading record");
        close(fd);
        return 1;
    }

    printf("Record being read: ");
    write(1, buffer, 9);

    printf("Read lock is being held. Press Enter to release it...\n");

    /*
     * scanf() leaves the newline in stdin.
     * First getchar() consumes it.
     * Second getchar() waits for Enter.
     */
    getchar();
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
