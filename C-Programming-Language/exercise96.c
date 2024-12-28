#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void print_file_info(const char *filename) {
    struct stat file_stat;

    // Retrieve file information
    if (stat(filename, &file_stat) < 0) {
        perror("stat");
        return;
    }

    // Print basic file size
    printf("File size: %ld bytes\n", file_stat.st_size);

    // Print inode number
    printf("Inode number: %ld\n", file_stat.st_ino);

    // Print file permissions
    printf("Permissions: ");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    // Print the number of hard links
    printf("Number of hard links: %ld\n", file_stat.st_nlink);

    // Print owner and group
    printf("Owner: %d, Group: %d\n", file_stat.st_uid, file_stat.st_gid);

    // Print file modification time
    printf("Last modification time: %s", ctime(&file_stat.st_mtime));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    print_file_info(argv[1]);

    return 0;
}
