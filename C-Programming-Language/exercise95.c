#include <unistd.h>
#include <stdio.h>

// fseek implementation for file pointer
int fseek(FILE *fp, long offset, int origin) {
    // Perform the operation for seeking based on the origin
    if (origin == SEEK_SET) {
        fp->ptr = fp->base + offset;  // Move to the given offset
    } else if (origin == SEEK_CUR) {
        fp->ptr += offset;  // Move relative to the current position
    } else if (origin == SEEK_END) {
        // Seek from the end of the file
        lseek(fp->fd, 0, SEEK_END);
        fp->ptr = fp->base + offset;  // Update the pointer based on the end
    }

    // Ensure the file pointer is adjusted for buffering (flush any previous data)
    if (fp->flags & 0x2) {
        // If in write mode, flush the data before seeking
        _flushbuf('\0', fp);
    }

    return 0;  // Return success
}
