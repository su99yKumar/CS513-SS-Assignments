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

    fd = open("records.txt", O_RDWR);

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
     * Each record is 9 bytes:
     * Record 1\n
     * Record 2\n
     * Record 3\n
     */

    offset = (record_number - 1) * 9;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = 9;

    printf("Attempting to acquire write lock on record %d...\n",
           record_number);

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("Error acquiring write lock");
        close(fd);
        return 1;
    }

    printf("Write lock acquired on record %d.\n", record_number);

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

    printf("Record before modification: ");
    write(1, buffer, 9);

    /*
     * Modify the selected record.
     * Each replacement is exactly 9 bytes.
     */
    if (lseek(fd, offset, SEEK_SET) == -1)
    {
        perror("Error seeking to record");
        close(fd);
        return 1;
    }

    if (record_number == 1)
    {
        if (write(fd, "Changed1\n", 9) != 9)
        {
            perror("Error modifying record");
            close(fd);
            return 1;
        }
    }
    else if (record_number == 2)
    {
        if (write(fd, "Changed2\n", 9) != 9)
        {
            perror("Error modifying record");
            close(fd);
            return 1;
        }
    }
    else
    {
        if (write(fd, "Changed3\n", 9) != 9)
        {
            perror("Error modifying record");
            close(fd);
            return 1;
        }
    }

    printf("Record %d modified successfully.\n", record_number);

    printf("Write lock is being held. Press Enter to release it...\n");

    /*
     * scanf() leaves the newline in stdin.
     * First getchar() consumes that newline.
     * Second getchar() waits for the user's Enter.
     */
    getchar();
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
