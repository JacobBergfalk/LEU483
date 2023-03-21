/*
 *      Sorting and finding the median
 *
 *      See: https://en.wikipedia.org/wiki/Bubble_sort and
 *           https://en.wikipedia.org/wiki/Insertion_sort
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

bool is_sorted(const int *arr, int size);

void bubble_sort(int *arr, int size);

void insertion_sort(int *arr, int size);

double median(const int *arr, int size);

void print_arr(const int *arr, int size);


int main(void) {
    int arr[] = {4, 5, 7, 6, 2, 8, 9, 4, 5, 3, 4, 1, 2, 3, 9, 8};
    CHECK_IF_EQUALS(is_sorted(arr, SIZE(arr)), false);

    bubble_sort(arr, SIZE(arr));
    print_arr(arr, SIZE(arr));
    CHECK_IF_EQUALS(is_sorted(arr, SIZE(arr)), true);
    

    int arr2[] = {1, 3, 6, 5, 7, 2, 9, 7, 8, 4, 4, 5, 3, 6, 6};
    CHECK_IF_EQUALS(is_sorted(arr2, SIZE(arr2)), false);
    insertion_sort(arr2, SIZE(arr2));
    CHECK_IF_EQUALS(is_sorted(arr2, SIZE(arr2)), true);
    print_arr(arr2, SIZE(arr2));

    // Both arrays sorted!
    printf("Size of arr is %ld median is %f\n", SIZE(arr), median(arr, SIZE(arr)));
    printf("Size of arr2 is %ld median is %f\n", SIZE(arr2), median(arr2, SIZE(arr2)));

    return 0;
}

bool is_sorted(const int *arr, int size) {
    
    for(int i = 1; i < size; i++) {
        if(arr[i - 1] > arr[i]) {
            return false;
        }
    }

    return true;
}


// Assumes sorted array
double median(const int *arr, int size) {

    if(size % 2 == 0) {
        return (arr[size / 2] + arr[size / 2 + 1]) / 2;
    } else {
        return arr[size / 2];
    }

}

void bubble_sort(int *arr, int size) {
    
    int temp;

    for(int i = 0; i < size -1; i++) {

        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    

}

void insertion_sort(int *arr, int size) {
    
    int temp; 
    for(int i = 1; i < size; i++) {
        int j = i;
        
        while( j > 0 && arr[j - 1] > arr[j]) {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}


// ----------- Helper method -----------------

void print_arr(const int *arr, int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}