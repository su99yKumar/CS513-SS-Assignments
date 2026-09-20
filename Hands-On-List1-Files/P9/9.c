#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat file_info;

    if (stat("test.txt", &file_info) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode: %ld\n", file_info.st_ino);
    printf("Number of hard links: %ld\n", file_info.st_nlink);
    printf("UID: %d\n", file_info.st_uid);
    printf("GID: %d\n", file_info.st_gid);
    printf("Size: %ld bytes\n", file_info.st_size);
    printf("Block size: %ld bytes\n", file_info.st_blksize);
    printf("Number of blocks: %ld\n", file_info.st_blocks);
    printf("Last access time: %ld\n", file_info.st_atime);
    printf("Last modification time: %ld\n", file_info.st_mtime);
    printf("Last change time: %ld\n", file_info.st_ctime);

    return 0;
}
