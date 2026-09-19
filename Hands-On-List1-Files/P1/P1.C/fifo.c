#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int result;

    result = mkfifo("myfifo", 0666);

    if (result == -1)
    {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created successfully.\n");

    return 0;
}

