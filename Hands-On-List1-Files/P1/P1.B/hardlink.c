#include <stdio.h>
#include <unistd.h>

int main()
{
    int result;

    result = link("original.txt", "hardlink2.txt");

    if (result == -1)
    {
        perror("link");
        return 1;
    }

    printf("Hard link created successfully.\n");

    return 0;
}
