/*
 *  This is a rework of remove duplicates exercise from set4
 *  Here we return a dynamically allocated array
 *
 * To be able to inspect arrays in functions during debug...
 * 1.  Start debugging, enter into function
 * 2.  Assume parameter to functions is arr[] and size is 10.
    - In Debugger window, right click > New Watch
    - Type: (int (*)[10]) arr
    - Enter, enter
 * 3.  Click the triangles before the watch to inspect the element
 * 4.  To remove watch, right click in window > Remove Watch
 *
 *  See:
 *  - use_malloc.c (variables and arrays only)
 *  - dyn_arr.c
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// Test macros
#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")
#define CHECK_IF_ARR_EQUALS(a1, a2) printf( memcmp(a1, a2, sizeof(a1)) == 0 ? "ok\n" : "not ok\n")

// Return new dynamically allocated array without duplicates
int *remove_dupl(const int *arr, int size);


int main(void) {

    int arr[] = {1, 1, 2, 2, 2, 2, 3};

    int *result = remove_dupl(arr, SIZE(arr));
    int expected[] = {1, 2, 3};
    CHECK_IF_ARR_EQUALS(expected, result);   // NOTE: Must have array first
    CHECK_IF_EQUALS(arr == result, false);   // Two different arrays (addresses)

    free(result);   // Not really needed here but in general.

    int arr2[] = {3, 3, 3, 5, 5, 5, 5, 5, 7, 7};
    int *result2 = remove_dupl(arr2, SIZE(arr2));
    int expected2[] = {3, 5, 7};
    CHECK_IF_ARR_EQUALS(expected2, result2);

    free(result2);  // Not really needed here but in general.

    return 0;
}


/*
 *  Hint: Use a temporarily (tmp) variable with same size
 *  as arr and copy the unique values to tmp. Keep track of number of 
 *  elements in tmp.
 *  Then,... dynamically allocate an array of that size and copy
 *  values from tmp to allocated. Return allocated array with the correct size.
 */
int *remove_dupl(const int *arr, int size) {
    // TODO
    return NULL;
}