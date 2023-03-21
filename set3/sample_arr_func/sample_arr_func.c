/*
 *  Functions with array parameters
 *
 *  A NOTE ON DEBUG
 *  - To be able to inspect arrays in functions, run Debug
 *
 *  For example, assuming parameters to function are arr[] and size (is 10).
 *  - In Watches click +
 *  - Type: (int (*)[10]) arr
 *  - Enter
 *  The content of the array is now possible to inspect in Watches
 *
 *  NOTE: Always use const if parameter is not going to be changed!
 *  It's a safe guard!
 */

#include<stdio.h>
#include<memory.h>

#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")
// This macro will work if at least the first argument is an array (i.e. not a pointer)
#define CHECK_IF_ARR_EQUALS(v1, v2) printf( memcmp(v1, v2, sizeof(v1)) == 0 ? "ok\n" : "not ok\n")


// Find min value in array (can't change array it's const, good!)
int min_value(const int arr[], int size);

// Copy all values from src to dest (can't change src it's const, good)
void copy(int dest[], const int src[], int size);

// NOTE: Not possible in C, can't return full array
// int[] copy(const int src[], int size);


int main(void) {
    int arr[] = {2, 5, -1, 7, 8, 9, 12, 1};

    int size = sizeof(arr)/ sizeof(arr[0]);
    CHECK_IF_EQUALS(min_value(arr, size), -1);

    int dest[size];
    copy(dest, arr, size);
    CHECK_IF_ARR_EQUALS(dest, arr);

    // NOTE: Not allowed! Can't assign arrays
    // dest = arr;

    return 0;
}


int min_value(const int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void copy(int dest[], const int src[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}


