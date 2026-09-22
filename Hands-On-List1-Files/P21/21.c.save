#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    pid_t pid;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error opening output.txt");
        return 1;
    }

    pid = fork();

    if (pid == -1)
    {
        perror("Error: fork() failed");
        close(fd);
        return 1;
    }

    if (pid == 0)
    {
        if (write(fd, "Child process writing to file.\n", 31) == -1)
        {
            perror("Error: child write failed");
            close(fd);
            return 1;
        }

        printf("Child process wrote to the file.\n");
    }
    else
    {
        if (write(fd, "Parent process writing to file.\n", 32) == -1)
        {
            perror("Error: parent write failed");
            close(fd);
            return 1;
        }

        printf("Parent process wrote to the file.\n");
    }

    close(fd);

    return 0;
}
