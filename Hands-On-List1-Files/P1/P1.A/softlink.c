#include <stdio.h>
#include <unistd.h>

int main()
{
    int result;

    result = symlink("original.txt", "softlink.txt");

    if (result == -1)
    {
        perror("symlink");
        return 1;
    }

    printf("Soft link created successfully.\n");

    return 0;
}
