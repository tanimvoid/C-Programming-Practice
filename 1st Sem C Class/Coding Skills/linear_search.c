/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program for Linear Search
*/

// Algorithm:
/*
STEP 1: Take input array and key to search.
STEP 2: Loop through the array to find the key.
STEP 3: If found, return the index; otherwise, return -1.
*/

#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int key = 6;
    int index = linearSearch(arr, 5, key);
    printf("Element found at index %d\n", index);
    return 0;
}
