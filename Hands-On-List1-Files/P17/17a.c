#include <stdio.h>

int main()
{
    FILE *file;

    file = fopen("ticket.txt", "w");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "100\n");

    fclose(file);

    printf("Initial ticket number stored successfully.\n");

    return 0;
}
