/*
 *  Functions with array parameter(s)
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
 *   Samples:
 *  - arr_func.c
 */
#include<stdio.h>
// #include<stdbool.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>

typedef int bool;
#define true 1
#define false 0

// Test macros
#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")
#define CHECK_IF_ARR_EQUALS(v1, v2) printf( memcmp(v1, v2, sizeof(v1)) == 0 ? "ok\n" : "not ok\n")

// -------- Declarations ---------------

// How many values (to_count) are there in arr?
int count(const int arr[], int size, int to_count);

// Return first index of to_find in arr if not found return -1
int find_first(const int arr[], int size, int to_find);

// Set fraction of array to 1, others to 0
void distribute(int arr[], int size, double fraction);

// Randomly reorder elements (a permutation)
void shuffle(int arr[], int size);

// Helper method
void print_arr(const int arr[], int size);


int main(void) {
    int arr[] = {4, 1, 5, 3, 6, 3, 1, 9};

    // Standard way of getting size of array
    // NOTE: Will not work if send arr as parameter to functions
    // because C will convert array to address to first elem!
    int size = sizeof(arr) / sizeof(arr[0]);

    CHECK_IF_EQUALS(count(arr, size, 6), 1);     // There's one 6
    CHECK_IF_EQUALS(count(arr, size, 3), 2);

    CHECK_IF_EQUALS(find_first(arr, size, 4), 0);      // 4 is at index 0
    CHECK_IF_EQUALS(find_first(arr, size, 5), 2);
    CHECK_IF_EQUALS(find_first(arr, size, 99), -1);

    int a2[10];
    int size_a2 = sizeof(a2) / sizeof(a2[0]);  // Standard idiom (not really necessary)
    distribute(a2, size_a2 , 0.2);
    int expected1[] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}; // The expected answer, 20% one's
    CHECK_IF_ARR_EQUALS(a2, expected1);       // Are a2 and expected1 the same? If so print ok.

    distribute(a2, size_a2, 0.5);
    int expected2[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  // 50% one's
    CHECK_IF_ARR_EQUALS(a2, expected2);

    distribute(a2, size_a2, 0.75);   // Rounded
    int expected3[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
    print_arr(a2, size_a2);
    CHECK_IF_ARR_EQUALS(a2, expected3);


    printf("Original array: \n");
    print_arr(arr, size);
    printf("Shuffled array: \n");
    shuffle(arr, size);            // Reorder randomly (permutation)
    print_arr(arr, size);          // Use ocular inspection of output
    shuffle(arr, size);
    print_arr(arr, size);
    shuffle(arr, size);
    print_arr(arr, size);

    return 0;
}

// ------ Implementations -----------------

int count(const int arr[], int size, int to_count) {
    
    int count = 0;
    
    for(int i = 0; i < size; i++) {
        if( arr[i] == to_count) count++;
    }
    
    return count;
}

int find_first(const int arr[], int size, int to_find) {
    
    for( int i = 0; i < size; i++) {
        if(arr[i] == to_find) {
            return i;
        }
    }
    return -1;
}

void distribute(int arr[], int size, double fraction) {
   
    int num_of_frac = ceil(fraction * size);
    
    for(int i = 0; i < size; i++) {
        
        if(num_of_frac > 0) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
        num_of_frac--;
    }
}

/*  Fisher- Yates algorithm
    https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 */
void shuffle(int arr[], int size) {
    
    //srand(time(NULL));
    
    for(int i = 0; i < size; i++) {
        int index = rand() % size;
       
        int a = arr[index];
        arr[index] = arr[i];
        arr[i] = a;
    }
}

// ----------- Helper method -----------------

void print_arr(const int arr[], int size){
    printf("[");
    for( int i = 0 ; i < size-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size-1]);
}

