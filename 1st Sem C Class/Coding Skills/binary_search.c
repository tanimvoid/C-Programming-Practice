/*
    Date: November 06, 2024
    Name: MD. SAMIUR RAHMAN TANIM
    Topic: Program for Binary Search
*/

// Algorithm:
/*
STEP 1: Assume the array is already sorted.
STEP 2: Set the initial low and high indices (low = 0, high = array size - 1).
STEP 3: While low is less than or equal to high, do the following:
    da. Calculate the middle index (mid = (low + high) / 2).
    b. If the middle element is equal to the key, return the mid index (element found).
    c. If the middle element is less than the key, set low to mid + 1.
    d. If the middle element is greater than the key, set high to mid - 1.
STEP 4: If the key is not found, return -1.
*/

#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key)
            return mid; // Element found
        else if (arr[mid] < key)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int key = 8;
    int index = binarySearch(arr, 5, key);
    
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    
    return 0;
}
