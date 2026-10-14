/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program to Find the Size of Data Types
*/

// Algorithm:
/*
STEP 1: Start the program.
STEP 2: Use the `sizeof` operator to get the sizes of data types (int, float, double, char).
STEP 3: Print the sizes of each data type.
STEP 4: End the program.
*/

#include <stdio.h>

int main() {
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));
    printf("Size of char: %lu bytes\n", sizeof(char));
    return 0;
}
