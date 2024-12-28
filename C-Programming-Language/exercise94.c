#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 1024

// Define the file structure
struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int flags;
    int fd;
};

// Flush the buffer for a file
int _flushbuf(int c, FILE *fp) {
    if (fp->flags & 0x2) {  // Check if file is writable
        *fp->ptr++ = c;
        if (fp->ptr >= fp->base + BUFSIZE) {
            // Flush the buffer by writing to the file
            write(fp->fd, fp->base, BUFSIZE);
            fp->ptr = fp->base; // Reset the buffer pointer
        }
    }
    return 0;
}

// Flush the buffer using fflush
int fflush(FILE *fp) {
    if (fp->flags & 0x2) { // Writable mode
        _flushbuf('\0', fp); // Write any pending data in the buffer
    }
    return 0;
}

// Close the file and flush buffers
int fclose(FILE *fp) {
    if (fp == NULL) {
        return EOF;
    }
    fflush(fp);  // Flush the buffer before closing
    close(fp->fd);  // Close the file descriptor
    fp->flags = 0;  // Reset flags for the file stream
    return 0;
}
