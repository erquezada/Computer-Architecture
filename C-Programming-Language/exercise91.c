#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

// System call-based cat program
void cat_sys(const char *filename) {
    int fd;  // file descriptor
    char buf[BUFSIZE];
    ssize_t nread;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read and write the contents of the file to stdout
    while ((nread = read(fd, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, nread) != nread) {
            perror("write");
            close(fd);
            exit(1);
        }
    }

    // Check for read error
    if (nread == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    // Close the file
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Call the system call-based cat function
    cat_sys(argv[1]);

    return 0;
}
