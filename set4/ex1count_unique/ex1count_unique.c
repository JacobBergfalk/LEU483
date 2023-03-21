/*
 *   How many unique elements in sorted array?
 *
 * See
 * - ptr_arr.c
 * - ptr_arr_func.c
 */
#include<stdio.h>
//#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>

typedef int bool;
#define true 1
#define false 0

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// Test macros
#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")

// Count unique elements in array
// REMEMBER: arr[] is same as *arr
int count_uniques(const int *arr, int size);

int main(void) {
    int arr1[] = {1, 1, 2, 2, 2, 2, 3, 4, 4, 4, 4, 4, 4, 4};
    CHECK_IF_EQUALS(count_uniques(arr1, SIZE(arr1)), 4);

    int arr2[] = {1, 1, 1, 1, 1};
    CHECK_IF_EQUALS(count_uniques(arr2, SIZE(arr2)), 1);


    int arr3[] = {1, 2, 3, 4, 5, 6};
    CHECK_IF_EQUALS(count_uniques(arr3, SIZE(arr3)), 6);
    
    return 0;
}


int count_uniques(const int *arr, int size) {
    
    int last_num = arr[0];
    int count = 1;
    
    for(int i = 0; i < size; i++) {
        
        if(last_num != arr[i]) {
            last_num = arr[i];
            count++;
        }
    }
    
    return count;
}
