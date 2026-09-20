#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int src, dest;
    char buffer[100];
    int n;

    src = open("source.txt", O_RDONLY);

    if (src == -1)
    {
        perror("Error opening source file");
        return 1;
    }

    dest = open("destination.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (dest == -1)
    {
        perror("Error opening destination file");
        close(src);
        return 1;
    }

    while ((n = read(src, buffer, sizeof(buffer))) > 0)
    {
        write(dest, buffer, n);
    }

    if (n == -1)
    {
        perror("Error reading source file");
    }

    close(src);
    close(dest);

    return 0;
}
