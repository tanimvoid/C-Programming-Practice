/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program to Read and Write Contents of a File
*/

// Algorithm:
/*
STEP 1: Open a file in write mode and write some text to it.
STEP 2: Close the file after writing.
STEP 3: Open the file in read mode to read the contents.
STEP 4: Display the content read from the file.
STEP 5: Close the file after reading.
*/

#include <stdio.h>

int main() {
    FILE *file;
    char text[100];

    file = fopen("file.txt", "w");
    fprintf(file, "Hello, this is a test file.\n");
    fclose(file);

    file = fopen("file.txt", "r");
    while (fgets(text, 100, file) != NULL) {
        printf("%s", text);
    }
    fclose(file);

    return 0;
}
