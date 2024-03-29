#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>



void cat_file(char* filepath);

int main(int argc, char* argv[]) {

    if(argc > 1) {    // User has provided at least 1 file to cat
        // Cycling through each filepath
        for(int i = 1; i < argc; i++) {
            cat_file(argv[i]); // Errors are handled in cat_file
        }
    }
    return 0;
}


void cat_file(char* filepath) {
    // Attempting to open file
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open file %s\n", filepath);
        printf("Error message: %s\n", strerror(errno));
        exit(1);
    }
    // File successfully opened for reading
    // Printing to screen with a 1-line buffer
    char line_buffer[UINT_MAX];
    char* ret = fgets(line_buffer, UINT_MAX, file);
    while (ret != NULL) {
        printf("%s", ret);
        ret = fgets(line_buffer, UINT_MAX, file);
    }
}

