/*
 *   An array (vectors) is a consecutive row of variables of the same type
 *   (i.e. no space in between variables, all are adjacent in memory)
 */

#include<stdio.h>

#define SIZE 5      // Number of variables (size of array)


int main(void) {
    // Declare and initialize array of 5 int variables (elements).
    // Initialize with values 10, 3, 12, ....
    int arr[SIZE] = {10, 3, 12, 7, 14};    // Indices: 0...4

    printf("%d\n", arr[0]);       // Indexing using []-operator (indexing operator)
    printf("%d\n", arr[SIZE-1]);  // Last index is one less than size!

    // ---------- Changing element values ------------------

    arr[3] = 77;              // Change variable at index 3
    arr[3]++;
    arr[3]--;

    arr[4] = arr[3];      // Copy from index 3 to 4

    int n = 2;
    arr[n] = arr[n + 1];    // Copy from one step right

    int tmp;
    tmp = arr[SIZE-1];        // Swapping first and last values (need extra variable)
    arr[SIZE-1] = arr[0];
    arr[0] = tmp;

    // ----------- Assign and compare ----------------------
    
    int arr2[SIZE];
    //arr2 = arr;   // NO! Can't assign full array at once
    
    for( int i = 0 ; i < SIZE; i++){   // Copy like this, element by element
        arr2[i] = arr[i];
    }
    
    if( arr == arr2 ){       // NO! Can't compare full array at once. Warning
        // BAD! Always false (use a loop like above to compare element by element)
    }
    
    // ---------- IO -------------

    // Print array
    for (int i = 0; i < SIZE; i++) {    // NOTE: i < SIZE strictly less!!
        printf("%d, ", arr[i]);
    }
    printf("\n");

    int arr3[SIZE];   // Other array (elements undefined)

    printf("Input an integer > ");   // Read into a single variable
    scanf("%d", &arr3[0]);            // NOTE: Must use &
    printf("Value was %d\n", arr3[0]);

    printf("Input 5 integers (space between) > ");
    for (int i = 0; i < SIZE; i++) {    // Read into all variables
        scanf("%d", &arr3[i]);
    }

    for (int i = 0; i < SIZE; i++) {    // Print again
        printf("%d, ", arr3[i]);
    }
    printf("\n");

    // ---- Const arrays -------

    // Can't change variables of const array
    const int c_arr[SIZE];
    //c_arr[0] = 4;  // Assignment not allowed, const!
    // c_arr[3] = 88;

    return 0;
}