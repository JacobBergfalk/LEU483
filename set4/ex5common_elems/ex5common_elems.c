/*
 *   Get common elements for all rows in matrix
 *   with positive integer elements
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>

#define ROWS 4
#define COLS 4

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// Test macros
#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")
#define CHECK_IF_ARR_EQUALS(v1, v2) printf( memcmp(v1, v2, sizeof(v1)) == 0 ? "ok\n" : "not ok\n")

// TODO Declarations of helper methods

void get_common_row_elems(int n_rows, int n_cols, const int matrix[n_rows][n_cols], int *common);

bool includes_in_rows(int num, int row, int n_cols, int n_rows, const int matrix[n_rows][n_cols]);

void padd_with_zeros(int *common, int size, int pos);

void print_arr(const int arr[], int size);


int main(void) {

    int m1[ROWS][COLS] = {
            {7, 1, 3, 6},
            {6, 2, 7, 1},
            {8, 9, 1, 3},
            {5, 6, 9, 1},
    };
    int m2[ROWS][COLS] = {
            {7, 1, 3, 9},
            {6, 9, 7, 1},
            {7, 9, 1, 3},
            {5, 7, 9, 1},
    };

    // TODO Add tests for helper methods


    int expected[] = {1, 0, 0, 0};  // Padded with 0's
    int result[COLS];
    get_common_row_elems(ROWS, COLS, m1, result);
    CHECK_IF_ARR_EQUALS(result, expected);
    //print_arr(result, 4);


    int expected2[] = {7, 1, 9, 0};  // Padded with 0's
    int result2[COLS];
    get_common_row_elems(ROWS, COLS, m2, result2);
    CHECK_IF_ARR_EQUALS(result2, expected2);
    //print_arr(result2, 4);

    return 0;
}


// Get all elements present on all rows
void get_common_row_elems(int n_rows, int n_cols, const int matrix[n_rows][n_cols], int *common) {

    //jämför elementen i första raden. 

    //först nr 7 i rad 0, i rad 1 finns match, i rad 2 ej match break;
    // sedan nr 1 i rad 0, i rad 1, 2, 3,  finns match. sparar i array.

    // huvudfunktion: if match in all, save value. 
    // flytande element 
    int pos = 0;
    for(int c = 0; c < n_cols; c++) {
        bool includes = true;
        int num = num = matrix[0][c];
        for(int r = 0; r < n_rows; r++) {

            if(!includes_in_rows(matrix[0][c], r, n_cols, n_rows, matrix )) {
                includes = false;
            }
        }

        if (includes) {
            common[pos] = num;
            pos++;
        }
    }

    padd_with_zeros(common, n_cols, pos);

}


bool includes_in_rows(int num, int row, int n_cols, int n_rows, const int matrix[n_rows][n_cols]) {

    bool includes = false;

    for(int c = 0; c < n_cols; c++) {

        if(num == matrix[row][c]) {
            includes = true;
        }
    }

    return includes;
}

void padd_with_zeros(int *common, int size, int pos){

    for(int i = pos; i < size; i++) {
        common[i] = 0;
    }
}



// ----------- Helper method -----------------

void print_arr(const int arr[], int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}