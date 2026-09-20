#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat file_info;

    if (argc != 2)
    {
        printf("Error: Please provide exactly one file name.\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &file_info) == -1)
    {
        perror("Error getting file information");
        return 1;
    }

    if (S_ISREG(file_info.st_mode))
    {
        printf("File type: Regular file\n");
    }
    else if (S_ISDIR(file_info.st_mode))
    {
        printf("File type: Directory\n");
    }
    else if (S_ISLNK(file_info.st_mode))
    {
        printf("File type: Symbolic link\n");
    }
    else if (S_ISFIFO(file_info.st_mode))
    {
        printf("File type: FIFO\n");
    }
    else
    {
        printf("File type: Other\n");
    }

    return 0;
}
