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
