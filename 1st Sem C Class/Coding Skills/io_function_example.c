/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program Using I/O Function with Arguments and Return Value
*/

// Algorithm:
/*
STEP 1: Define a function that takes an integer argument and returns the square.
STEP 2: In the main function, prompt the user for an input number.
STEP 3: Call the square function and display the result.
STEP 4: End the program.
*/

#include <stdio.h>

int square(int num) {
    return num * num;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Square of %d is %d\n", num, square(num));
    return 0;
}
