#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open file with error handling
    FILE* openFile = fopen("sample_text.txt", "r");
    if (!openFile) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Buffer to hold each line
    char line[2048];
    
    // Process each line
    while (fgets(line, sizeof(line), openFile)) {
        printf("%s", line);
    }

    // Close the file after reading
    if (fclose(openFile) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
