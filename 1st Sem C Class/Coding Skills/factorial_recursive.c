/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program to Find Factorial Using Recursive Function
*/

// Algorithm:
/*
STEP 1: Define a recursive function `factorial(int n)`.
STEP 2: If n is 0 or 1, return 1 (base case).
STEP 3: Otherwise, return n * factorial(n - 1).
STEP 4: In the main function, take an input number and call the factorial function.
STEP 5: Print the result.
STEP 6: End the program.
*/

#include <stdio.h>

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}
